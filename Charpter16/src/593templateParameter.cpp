/*
 * 593templateParameter.cpp
 *
 *  Created on: 2016年9月28日
 *      Author: songx
 */

#include <functional>
#include <iostream>
#include <vector>

using namespace std;

//模板参数
//一个模板参数名的可用范围是在其声明之后，至模板声明或定义结束之前。
//模板参数会隐藏外层作用域中声明的相同名字。
//但是，在模板内不能重用模板参数名
//一个模板参数名在一个特定模板参数列表中只能出现一次

//模板声明
//声明中的模板参数的名字不必与定义中相同
//template<typename T>T calc(const T&,const T&);  声明

//定义
//template<typename type>
//type calc(const type &a,const type &b){....}

//***********************************************************************
//使用类的类型成员
//从属于类的有类型成员和static数据成员
//都可以通过 类名::的方式进行访问

//对于普通的类而言，编译器掌握类的定义，因此，它知道通过作用域运算符访问的名字是类型还是static成员。
//使用string::size_type，编译器有string的定义，从而知道size_type是一个类型
//但对于类模板而言，使用T::mem，编译器不知道mem是一个类型成员还是static数据成员
//为了处理模板，编译器必须知道名字是否表示一个类型
//T是类型参数名
//T::size_type * p
//可能是定义一个名为p的变量，也可能是将一个名为size_type的static数据成员乘以一个p
//如using size_type = vector<T>::size_type;
//这样无法确定是数据还是类型，需要加一个typename以表示这是一个类型
template<typename T> class Test {
	using size_type = typename vector<T>::size_type;
};
//当我们希望通知编译器一个名字表示类型时，必须使用关键字typename

//******************************************************************************
//默认模板实参
//就像为函数参数提供默认参数一样，我们也可能提供默认模板实参
template<typename T,typename F = less<T>>
int compare(const T & lhs,const T & rhs,F f = F()){
	if(f(lhs,rhs)){
		return -1;
	}else if(f(rhs,lhs)){
		return 1;
	}else{
		return 0;
	}
}
//我们为这个模板实参提供了默认实参，并对其对应的函数实参也提供了默认实参。默认模板实参指出compare将使用less镀锡。
//当用户调用compare时，可以提供自己的比较操作，但这不是必须的
void test25(){
	bool i = compare(0,42);
	cout<<i<<endl;
//	SalesData items1(cin),items2(cin);
//	bool j = compare(item1,item2,commpareIsbn);
}

//如果一个类模板为其所有模板参数都提供了默认实参，且我们希望使用这些默认实参，就必须在模板名之后跟一个空<>
template<typename T = int>class Numbers{
public:
	Numbers(T v = 0):val(v){}
private:
	T val;
};
void test27(){
	Numbers<long double> n;
	Numbers<> i;
}

