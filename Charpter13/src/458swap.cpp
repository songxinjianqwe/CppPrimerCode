/*
 * 458swap.cpp
 *
 *  Created on: 2016年9月13日
 *      Author: songx
 */
#include <iostream>
using namespace std;

//swap
//除了定义拷贝控制成员，管理资源的类还定义一个名为swap的函数。
//对于那些重排元素顺序的算法一起使用的类，定义swap是非常重要的。这类算法在需要交换两个元素时会调用swap
//如果对象中持有指针成员，那么我们希望交换时交换指针，而非拷贝之后再交换。

class HasPtr3{
	friend void swap(HasPtr3 & ,HasPtr3 &);
public:
	HasPtr3(const string & s = string()):ps(new string(s)),i(0),count(new size_t(1)){}
	HasPtr3(const HasPtr3 & orig):ps(new string(*orig.ps)),i(orig.i),count(orig.count){
		--*count;
	}
	HasPtr3& operator=(HasPtr3 );
	HasPtr3& operator=(const HasPtr3 & hp){
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
	~HasPtr3(){
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
//为了提高效率，swap函数一般定义为inline
inline void swap(HasPtr3 & left,HasPtr3 &right){
	swap(left.ps,right.ps);
	swap(left.i,right.i);
}
//注意：标准库也定义有通用的swap，但它是采用拷贝值的方式交换的，效率不如自己定义的高。
//如果存在类型特定的swap版本，其匹配程度会由于std中定义的版本。因此，如果存在类型特定的swap版本，swap调用会与之匹配。如果不存在类型特定的版本，则会使用std中的版本。


//在赋值拷贝运算符中使用swap
//赋值并交换

HasPtr3 & HasPtr3::operator =(HasPtr3 rhs){
	swap(*this,rhs);
	return *this;
}
//注意这个函数的参数是拷贝而不是引用，将右侧运算对象拷贝到rhs
//将左侧运算对象中原来保存的指针存入rhs，并将rhs中原来的指针存入*this中。
//因此，在swap调用之后，*this中的指针将指向新分配的string---右侧运算对象中string的一个副本
//当赋值运算符结束时，rhs被销毁，HasPtr的析构函数将执行。delete掉rhs现在指向的内存，即释放掉左侧运算对象中原来的内存。
//自动处理了自赋值情况，并且天然就是异常安全的
//通过改变左侧运算对象之前拷贝右侧运算对象保证了自赋值的正确
//唯一可能抛出异常的是拷贝构造函数中的new表达式
//如果真发生了异常，它也会在我们改变左侧运算对象之前发生。




