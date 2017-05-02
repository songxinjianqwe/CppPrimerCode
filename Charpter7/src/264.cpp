#include <iostream>
#include <string>
using namespace std;
//隐式类型转换

//如果构造函数只接受一个实参，那它实际上定义了转换为此类型的隐式转化规则，有时我们把这种构造函数称作转换构造函数
//需要使用类的对象的时候，可以用参数代替

class SaleData {
public:
	SaleData(const string & bk, unsigned units, double rev) :bookNo(bk), unitsSold(units), revenue(rev) {}
	//委托1
	SaleData() :SaleData("", 0, 0) {}
	//委托2
	explicit SaleData(const string & s) :SaleData(s, 0, 0) {}
	//委托3，先委托了默认构造函数，默认构造函数又委托了三个参数的构造函数
	explicit SaleData(istream & is) :SaleData() {
		read(is, *this);
	}
	istream & read(istream & is, SaleData& item) {
		double price = 0;
		cin >> item.bookNo >> item.unitsSold >> price;
		item.revenue = item.unitsSold* price;
		return is;
	}
	string isbn() const {
		return bookNo;
	}

	 SaleData & combine(const SaleData & sd) {
		unitsSold += sd.unitsSold;
		revenue += sd.unitsSold;
		return *this;//解引用this，会得到这个对象
	}
private:
	string bookNo;
	unsigned unitsSold;
	double revenue;
};

void test1() {
	string nullBook = "100-123-222";
	SaleData item("100-123-222", 23, 12.99);
//	item.combine(nullBook);
	
//	item.combine("100-123-222");//error
	//原因是编译器只会自动地执行一步类型转换
	//这里先将“”转为string，然后将string转为SalesData
//	item.combine(cin);//ok

	//抑制隐式类型转换
	//使用explicit关键字可以避免类型转换
	//explicit关键字只对一个实参的构造函数有效，需要多个实参的构造函数不能用于执行隐式转化，所以无须将这些构造函数指定为explicit的。
	//只能在类中声明构造函数时使用explicit关键字，在类外部定义时不应重复

	//发生隐式类型转换的一种情况是当我们执行拷贝形式的初始化时，此时我们使用直接初始化而不能使用explicit构造函数
	SaleData item2(nullBook);
//	SalesData item3 = nullBook;//error


	//即使是explicit构造函数，也可以通过强制类型转换的形式
	item.combine(SaleData(nullBook));
	item.combine(static_cast<SaleData>(cin));
}