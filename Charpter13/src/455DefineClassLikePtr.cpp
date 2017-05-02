/*
 * 455DefineClassLikePtr.cpp
 *
 *  Created on: 2016年9月12日
 *      Author: songx
 */

#include <cstddef>
#include <memory>
#include <string>

using namespace std;

//定义行为像指针的类
//析构函数不能单方面地释放关联的string。只有当最后一个指向string的HasPtr销毁时，它才可以释放string、
//令一个类展现类似指针的行为的最好方法就是使用shared_ptr来管理类中的资源。
//拷贝或赋值一个shared_ptr会拷贝或赋值shared_ptr所指向的指针。
//shared_ptr类自己记录有多少用户共享它所指向的对象。当没有用户指向对象时，shared_ptr类负责释放资源。

//我们也可以手动来实现，使用引用计数来使普通指针类似于智能指针

//引用计数的工作方式：
//1.构造函数（除了拷贝构造函数）需要创建一个引用计数。默认为1
//2.拷贝构造函数不分配新的计数器，而是拷贝给定对象的数据成员，包括计数器。拷贝构造函数递增共享的计数器
//3.析构函数递减计数器，指出共享状态的用户少了一个。如果计数器变为0，则析构函数释放状态
//4.拷贝赋值运算符递增右侧运算对象的计数器，递减左侧运算对象的计数器。如果左侧运算对象的计数器为0，那么销毁。

//引用计数需要被所有的对象共享，为了保持状态一致，使用动态内存来保存。
class HasPtr2{
public:
	HasPtr2(const string & s = string()):ps(new string(s)),i(0),count(new size_t(1)){}
	HasPtr2(const HasPtr2 & orig):ps(new string(*orig.ps)),i(orig.i),count(orig.count){
		--*count;
	}
	HasPtr2& operator=(const HasPtr2 & hp){
		//需要处理自赋值的问题：先递增右侧运算对象的计数器，再递减左侧
		++*hp.count;
		--*count;
		if(*count == 0){
			if(ps){
				delete ps;
				ps = nullptr;
			}
			delete count;
			count = nullptr;
		}
		ps = hp.ps;
		i = hp.i;
		count = hp.count;
		return *this;
	}
	~HasPtr2(){
		--*count;
		if(*count == 0){
			if(ps){
				delete ps;
				ps = nullptr;
			}
			delete count;
			count = nullptr;
		}
	}
private:
	string * ps;
	int i;
	size_t *count;//计数器
};

//使用智能指针来代替手动计数
class HasPtrWithSP {
public:
	HasPtrWithSP(const string & s = string()):ps(make_shared<string>(s)),i(0){}
	HasPtrWithSP(const HasPtrWithSP & orig):ps(orig.ps),i(orig.i){}
	HasPtrWithSP& operator=(const HasPtrWithSP & hp){
		ps = hp.ps;
		i = hp.i;
		return *this;
	}
	~HasPtrWithSP(){}
private:
	shared_ptr<string> ps;
	int i;
};


