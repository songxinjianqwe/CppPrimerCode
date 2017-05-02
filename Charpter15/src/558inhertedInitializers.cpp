/*
 * 558inhertedInitializers.cpp
 *
 *  Created on: 2016年9月25日
 *      Author: songx
 */

#include <DiskQuote.h>
using namespace std;
//继承的构造函数
//派生类能够直接重用其直接基类定义的构造函数
//我们将这种“重用”称为“继承”
//一个类只初始化它的直接基类，一个类也只继承其直接基类的构造函数
//类不能继承默认构造函数、拷贝构造函数和移动构造函数
//方法是提供一条注明了直接基类名的using声明语句
//using DiskQuote::DiskQuote;


/*
class BulkQuote:public DiskQuote{
public:
	using DiskQuote::DiskQuote;
	double netPrice(size_t)const;
};
*/
//通常情况下，using语句的作用是令某个名字在当前作用域可见，
//而作用域构造函数时，using声明语句将令编译器产生代码
//对于基类的每个构造函数，编译器都生成一个与之对应的派生类构造函数。（在派生类中生成一个形参列表完全相同的构造函数）
//形如：derived(params):base(args){}
//derived是派生类的名字，base是基类的名字；params是构造函数的形参列表，args将派生类构造函数的形参
//传递给基类的构造函数

//适用于派生类没有自己额外的成员的情况，如果派生类有自己的成员，那它们将被默认初始化

//using DiskQuote::DiskQuote 就相当于
//BulkQuote(const string &book,double price,size_t qty,double disc):DiskQuote(book,price,qty,disc){}

//和普通成员的using声明不一样，一个构造函数的using声明不会改变该构造函数的访问级别
//基类的构造函数是什么访问级别，那么派生类中继承的构造函数也是什么访问级别
//而且一个using声明语句不能指定explict或constexpr
//如果基类的构造函数是explict或constexpr，那么继承的构造函数也拥有相同的属性

//当一个基类构造函数有默认实参时，这些实参并不会被继承。相反，派生类将会获得朵儿继承的构造函数，其中每个构造函数分别省略掉一个含有默认实参的形参
//例如：
//基类有一个构造函数Base(int i,int j = 1)
//则派生类获得两个构造函数：
//Derived(int i,int j)
//Derived(int i)

//如果基类含有几个构造函数，但除了两个例外，大多数时候派生类会继承所有这些构造函数
//一个例外是派生类可以继承一部分构造函数，而为其他构造函数定义自己的版本
//如果派生类定义的构造函数与基类的构造函数具有相同的参数列表，则该构造函数不会被继承
//定义在派生类中的构造函数将替换继承而来的构造函数
//另一个例外是默认、拷贝、移动构造函数不会被继承。


