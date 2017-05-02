/*
 * 440Copy.cpp
 *
 *  Created on: 2016年9月12日
 *      Author: songx
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//一个类通过定义五种特殊的成员函数来控制拷贝、移动、赋值、销毁操作：拷贝构造函数、拷贝赋值运算符、移动构造函数、移动赋值运算符、析构函数
//拷贝和移动构造函数定义了当用同类型的另一个对象初始化本对象时做什么
//拷贝和移动赋值运算符定义将一个对象赋予同类型的另一个对象时做什么
//析构函数定义了当此类型对象销毁时做什么
//这些统称为拷贝控制操作

//在定义C++类的时候，拷贝控制操作都是必须的

//拷贝构造函数
//如果一个构造函数的第一个参数是自身类类型的引用，且任何额外参数都有默认值，则此构造函数是拷贝构造函数
//拷贝构造函数通常不应该是explict
//合成拷贝构造函数
//即使我们自己定义了其他构造函数，编译器你也会为我们呵呵才能一个拷贝构造函数
//一般情况下，合成的拷贝构造函数会将其参数的成员诸葛拷贝到正在创建的对象中
//每个成员的类型决定了它如何拷贝：对类类型的成员，会使用其拷贝构造函数来拷贝；内置类型的成员则直接拷贝；逐元素地拷贝一个数组类型的成员
class SalesData {
public:
	SalesData(const SalesData &);
private:
	string bookNo;
	unsigned unitsSold = 0;
	double revenue = 0;
};
SalesData::SalesData(const SalesData & orig) :
		bookNo(orig.bookNo), unitsSold(orig.unitsSold), revenue(orig.revenue) {
}
//拷贝初始化
//拷贝初始化是使用=运算符来实现的，将等号右侧的对象拷贝到左侧的对象中；其他方式是直接初始化
void test1(){
	string s("Hello");//直接初始化
	string s2 = s;//拷贝初始化
}
//直接初始化是要求编译器使用普通的函数匹配来选择与我们提供的参数最匹配的构造函数；拷贝初始化是要求编译器将右侧运算对象拷贝到正在创建的对象中
//拷贝初始化通常使用拷贝构造函数来完成。如果一个类有一个移动构造函数，则拷贝初始化有时会使用移动构造函数而非拷贝构造函数来完成。
//拷贝初始化不仅在用=定义变量时会发生，以下情况也会发生：
//将一个对象作为实参传递给一个非引用类型的形参
//从一个返回类型为非引用类型的函数返回一个对象
//用花括号列表初始化一个数组中的元素或一个聚合类的成员

//拷贝构造函数被用来初始化非引用类类型参数，这一特性解释了为什么拷贝构造函数自己的参数必须是引用类型。如果其参数不是引用类型，则调用永远也不会成功
//为了调用拷贝构造函数，我们必须拷贝它的实参，但为了拷贝实参，我们又需要调用拷贝构造函数。

//如果我们的初始化值要求通过一个explict的构造函数来进行类型转换，那么使用拷贝初始化还是直接初始化就不是无关紧要的了。
//vector<int> v1(10);//ok 直接初始化
//vector<int> v2 = 10;//error 拷贝初始化

//编译器还可以绕过拷贝/移动构造函数,直接创建对象，将拷贝初始化转为直接初始化


//13.5
class HasPtr{
	friend void swap(HasPtr &,HasPtr &); 
	friend bool operator<(const HasPtr &,const HasPtr &);
public:
	HasPtr(const string & s = string()):ps(new string(s)),i(0){}
	HasPtr(const HasPtr & orig):ps(new string(*orig.ps)),i(orig.i){}
	HasPtr& operator=(const HasPtr & hp){
		string * newPtr = new string(*hp.ps);
		delete ps;
		ps = newPtr;
		i = hp.i;
		return *this;
	}
	~HasPtr(){
		delete ps;
	}
	
	string  toString()const {
		return *ps;
	}
	void swap(HasPtr & rhs){
		std::swap(ps,rhs.ps);
		std::swap(i,rhs.i);
		cout<<"call swap(HasPtr & rhs)"<<endl;
	}
private:
	string * ps;
	int i;
};

//注意拷贝构造函数和拷贝赋值运算符的区别：一句话，
//‘＝’只有在赋值时，才调用赋值函数，当在声明变量时，B b3=b1和B b4(b3)调用的函数是一样的，均为拷贝构造函数。
//定义对象并初始化时调用拷贝构造函数，以后的=均为拷贝赋值运算符
//区别2：拷贝构造函数通常是深拷贝（系统提供的是浅拷贝），拷贝赋值运算符通常是浅拷贝  当然这一点并没有规定
//区别3：拷贝赋值运算符要注意原有对象的动态内存释放问题，拷贝构造函数不必考虑这一点
inline void swap(HasPtr & left,HasPtr & right){
	swap(left.ps,right.ps);
	swap(left.i,right.i);
	cout<<"call swap(HasPtr & left,HasPtr & right)"<<endl;
}

bool operator<(const HasPtr & lhs,const HasPtr & rhs){
	return *lhs.ps < *rhs.ps;
}

void test(){
	vector<HasPtr> hVec = {HasPtr("ccc"),HasPtr("bbb"),HasPtr("aaa")};
	sort(hVec.begin(),hVec.end());
	for(const auto & h:hVec){
		cout<<h.toString()<<endl;
	}
}

