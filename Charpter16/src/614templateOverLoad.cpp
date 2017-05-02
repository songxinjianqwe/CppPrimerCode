/*
 * 614templateOverLoad.cpp
 *
 *  Created on: 2016年9月30日
 *      Author: songx
 */

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

//函数模板可以被另一个模板或一个普通非模板函数重载，名字相同的函数必须具有不同数量或类型的参数。
//如果涉及函数模板，则函数匹配规则会在以下几方面受到影响：
//1.对于一个调用，其候选函数包括所有模板实参推断成功的函数模板实例
//2.候选的函数模板总是可行的，因为模板实参推断会排除任何不可行的函数
//3.可行函数（模板与非模板）按类型转换来排序。可以用于函数模板调用的类型转换是非常有限的
//4.如果恰有一个函数比任何其他函数都更好的匹配，则选择此函数。但是，如果有多个函数提供同样好的匹配，则：
//  1)如果同样好的函数中只有一个是非模板函数，则选择此类型
//  2)如果同样好的函数中没有非模板函数，而有多个函数模板，且其中一个模板比其他模板更特例化，则选择此模板
//  3)否则报错

//构造一组函数，返回一个给定对象的string表示
template<typename T>
string debugRep(const T & t){
	ostringstream ret;
	ret << t;
	return ret.str();
}
//定义打印指针版本的debugRep
template<typename T>
string debugRep(T * p){
	ostringstream ret;
	ret <<"pointers:"<<p;
	if(p){
		ret <<"   "<<debugRep(*p);
	}else{
		ret <<" null pointer";
	}
	return ret.str();
}
//注意此函数不能用于打印字符指针，因为IO库为char*定义了一个<<版本，此<<版本假定指针表示一个空字符结尾的字符数组，并打印数组的内容而非地址值
void test50(){
	string s("he");
	//只有第一个版本可行，第二个版本要求一个指针，而这是一个对象
	cout<<debugRep(s)<<endl;
	//如果用一个指针调用，两个函数都生成可行的实例
	cout<<debugRep(&s)<<endl;
}
//debugRep(const string * &)
//debugRep(string *)
//第二个版本是精确匹配



//多个可行模板
//另一个例子
//const string * sp = &s;
//cout<<debugRep(sp)<<endl;

//此例中的两个模板都是可行的，而且两个都是精确匹配
//debutRep(const string * &)
//debugRep(const string *)
//此调用将被解析为debugRep(T*)，即更特例的版本
//设计这条规则的原因是，模板debugRep(const T&)本质上可以用于任何类型，包括指针类型。
//此模板比debug(T*)更加通用，后者只能用于指针类型。

//当有重载模板对一个调用提供同样好的匹配时，应选择最特例化的版本。

string debugRep(const string &s){
	cout<<""""<<s<<"""";
}
//string s("hi")
//cout<<debugRep(s)<<endl;

//编译器会选择非模板版本，当存在多个同样好的函数模板时，编译器选择最特例化的版本，处于相同的原因，一个非模板函数比一个函数模板更好。














