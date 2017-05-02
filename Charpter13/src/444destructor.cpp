/*
 * 444destructor.cpp
 *
 *  Created on: 2016年9月12日
 *      Author: songx
 */

#include <iostream>
#include <memory>
#include <vector>
using namespace std;

//析构函数释放对象使用的资源，并销毁对象的非静态成员变量
//析构函数是类的一个成员函数，名字由~和类名组成。它没有返回值，也不接受参数。
//由于析构函数不接受参数，所以它不能被重载。对一个给定类，只会有一个析构函数。
//在一个析构函数中，首先执行函数体，然后销毁成员，成员按初始化书序的逆序销毁。
//销毁类类型的成员需要执行成员自己的析构函数，内置类型没有析构函数，因此销毁内置类型成员什么也不需要做。
//隐式销毁一个内置指针类型的成员不会delete它所指向的对象（必须在函数体中delete掉）
//与普通指针不同，智能指针成员在析构阶段会被自动销毁(递减引用计数，计数为0，则对象被销毁)

//什么时候会调用析构函数
//变量离开作用域时被销毁
//当一个对象被销毁时，其成员变量被销毁
//容器被销毁时（包括数组），其元素被销毁
//对于动态分配的对象，当对指向它的指针应用delete时被销毁
//对于临时对象，当创建它的完整表达式时被销毁

//合成析构函数
//当一个编译器没有定义自己的析构函数，编译器会为它定义一个合成析构函数
class Foo{
	~Foo();
};


class X{
public:
	//构造函数
	X(){
		cout<<"X()"<<endl;
	}
	//拷贝构造函数
	X(const X & x){
		cout<<"X(const & x)"<<endl;
	}
	//拷贝赋值运算符
	X & operator=(const X & x){
		cout<<"X & X(const X & x)"<<endl;
		return *this;
	}
	//析构函数
	~X(){
		cout<<"~X()"<<endl;
	}
};
void test2(X x){
	cout<<"非引用传递"<<endl;
}
void test3(X & x){
	cout<<"引用传递"<<endl;
}
void test4(){
	X * px = new X();
	shared_ptr<X> spx = make_shared<X>();
	delete px;
	cout<<"动态分配"<<endl;
}
void test5(){
	vector<X> xVec;
	xVec.push_back(X());
	cout<<"容器存储"<<endl;
}

void test6(){
	X x;
	test2(x);
	test3(x);
	test4();
	test5();
	X x2 = x;
	x = x2;
}
/*
	X() 74
	X(const & x) 75/42
	非引用传递 56
	~X()  57
	引用传递   59
	X()   62
	X()   63
	~X()  64
	动态分配  65
	~X()  66
	X()   69 创建临时对象
	X(const & x)  69临时对象拷贝到容器中 
	~X()  69 临时对象被销毁
	容器存储    70
	~X()  71 
	X(const & x) 79
	X & X(const X & x) 80
	~X() 81
	~X() 81
*/  
