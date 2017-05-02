/*
 * 415shared_ptrAndException.cpp
 *
 *  Created on: 2016年9月10日
 *      Author: songx
 */

#include <memory>

using namespace std;

//智能指针与异常
//智能指针能够保证资源被释放
//如果使用智能指针，即使程序块过早结束，智能指针类也能确保在内存不再需要的时候将其释放
//对于普通指针而言，如果在new和delete之间发生异常，且异常没有被捕获，那么内存就永远无法被释放了。

//对于良好定义的类，应该提供析构函数，当智能指针被销毁时，会自动调用析构函数
//如果这个类没有定义析构函数，我们可以自己提供一个删除器

struct destination;
struct connection;

connection connect(destination *);
void disconnect(connection);
void f(destination &d ){
	connection c = connect(&d);
	//use connection
	//如果忘了调用disconnect，就无法关闭c了。
}
void endConnection(connection *p){
	disconnect(*p);
}
void g(destination &d){
	connection c = connect(&d);
	shared_ptr<connection> p (&c,endConnection);
	//函数结束时，会自动调用endConnection函数
}
void h(destination &d){
	connection c = connect(&d);
	shared_ptr<connection> p (&c,[](connection *p){disconnect(*p);});
	//函数结束时，会自动调用endConnection函数
}

//智能指针的使用规范：
//1.不使用相同的内置指针初始化或reset多个智能指针
//2.不delete get（）返回的指针
//3.不使用get（）初始化或reset另一个智能指针
//4.如果使用get（）返回的指针，那么当最后一个对应的智能指针销毁后，该指针就无效了
//5.如果使用智能指针不是new分配的动态内存，那么需要传递一个删除器


