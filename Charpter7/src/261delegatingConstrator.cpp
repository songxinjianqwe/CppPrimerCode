#include <iostream>
#include <string>
using namespace std;
//委托构造函数
//一个委托构造函数使用它所属类的其他构造函数执行它自己的初始化过程
//委托构造函数也有一个成员初始值列表和一个函数体。在委托构造函数内，成员初始值列表只有一个入口，就是类名本身。和其他成员初始值一样，类名后面紧跟着括号括起来的
//参数列表，参数列表必须与类中另一个构造函数匹配
//类名():类名(实参){}
//类似于java中的this();

class SalesData {
public:
	SalesData(const string & bk,unsigned units,double rev):bookNo(bk),unitsSold(units),revenue(rev){}
	//委托1
	SalesData() :SalesData("", 0, 0){}
	//委托2
	SalesData(const string & s) :SalesData(s, 0, 0){}
	//委托3，先委托了默认构造函数，默认构造函数又委托了三个参数的构造函数
	SalesData(istream & is) :SalesData() {
		read(is, *this);
	}
	istream & read(istream & is, SalesData& item) {
		double price = 0;
		cin >> item.bookNo >> item.unitsSold >> price;
		item.revenue = item.unitsSold* price;
		return is;
	}
private:
	string bookNo;
	unsigned unitsSold;
	double revenue;
};

//执行顺序：
//1.被委托的构造函数初始值列表
//2.被委托的构造函数的函数体
//3.委托者的构造函数函数体