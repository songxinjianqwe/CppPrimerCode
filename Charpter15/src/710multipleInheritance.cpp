/*
 * 710multipleInheritance.cpp
 *
 *  Created on: 2016年10月3日
 *      Author: songx
 */

#include <iostream>
using namespace std;
//多重继承与虚继承
//多重继承是指从多个直接基类中产生派生类的能力。多重继承的派生类继承了所有父类的属性。
//抽象类ZooAnimal 
//类Bear
//类Endangerd

//我们的示例类是Panda

//多重继承的派生列表中可以包含多个基类
class ZooAnimal {
public:
	ZooAnimal(const string & s, bool onExhibit) :
			name(s), onExhibit(onExhibit) {
	}
private:
	string name;
	bool onExhibit;
};
class Bear: public ZooAnimal {
public:
	Bear(const string & s, bool onExhibit, const string & bearname) :
			ZooAnimal(s, onExhibit), bearName(bearname) {
	}
private:
	string bearName;
};
class Endangered {
public:
	int critical = 3;
	int normal = 1;
	Endangered(int degree) :
			degree(degree) {
	}
private:
	int degree;
};
class Panda: public Bear, public Endangered {
	Panda(const string &name, bool onExhibit);

};

//派生类的对象中包含有每个基类的子对象
//够早啊一个派生类的对象将同时构造并初始化它的所有基类子对象
Panda::Panda(const string &name, bool onExhibit) :
		Bear(name, onExhibit, "Panda"), Endangered(Endangered::critical) {
}
//基类的构造顺序与派生列表中基类的出现顺序一致，而与派生类构造函数初始值列表中基类的顺序无关
//一个Panda的初始化顺序：
//ZooAnimal 是最终基类
//Panda 的第一个直接基类Bear
//Panda 的第二个直接基类Endanger
//Panda自己

//允许派生类从它的一个或几个基类中继承构造函数
//但是如果从多个基类中继承了相同的构造函数（形参列表相同），则程序产生错误
class Base1{
public:
	Base1() = default;
	Base1(const string &);
	Base1(shared_ptr<int>);
};
class Base2{
public:
	Base2() = default;
	Base2(const string &);
	Base2(int);
};
class Derived1:public Base1,public Base2{
	using Base1::Base1;
	using Base2::Base2;
};
//如果一个类从它的多个基类继承了相同的构造函数，则这个类必须为该构造函数定义它自己的版本
class Derived2:public Base1,public Base2{
	using Base1::Base1;
	using Base2::Base2;
	Derived2() = default;
	Derived2(const string & s):Base1(s),Base2(s){}
};

//多重继承的派生类的拷贝和移动操作
//多重继承的派生类如果定义了自己的拷贝或赋值构造函数和赋值运算符，则必须在完整的对象上执行拷贝、移动、赋值操作
//只有当派生类使用的是合成版本的拷贝、移动或赋值成员时，才会自动对其基类部分执行这些操作
//在合成的拷贝控制成员中，每个基类分别使用自己的对应成员隐式地完成构造、赋值、销毁等工作
Panda yingying("yingying");
Panda lingling = yingying;
//将调用Bear的拷贝构造函数，后者在执行自己的拷贝任务之前先调用ZooAnimal的拷贝构造函数。
//一旦yingying的Bear部分构造完，接着就会调用Endangered的拷贝构造函数来创建对象响应的部分。最后调用Panda的拷贝构造函数

//类型抓换与多个基类
//编译器不会再派生类向基类的几种转换中进行比较和选择，因为转换到任意一种基类都一样好。
//与单继承一致，对象、指针和引用的静态类型决定了我们能够调用哪些成员。

//多重继承下的类作用域
//在多重继承的情况下，相同的查找过程在所有直接基类中同时进行。如果名字在多个基类中都被找到，则对该名字的使用具有二义性
//对一个派生类来说，从它的几个基类分别继承名字相同的成员是完全合法的，只不过在使用这个名字时必须明确指出它的版本。
//如果名字相同又没有指明是哪个类，将报告二义性错误，最好的办法是在派生类中为该函数定义一个新版本。

//*********************************************************************************8
//虚继承
//派生类可以多次继承同一个类
//派生类可以通过它的两个直接基类分别继承同一个间接基类，也可以直接继承某个基类，然后通过另一个基类再一次间接继承该类。
//如果某个类在派生过程中出现了多次，则派生类将包含该类的多个子对象。
//在C++中我们通过虚继承的机制解决上述问题。虚继承的目的是令某个类做出声明，承诺愿意共享它的基类。
//其中，共享的基类子对象称为虚基类。
//不论虚基类在继承体系中出现了多少次，在派生类中都只包含唯一一个共享的虚基类子对象。
//Panda可能属于Raccoon科或Bear科，可以Panda类同时继承这两个类。为了避免赋予Panda两份ZooAnimal
//我们将Bear和Raccoon继承ZooAnimal方式定义为虚继承
//必须在虚继承的真实需求出现前就已经完成虚继承的操作。

//虚继承只影响从虚基类的派生类中进一步派生出的类，它不会影响派生类本身。
//定义虚基类的方式是在派生列表中添加virtual关键字
class Raccoon:public virtual ZooAnimal{};
class Bear:virtual public ZooAnimal{};

//virtual说明符表明了一种愿望，即在后续的派生列当中共享虚基类的同一份实例，至于什么样的类能作为虚基类没有特殊规定
class Panda:public Bear,public Racoon,public Endangered{
	
};
//************************************************************************************
//构造函数与虚继承
//在虚继承中，虚基类是由最底层的派生类初始化的。如当创建Panda对象时，由Panda的构造函数独立控制ZooAnimal的初始化过程
//如果以普通规则执行初始化任务，虚基类会在多条继承路径上被重复初始化
//含有虚基类的对象的构造顺序与一般的顺序有区别：首先使用提供给最底层派生类的构造函数的初始值初始化该对象的虚基类字部分，
//接下来按照直接基类在派生列表中出现的次序一次对其进行初始化。
//如果Panda没有显式地初始化ZooAnimal基类，则ZooAnimal的默认构造韩寒苏将被调用。
//如果ZooAnimal没有默认构造函数，则代码将发生错误。


//构造函数和析构函数的次序
//一个类可以有多喝虚基类。此时，这些虚的子对象按照它们在派生列表中出现的顺序从左到右依次构造。

//编译器按照直接基类的声明顺序对其依次进行检查，以确定其中是否含有虚基类。
//如果有，则先构造虚基类，然后按照声明的顺序逐一构造其他非虚基类。
//合成的拷贝和移动构造函数按照完全相同的顺序执行，合成的赋值运算符中的成员也按照该顺序赋值。
//对象的销毁顺序与构造韩寒苏正好相反












