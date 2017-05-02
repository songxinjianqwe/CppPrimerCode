#include <iostream>
#include <string>
using namespace std;

//注意赋值和初始化不同
//构造函数可能有两种写法，一种是先默认初始化后赋值的方式，一种是初始化的方式

class SalesData {
public:
	//初始化的方式
	SalesData(const string& s,unsigned units,double rev):bookNo(s),unitsSold(units),revenue(rev){}
	//赋值的方式（类似于java)
	SalesData(const string& s, unsigned units, double rev) {
		bookNo = s;
		unitsSold = units;
		revenue = rev;
	}
	
private:
	string bookNo;
	unsigned unitsSold;
	double revenue;
};

//如果没有在构造函数的初始化列表显式地初始化成员，则该成员将在构造函数体之前执行默认初始化
//这种方式并不好
//因为有些情况下构造函数的初始化必不可少
//比如有成员变量为const或者引用的情况
//示例
class ConstRef {
public:
	ConstRef(int ii);
private:
	int i;
	const int ci;
	int & refI;
};
ConstRef::ConstRef(int ii) {
	i = ii;
//	ci = ii;//error
//	refI = ii;//error
}
//因为没有构造函数初始化列表，所以成员变量都进行了默认初始化，而随着构造函数体开始执行，初始化就完成了。
//初始化const变量或引用类型的位移机会就是通过构造函数初始值

ConstRef::ConstRef(int ii) :i(ii),ci(ii),refI(ii){}//ok

//成员初始化的顺序
//成员的初始化顺序和它们在类定义中的出现顺序一致，构造函数初始值列表中初始值的前后位置关系不会影响实际的初始化顺序
class X {
	int i;
	int j;
public:
	X(int val) :j(val),i(j){}//error
};
//这个构造函数是错误的
//因为i先被初始化，而j是未定义的，所以会用一个未定义的值初始化i。

//因此最好令构造函数初始值的顺序与成员声明的顺序保持一致，而且如果可能的话，尽量避免使用某些成员初始化其他成员

//默认实参和构造函数
//构造函数中也可以使用默认实参
//如果一个构造函数中的参数都被赋予了默认实参，那么这个构造函数也可以视为是默认构造函数
//但是这样的构造函数不能多于一个，否则编译器会不知道应该调用哪个

