/*
 * 490overloadoperator.cpp
 *
 *  Created on: 2016年9月14日
 *      Author: songx
 */
#include <iostream>
using namespace std;

//运算符重载

//重载的运算符时具有特殊名字的函数：它们的名字由关键字operator和气候要定义的运算符共同组成。重载的运算符也包含返回类型、阐述列表、函数体。
//重载运算符函数的参数数量与该运算符作用的运算对象数量一样多。
//除了重载的函数调用运算符operator()，其他冲澡运算符不能包含默认实参
//如果一个运算符函数是成员函数，则它的左侧第一个运算对象绑定到隐式的this指针上。因此，成员运算符函数的参数数量比运算符的运算对象总数少一个。
//对于运算符函数来说，它或者是类的成员函数，或者至少含有一个类类型的参数。不能重载内置类型的运算符
//对于一个重载的运算符来说，其优先级和结合性与对应的内置运算符保持一致。
//可以被重载的运算符 ： +-*/%&^ () 等等
//我们也可以像调用普通函数一样直接调用运算符函数，现制定函数名字，然后传入数量正确、类型适当的实参。
//data1 + data2
//operator+(data1,data2);

//我们像调用其他成员函数一样显式地调用成员运算符函数。具体做法是：首先指定运行函数的对象的名字，然后使用点运算符或箭头运算符访问希望调用的函数
//data1 += data2;
//data1.operator+(data2);

//某些运算符不应该被重载：&& || , &
//&& || , 这些运算符的重载无法应用这些运算符本身求值顺序，比如无法实现短路，只能都求。
//不重载,和& 是已经定义了这两种运算符用于类类型对象时的特殊含义，所以一般不应该被重载。

//重载运算符的一个原则是使用与内置类型一致的含义。
//如果类执行IO操作，可以定义>> <<与内置类型的IO一致
//检查相等性 一般是重载==，如果有了==，通常也应该有！=
//如果包含比较操作，则定义<；如果有了<，通常也应该定义其他关系操作
//重载运算符的返回类型通常情况下应该与其内置版本的返回类型兼容：逻辑运算符和关系运算符应该返回bool；算术运算符应该返回一个类类型的对象；
//赋值运算符和复合赋值运算符应该返回左侧运算对象的一个引用

//赋值运算符：赋值之后，左侧运算对象和右侧运算对象的值相等，并且运算符应该返回它左侧运算对象的一个引用
//如果累含有算术运算符或者位运算符，那么最好也提供对应的复合赋值运算符。

//当我们定义重载运算符时，首先必须决定是将其声明为类的成员函数还是声明一个普通的非成员函数。
//= [] () ->必须是成员
//复合赋值运算符一般也是成员，但并非必须
//改变对象状态的运算符或者与给定类型密切相关的运算符通常是成员：++ -- *解引用  
//具有对称性的一般是非成员函数：算术、相等性、关系、位运算符





