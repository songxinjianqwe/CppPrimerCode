/*
 * 547classScope.cpp
 *
 *  Created on: 2016年9月23日
 *      Author: songx
 */

#include <iostream>

using namespace std;

//当存在继承关系时，派生类的作用域嵌套在其基类的作用域之内。如果一个名字在派生类的作用域中无法正确解析，则编译器将继续在外层的基类作用域
//中寻找该名字的定义

//恰恰因为类作用域与这种继承嵌套的关系，所以派生类才能像使用自己的成员一样使用基类的成员
//在编译时进行名字查找：
//一个对象、引用、指针的静态类型决定了该对象的哪些成员是可见的。即使静态类型和动态类型不一致，我们能使用那些成员仍然是由静态类型决定的
//指针或引用的类型决定了它所能调用的对外接口
//派生类能重用定义在其直接基类中的名字，此时定义在内层作用域（派生类）的名字价格隐藏定义在外层作用域（基类）中的名字。

//如果函数名一致，参数不同，那么派生类的函数会隐藏基类中的函数
//如果函数名一致，参数也相同，且是虚函数，那么派生类的函数会重写（覆盖）基类中的函数
//如果变量名一致，那么派生类的变量会隐藏基类中的变量

class Base4{
public:
	Base4() = default;
protected:
	int mem = 0;
};


class Derived2 :public Base4{
public:
	Derived2(int i ):mem(i){}
	int getMem(){
//		return mem;//打印42
		return Base4::mem;//打印0
	}
protected:
	int mem = 0;
};

void test20(){
	Derived2 d(42);
	cout<<d.getMem()<<endl;
}
//可以通过作用域运算符来使用一个被隐藏的基类成员
//className::member

//函数调用的解析过程：p->mem()
//首先确定p的静态类型
//在p的静态类型对应的类中查找mem，如果找不到，那么继续在直接基类中查找直至达到继承链的顶端
//一旦找到mem，就进行常规的类型检查
//假设调用合法，则编译器将根据是否是虚函数而产生不同的代码：
//如果mem是虚函数并且是通过指针、引用调用，那么编译器产生的代码将在运行时确定到底运行该虚函数的哪个版本，依据是对象的动态类型
//反之，如果mem不是虚函数或者我们是通过对象进行的调用，则编译器将产生一个常规函数调用。

//名字查找先于类型检查
//如果派生类（内层作用域）中的成员与基类（外层作用域）的某个成员同名，则派生类将在其作用域内隐藏该基类成员
//即使形参列表不一致，基类成员也仍然会被隐藏掉


class Base5{
	int memfcn();
};
class Derived3:public Base5{
	int memfcn(int);
};
void test21(){
	Derived3 d;
	Base5 b;
	b.memfcn();
	d.memfcn(2);
//	d.memfcn();//error 无参数的memfcn已经被隐藏掉了
	d.Base5::memfcn();
}



