/*
 * 417unique_ptr.cpp
 *
 *  Created on: 2016年9月10日
 *      Author: songx
 */

#include <iostream>
#include <memory>

using namespace std;
//unique_ptr
//拥有它所指向的对象
//某个时刻智能有一个unique_ptr指向一个给定对象。当unique_ptr被销毁时，它所指向的对象也被销毁。
//当我们定义一个unique_ptr时，需要将其绑定到一个new返回的指针上。
//初始化unique_ptr必须采用直接初始化的方式
//unique_ptr不支持普通的拷贝或赋值操作
//操作：
//unique_ptr<T> u1
//unique_ptr<T,D> u2
//unique_ptr<T,D> u3(callable) 会使用一个可调用对象来释放指针，如果不提供这个参数 就表示使用delete来释放
//u = nullptr 释放内存，并将u置为空
//u.release() u放弃对指针的控制权，返回指针，并将u置为空（注意！这个指针指向的内存需要程序员手动释放）通常用于初始化另一个智能指针或给另一个智能指针赋值
//u.reset() 释放u指向的对象，如果提供了内置指针q，那么令u指向q，否则将u置为空 
//u.reset(q)
//u.reset(nullptr)

//虽然不允许拷贝，但是允许从函数返回一个unique_ptr，因为编译器知道要返回的对象要被销毁，在此情况下，编译器执行一种特殊的拷贝。
void test12() {
	unique_ptr<double> p(new double);
	unique_ptr<double> p2(p.release()); //p2接管了p指向的内存
	auto p3 = p2.release();
	cout << *p3 << endl;
	delete p3;

	unique_ptr<int> pi(new int);
//	unique_ptr<int> pi2 = pi;//use of deleted function
}
unique_ptr<int> clone(int i) {
	return unique_ptr<int>(new int(i));
}

//向unique_ptr传递删除器

struct destination;
struct connection;

connection connect(destination *);
void disconnect(connection);
void f(destination &d) {
	connection c = connect(&d);
	//use connection
	//如果忘了调用disconnect，就无法关闭c了。
}
void endConnection(connection *p) {
	disconnect(*p);
}

void f(destination &d) {
	connection c = connect(&d);
	unique_ptr<c, decltype(endConnection)*> p(&c, endConnection);

}

