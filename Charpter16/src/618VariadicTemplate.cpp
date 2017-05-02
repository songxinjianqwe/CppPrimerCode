/*
 * 618VariadicTemplate.cpp
 *
 *  Created on: 2016年9月30日
 *      Author: songx
 */

#include <iostream>
#include <string>

#include "../header/StrVec.h"

using namespace std;

//一个可变参数模板时一个接受可变数目参数的模板函数或模板类。
//可变数目的参数被称为参数包。
//模板参数包表示0~多个模板参数；函数参数包表示0~多个函数参数
//用一个省略号表示一个包
//class/typename ...指出接下来的参数表示零个或多个类型的列表
//一个类型名后面跟一个省略号表示零个或多个给定类型的非类型参数的列表
//在函数参数列表中，如果一个参数的类型是一个模板参数包，那么此参数是一个函数参数包
template<typename T,typename...Args>
void foo(const T & t, const Args & ... rest){
	
}
//对于一个可变参数模板，编译器除了推断参数类型之外，还会推断参数数量。
void test51(){
	int i = 0;
	double d = 23;
	string s = "hw";
	foo(s,42,i,d);
}
//foo被实例化为
//void foo(const char[3]&,const int &,const int &,const double &)

//sizeof...运算符
//当我们需要知道包中有多少个元素时，可以使用sizeof...运算符。sizeof...也返回一个常量表达式，而且不会对其实参求值
template<typename ...Args>
void g(Args... args){
	cout<<sizeof...(Args)<<endl;
	cout<<sizeof...(args)<<endl;
}

//如果使用一个initializer_list来定义一个可变参数的函数，其参数类型必须是相同的
//当我们既不想要想要处理的实参的数目也不知道它们的类型时，可变参数函数是很有用的。
//可变参数函数通常是递归的。
//第一步调用是处理包中的第一个实参，然后用剩余实参调用自身。
//为了终止递归，我们还需要定义一个非可变参数的函数，接受一个流和一个对象

//用于结束递归的函数
//此函数必须在可变参数版本的print定义之前声明
template<typename T>
ostream & print(ostream & os,const T & t){
	return os<<t;
}
template<typename T,typename ... Args>
ostream & print(ostream &os,const T & t,const Args&...rest){
	os<<t<<"\t";
	return print(os,rest...);//递归调用，打印其他实参;当rest只剩一个的时候会调用上面那么print函数
}
//return(os,rest...);
//其结果是rest中的第一个实参被绑定到t上，剩余实参形成下一个print调用的参数包。
//在每个调用中，包中的第一个实参被移除，成为绑定到t的实参。

//print(cout,i,s,42)
//递归执行如下：
//                     t     rest...
//print(cout,i,s,42)   i      s,42
//print(cout,s,42)     s      42
//print(cout,42)       //非可变参数版本的print
//对于最后一次调用递归调用print(cout,42)，两个print版本都是可行的。但是非可变参数模板比可变参数模板更加特例化，因此编译器选择非可变参数版本
//当定义可变参数版本的print时，非可变参数版本的声明必须在作用域中。

void test60(){
	print(cout,23,"sdjai",23.23923,'d',2e21);
}

//*******************************************************************************************************

//包扩展
//对于一个参数包，除了获取其大小之外，我们能对它做的唯一的事情就是扩展
//当扩展一个包时，我们还要提供用于每个扩展元素的模式。
//扩展一个包就是将它分解为构成的元素，对每个元素应用模式，获得扩展后的列表。
//我们通过在模式右边放一个省略号来触发扩展操作

//第一个扩展操作 扩展模板参数包，为print生成函数参数列表。
//第二个扩展操作出现在对print的调用中。此 模式为print调用生成实参列表。
//在此情况下，模式是函数参数包的名字rest。此模式扩展出一个由包中元素组成的、逗号分隔的列表。

//C++还允许更复杂的扩展模式
template<typename ...Args>
ostream & errorMsg(ostream & os,const Args&...rest){
	return print(os,debugRep(rest)...);
}
//这个print调用了模式debugRep(rest)。此模式表示我们希望对函数参数包rest中的每个元素都调用debugRep。
//扩展结果将是一个逗号分隔的debugRep的调用列表。
//比如这种调用:errorMsg(cerr,fcnName,code.num(),otherData);
//print(cerr,debugRep(fcnNuame),debugRep(code.num()),debugRep(otherData));


//注意不能写成debugRep(rest...);
//试图用4个实参的列表来调用debugRep
//扩展中的模式会独立地应用于包中的每个元素

//*********************************************************************************************

//转发参数包
//我们可以组合使用可变参数模板和forward机制来编写函数，将其实参不变地传递给其他函数
//以StrVec中的emplace_back成员为例
/*

template <typename ...Args>
void StrVec::emplace_back(Args&&...args){
	check_n_copy();
	alloc.construct(firstFree++,forward<Args>(args)...);
}
*/
//emplace_back函数应该是可变参数的，因为string有多个构造函数，参数各不相同。
//由于我们希望使用string的移动构造函数，因此还需要保持传递给emplace_back的实参的所有类型信息
//保持类型信息是一个两阶段的过程。首先，为了保持实参中的类型信息，必须将emplace_back的函数参数定义为右值引用
//其次，当emplace_back将这些实参传递给construct时，我们必须使用forward来保持实参的原始类型

//此模式生成如下形式元素
//forward<Ti>ti
//其中Ti表示模板参数包中第i个元素的类型，ti表示函数参数包中第i个元素。
void test66(){
	StrVec sVec;
	sVec.emplace_back(10,'c');
	//construct调用中的模式会扩展出forward<int>(10),forward<char>(c)
	for(auto it = sVec.begin();it != sVec.end();it++){
		cout<<*it<<"\t";
	}
	cout<<endl;
}








