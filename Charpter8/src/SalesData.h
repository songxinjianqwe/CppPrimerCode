#ifndef SalesData_H
#define SalesData_H
#include <iostream>
#include <string>
using namespace std;


class SalesData {
	//友元函数，可以直接访问类的private的成员变量
	friend SalesData add(const SalesData&, const SalesData&);
	friend ostream & print(ostream &, const SalesData&);
	friend istream & read(istream&, SalesData&);
private:
	string bookNo;
	unsigned unitsSold = 0;
	double revenue = 0;
	double avgPrice() const {
		if (unitsSold) {
			return revenue / unitsSold;
		} else {
			return 0;
		}
	}
public:
	string isbn() const {
		return bookNo;
	}

	SalesData & combine(const SalesData & sd) {
		unitsSold += sd.unitsSold;
		revenue += sd.unitsSold;
		return *this;//解引用this，会得到这个对象
	}//因为该函数类似于+=，该运算符的返回值就是自己，所以有必要返回自己。而返回的属于左值，所以要返回引用类型

	 //构造函数
	SalesData() = default;
	SalesData(const string & book) :bookNo(book) {
		//如果没有类内初始值的话
		unitsSold = 0;
		revenue = 0;
	}
	SalesData(const string & book, unsigned units, double reven) :bookNo(book), unitsSold(units), revenue(reven) {}
	SalesData(istream & is) {
		read(is, *this);
	}
};
SalesData add(const SalesData&, const SalesData&);
ostream & print(ostream &, const SalesData&);
istream & read(istream&, SalesData&);

SalesData add(const SalesData& item1, const SalesData& item2) {
	SalesData sum = item1;
	sum.combine(item2);
	return sum;
}
ostream & print(ostream & os, const SalesData& item) {
	os << item.isbn() << "\t" << item.unitsSold << "\t" << item.revenue;
	return os;
}
istream & read(istream & is, SalesData& item) {
	double price = 0;
	is >> item.bookNo >> item.unitsSold >> price;
	item.revenue = item.unitsSold* price;
	return is;
}
#endif // !SalesData_H