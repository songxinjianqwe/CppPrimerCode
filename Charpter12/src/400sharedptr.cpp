/*
 * 400sharedptr.cpp
 *
 *  Created on: 2016年9月8日
 *      Author: songx
 */

#include <initializer_list>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;
//我们的程序使用过静态内存，用于保存局部静态变量、类静态成员变量和全局变量
//使用过栈内存，保存定义在函数中的非静态变量，
//分配在静态内存和栈内存中的对象由编译器自动给创建和销毁。栈对象仅在其定义的程序块运行时才存在；静态成员在使用之前分配，在程序结束后销毁。
//每个程序还拥有一个内存池， 称为堆，用来存储动态分配的对象。
//c++中动态内存管理是通过new和delete运算符来完成的。
//为了更安全地使用动态内存，出现了两种智能指针类型来管理动态对象。
//智能指针的行为类似于常规指针，重要的区别是负责自动释放所指向的对象。
//这两种智能指针的区别在于管理底层指针的方式，shared_ptr允许多个指针指向同一个对象，unique_ptr独占所指向的对象
//weak_ptr是一个伴随类，是一种弱引用，指向shared_ptr所管理的对象。它们都定义在memory头文件中。
//智能指针也是模板，需要给出指针指向的类型
//默认初始化的智能指针中保存着一个空指针
//智能指针的使用方式和普通指针类似，解引用一个智能指针返回它指向的对象

//shared_ptr和unique_ptr都支持的操作：
//shared_ptr<T> sp  unique_ptr<T> up
//p *p  p->mem  
//p.get() 返回p中保存的指针，如果智能指针释放了其对象，返回的指针所指向的对象也就消失了。
//swap(p,q) p.swap(q)

//shared_ptr独有的操作：
//make_shared(args) 返回一个shared_ptr，指向一个动态分配的类型为T的成员，使用args初始化此对象，类似于new+emplace
//shared_ptr p(q) p是q的拷贝，会递增q的引用计数器
//p = q p指向q指向的对象，使得q的引用计数器+1，p的引用计数器-1。当p的引用计数为0时，将其管理的原内存释放
//p.use_count() 返回与p共享对象的智能指针数量，速度较慢
//p.unique()如果p的use_count 为1，返回true；否则返回false

//每个shared_ptr都持有一个引用计数器。无论何时我们拷贝一个shared_ptr，计数器都会递增。
//当我们给shared_ptr赋予一个新值或者shared_ptr被销毁（离开作用域），计数器都会递减
//当指向一个对象的最后一个shared_ptr呗销毁时，shared_ptr类会自耦东销毁此对象。
//它是通过析构函数完成销毁工作的。每个类都有一个析构函数，控制此类型的对象销毁时做什么操作。
//析构函数一般用来释放对象所分配的资源。
//对于一块内存，shared_ptr类保证只要有任何shared_ptr对象引用它，它就不会被释放掉。
//如果将shared_ptr存放于一个容器中，而后不再需要全部元素，而只是用其中一部分，要记得用erase删除不再需要的那些元素。

//程序使用动态内存处于三个原因：
//1.程序不知道自己需要使用多少内存
//2.程序不知道自己所需对象的实际类型
//3.程序在多个对象间共享数据

//定义一个StBlob类，持有一个智能指针，指向一个string的vector

void test1() {
	shared_ptr<int> p = make_shared<int>(42);
	shared_ptr<string> q = make_shared<string>("Interesting");
	auto ptr = make_shared<double>(3.14);
	auto ptr2(ptr);
//	p = q;
}


class StrBlob {
public:
	using sizeType = vector<string>::size_type;
	StrBlob() = default;
	StrBlob(initializer_list<string> list) :
			data(make_shared<vector<string>>(list)) {
	}
	sizeType size() const {
		return data->size();
	}
	bool empty() const {
		return data->empty();
	}
	void push_back(string str) {
		data->push_back(str);
	}
	void pop_back() {
		check(0, "Pop_bakc on empty StrBlob");
		data->pop_back();
	}
	string & front() {
		check(0, "Front on empty StrBlob");
		return data->front();
	}
	string & back() {
		check(0, "Back on empty StrBlob");
		return data->back();
	}
	//const 重载版本
	const string & front()const {
		check(0, "Front on empty StrBlob");
		return data->front();
	}
	const string & back() const{
		check(0, "Back on empty StrBlob");
		return data->back();
	}
	//并不推荐加一个重载的版本
	//因为const的对象本不应该能够修改其值，因此没有必要去添加const版本的函数
	//而且即使const对象调用了非const的函数，编译器会报错，也无法调用修改。
private:
	shared_ptr<vector<string>> data;
	void check(sizeType i, const string & msg) const {
		if (data->size() <= i) {
			throw out_of_range(msg);
		}
	}
};
//initializer_list可以替代一个StrBlob对象，如果不加explicit的话


