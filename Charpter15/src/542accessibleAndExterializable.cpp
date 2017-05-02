/*
 * 542accessibleAndExterializable.cpp
 *
 *  Created on: 2016年9月23日
 *      Author: songx
 */

#include <stddef.h>

using namespace std;
//访问控制与继承
//受保护成员
//一个类使用protected关键字来声明那些希望与派生类分享但是不想被其他公共访问使用的成员。
//protected可以视为public和private中和后的产物
//protected成员对于类的用户是不可访问的
//protected成员对于当前类的派生类和派生类的友元来说是可访问的
//派生类的成员和友元只能通过派生类对象来访问基类的protected成员，派生类对于一个基类对象中的protected成员没有任何访问特权
//派生类的成员和友元只能访问派生类对象中的基类部分的受保护成员；对于普通的基类对象中的成员不具有特殊的访问权限
//也就是说，子类的友元能通过子类访问父类的protected成员，但是不能直接访问父类的protected成员
class Base {
	friend class Pal;
protected:
	int protMem = 2;
};
class Sneaky: public Base {
	friend void clobber(Sneaky &);
	friend void clobber(Base &);
private:
	int j = 0;
};
void clobber(Sneaky & s) {
	s.protMem = 0;
}
void clobber(Base & b) {
//	b.protMem = 0;//error
	//子类友元不能直接访问父类的protected成员
}

//某个类对其继承而来的成员的访问权限受到两个因素影响：一是在基类中该成员的访问说明符；二是在派生类的派生列表中的访问说明符
class Base2 {
public:
	void pubMem();
protected:
	int protMem;
private:
	char privMem;
};
class Pub: public Base2 {
	int f() {
		return protMem;	//ok
	}
	char g() {
//		return privMem;//error
		return 'c';
	}
};
class Priv: private Base2 {
	int f1() {
		return protMem;	//ok
	}
};
//派生访问说明符对于派生类的成员和友元能否访问其直接基类的成员没有影响，对基类的成员的访问权限只与基类中的访问说明符有关
//派生访问说明符的目的是控制派生类的用户（包括使用类的人和派生类的派生类）对于基类陈冠的访问权限
void test8() {
	Pub d1;
	Priv d2;
//	d1.pubMem();//ok
//	d2.pubMem();//error
}
//如果继承是公有的，那么成员将遵循其原有的访问说明符；如果继承是私有的，那么从基类中继承的所有成员对外部（或派生类）而言都是私有的
//如果继承是protected的，那么从基类中继承的所有成员对外部（或派生类）而言都是protected的

class DerivedFromPub: public Pub {
	int useBase() {
		return protMem;
	}
};
class DerivedFromPrivate: public Priv {
	int useBase() {
//		return protMem;//error
		return 0;
	}
};

//派生类向基类转换的可访问性(基类的指针或引用可以指向派生类的对象)：
//派生类向基类的转换是否可访问由使用该转换的代码决定，同时派生类的派生访问说明符也会有影响
//class D:public B
//D公有继承B时，用户代码才能使用派生类向基类的类型转换（protected或private都不行）
//无论什么方式继承，D的成员函数和友元都能使用派生类向基类的转换；派生类向其直接基类的类型转换对于派生类的成员和友元来说是永远可访问的
//如果D继承B的方式是public或者protected，那么D的派生类  的成员和友元(注意不是用户)可以使用D向B的类型转换（private不可）

//一个类有三种用户：普通用户；类的实现者；派生类
//普通用户只能访问类的public成员
//类的实现者负责编写类的成员和友元，可以访问类的所有部分
//派生类及其友元可以访问基类的public和protected成员

//基类应该将其接口成员声明为public
//将属于其实现的部分为两组：一组供派生类访问，声明为protected；另一组只能由基类和基类的友元访问，声明为private

//友元与继承
//友元不能传递，也不能继承
//只要记住：每个类负责控制各自成员的访问权限

//友元关系
class Pal {
public:
	int f(Base b) {
		return b.protMem;
	}
	int f2(Sneaky s) {
		return s.protMem;
	}
	int f3(Sneaky s) {
//		return s.j;//error
		return 0;
	}
};
//一个类将另一个类声明为友元的时候，这种友元关系只对做出声明的类有效；对于原来的那个累来说，其友元的基类或者派生类不具有特殊的访问能力

//改变个别成员的可访问性：
//有事我们需要改变派生类继承的某个名字的访问级别，通过使用using声明来实现
class Base3 {
public:
	size_t size() const {
		return n;
	}
protected:
	size_t n;
};

class Derived :private Base3{
public:
	using Base3::size;
protected:
	using Base3::n;
};
//这里用了私有继承，所以Base3的成员都是private的，using语句改变了这些成员的可访问性。
//改变之后，Derived用户可以使用size成员，而Derived的派生类将可以使用n
//通过在类的内部使用using声明语句，我们可以将该类的直接或间接基类中的任何可访问成员（菲私有成员）标记出来
//using声明语句中名字的访问权限由该using声明语句之前的访问说明符来决定
//如果using声明语句出现在类的private部分，那么该名字只能被类的成员和友元访问
//如果using声明语句出现在类的public部分，那么类的所有用户都能访问它
//如果using声明语句出现在protected部分，那么该名字对于成员、友元和派生类都是可访问的。

//默认的继承保护级别
//冒号之后不加访问修饰符，直接加父类名的话使用的是默认的继承保护级别
//对于派生类是struct的，默认继承保护级别是public的；派生类是class的，默认继承保护级别是private
//但是最好不要使用默认的，而应该直接声明出来。
//!     Base *p = &d1;  //  d1 has type Pub_Derv    --  legal   --right
//!     p = &d2;        //  d2 has type Priv_Derv   --  illegal --right
//!     p = &d3;        //  d3 has type Prot_Derv   --  illegal --right
//!
//!     p = &dd1;       //  dd1 has type Derived_from_Public    --  legal   --right
//!     p = &dd2;       //  dd2 has type Derived_from_Private   --  illegal --right
//!     p = &dd3;       //  dd3 has type Derived_from_Protected --  illegal --right
//!
//      User code may use the derived-to-base conversion only if D inherits
//      publicly from B. User code may not use the conversion if D inherits
//      from B using either protected or private.
//这道题说明了只有public方式继承的，父类指针或引用才能指向子类对象

//  Member functions and friends of D can use the conversion to B regardless
//  of how D inherits from B. The derived-to-base conversion to a direct base
//  class is always accessible to members and friends of a derived class.
//  Hence, the 3 below are all legal:
//
//          Pub_Derv    --  legal   --right
//          Priv_Derv   --  legal   --right
//          Prot_Derv   --  legal   --right
//
//  Member functions and friends of classes derived from D may use the
//  derived-to-base conversion if D inherits from B using either public or
//  protected. Such code may not use the conversion if D inherits privately
//  from B.Hence:
//          Derived_from_Public    --  legal    --right
//          Derived_from_Private   --  illegal  --right
//          Derived_from_Protected --  legal    --right
//这道题说明了两点：子类继承父类，无论什么方式继承，子类的成员函数和友元都能实现父类指针或引用指向子类对象
//子类继承父类，只有public和private方式继承，子类的子类的成员函数和友元才能实现父类指针或引用指向子类对象

void test10(){
	Pub d1;
	Priv d2;
	DerivedFromPub dd1;
	DerivedFromPrivate dd2;
	Base2 * p =  &d1;
//	p = &d2;//error
	p = &dd1;
//	p = &dd2;//error
}

