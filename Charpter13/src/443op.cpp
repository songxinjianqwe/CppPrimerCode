/*
 * 443op.cpp
 *
 *  Created on: 2016年9月12日
 *      Author: songx
 */

#include <iostream>
using namespace std;

//重载运算符
//重载运算符本质上是函数，其名字由operator关键字后接表示要定义的运算符的符号组成。
//因此，赋值运算符就是一个名为operator=的函数。运算符函数也有一个返回类型和参数列表
//重载运算符的参数表示运算符的运算对象。某些运算符，比如赋值运算符，必须定义为成员函数。如果一个运算符是成员函数，其左侧运算对象就绑定到隐式的this参数。
//对于一个二元运算符，如赋值运算符，其右侧运算对象作为显式参数传递。
//拷贝赋值运算符接受一个与其所在类相同类型的参数
class Foo{
public:
	Foo& operator=(const Foo&);
};
//赋值运算符通常返回一个指向其左侧运算对象的引用。标准库通常要求保存在容器中的类型要具有赋值运算符，且其返回值是左侧运算对象的引用。

//如果一个类没有定义自己的拷贝赋值运算符，编译器会为它生成一个合成拷贝赋值运算符，它会将右侧运算对象的每个非静态成员变量赋予左侧运算对象的对应成员。
//这一工作是通过成员类型的拷贝赋值运算符来完成的。
SalesData & SalesData::operator =(const SalesData & orig){
	bookNo = orig.bookNo;
	unitsSold = orig.unitsSold;
	revenue = orig.revenue;
	return *this;
}




