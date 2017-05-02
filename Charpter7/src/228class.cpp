#include <iostream>
#include <string>
using namespace std;

//可以使用class或者struct来定义类
//都可以在其内部放入成员变量和成员函数
//区别在于访问权限的不同
//如果是struct，那么定义在第一个访问说明符之前的成员是public的
//如果是class，那么是private的
//访问说明符有两种:public和private
//public：在该说明符之后的成员在整个程序内都可以被访问，定义了类的接口
//private：在该说明符之后的成员可以被类的成员函数访问，但是不能被使用该类的代码访问，隐藏了类的实现细节
//对访问说明符出现的次数和位置没有限制，可以出现多次，可以重复出现


//示例：SalesData类
//成员变量有：bookNo string 编号;unitsSold unsigned 销量; revenue double 总收入
//从成员函数有：isbn()返回对象的isbn；combine 一个SalesData对象加到当前的SalesData对象中
//非成员函数有，定义在类的外部（类似java的静态方法）：add 两个SalesData对象的加法
//read从istream读到SalesData对象中
//print将SalesData对象输出到ostream中

//友元函数
//作为一个类的友元函数，可以访问它的非公有成员
//友元声明不等于函数声明，如果声明某个函数为它的友元函数，那么需要在类的内部写它的友元声明
//并且在类的外部还需要加上它的函数声明
//友元函数的声明（类外）和类都应该放在头文件中。

class SalesData {
	//友元函数，可以直接访问类的private的成员变量
	friend SalesData add(const SalesData&, const SalesData&);
	friend ostream & print(ostream &, const SalesData&);
	friend istream & read(istream&, SalesData&);
private:
	string bookNo;
	unsigned unitsSold = 0;
	double revenue = 0 ;
	double avgPrice() const;//只进行了声明
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
	SalesData(istream & is);//在外部定义
};
SalesData add(const SalesData&, const SalesData&);
ostream & print(ostream &, const SalesData&);
istream & read(istream&, SalesData&);
//定义在类内部的函数是隐式的inline函数
//成员函数可以定义在类内，也可以定义在类外

//this:
//成员函数通过一个名为this的隐式参数来访问调用它的那个对象。当我们调用一个成员函数时，用请求该函数的对象地址初始化this
//任何对类成员的直接访问都被看做this的隐式引用
//因为this的目的是总是指向这个对象，所以this是一个常量指针，我们不允许改变this中保存的地址
//注意isbn函数后面跟着一个const，有这个const表明这个成员函数是常量成员函数（不允许改变对象中成员变量的值）

//这个const的作用是改变this的类型，由常量指针修改为指向常量的常量指针，也就是const SalesData * const this
//为什么要修改呢？
//首先明确这个成员函数的目的是返回对象中的一个成员变量的值，而非修改（getter）
//并且this是隐式参数，如果不允许通过这个this参数修改其值，通常做法是将参数的类型声明为const（指向常量的指针）
//而this的类型不是指向常量的指针，所以需要进行类型转换，转换的位置就在函数的参数列表之后

//有 const 修饰的成员函数（指 const 放在函数参数表的后面，而不是在函数前面或者参数表内），只能读取数据成员，不能改变数据成员；
//没有 const 修饰的成员函数，对数据成员则是可读可写的。

//注意！成员函数体可以随意使用类中的其他成员而无需在意这些成员出现的次序（编译器会先编译成员声明、再编译成员函数）

//如果我们在类的外部定义成员函数，那么需要遵循：
//在类中对成员函数进行声明
//返回类型、参数和函数名都需要和类内部的声明保持一致
//必须包含它所属的类名
//示例
inline double SalesData::avgPrice() const {
	if (unitsSold) {
		return revenue / unitsSold;
	} else {
		return 0;
	}
}

//当我们定义的函数类似于某个内置运算符时，应该令该函数的行为尽量模仿这个运算符。
//内置的赋值运算符把它的左侧对象当成左值返回，因此为了和它保持一致，combine函数必须返回引用类型（左值可以接受其他变量的赋值操作）

//类的非成员函数：不在类中定义，也不在类中声明，但是它的定义和类的声明放在同一个头文件中
//实际上不属于类本身
SalesData add(const SalesData& item1, const SalesData& item2) {
	SalesData sum = item1;//这里是将所有成员变量拷贝一份，与java不同
	sum.combine(item2);
	return sum;
}
ostream & print(ostream & os, const SalesData& item) {
	//将流定义为引用是因为IO类不可以被拷贝
	//不使用const是因为输出的时候会改变流的内容
	os << item.isbn() << "\t" << item.unitsSold << "\t" << item.revenue;
	return os;
}
//一般来说，执行输出任务的函数应该尽量减少对格式的控制，这样可以确保由用户代码来决定是否换行。
istream & read(istream & is, SalesData& item) {
	double price = 0;
	cin >> item.bookNo >> item.unitsSold >> price;
	item.revenue = item.unitsSold* price;
	return is;
}

void countItems() {
	SalesData item, trans;
	if (read(cin, item)) {
		while (read(cin, trans)) {
			if (item.isbn() == trans.isbn()) {
				item.combine(trans);
			} else {
				print(cout, item) << endl;
				item = trans;
			}
		}
		print(cout, item) << endl;
	} else {
		cerr << "No data!" << endl;
	}
}
//构造函数
//构造函数的名字和类名相同，没有返回类型，也有参数列表和函数体
//可以有多个重载的构造函数
//构造函数不能被声明为const的函数
//当我们创建类的一个const对象时，知道构造函数完成初始化过程，对象才真正变成const的。（也就是说每一个对象在构造完成后都变为const对象了，在构造过程中还不算const的）
//如果我们没有显式指定构造函数，那么编译器会指定一个合成的默认构造函数（无需实参，成员变量如果有类内初始值，那么进行初始化；没有就进行默认初始化）
//但是我们最好自己定义默认的构造函数
//原因：1.当我们定义了其他的构造函数，与此同时我们也需要定义一个默认的构造函数（编译器不会为我们自动生成）
//2.合成的默认构造函数可能执行错误的操作，比如指针和数组的值是未定义的，可能出错
//3.编译器不能为某些类合成默认的构造函数（比如类中的一个成员是另一个类的对象，它没有默认构造函数，那么必须为当前类指定默认构造函数）

//默认构造函数语法：
// 类名()= default ;
//表示这个构造函数是默认构造函数
//= default 可以出现在类的内部（内联），也可以出现在类的外部（非内联）
//普通的构造函数语法：
//类名(参数1，参数2...): 成员变量1(参数1),成员变量2(参数2)..{...}
//表示将成员变量的值设置为各个参数，称为构造函数初始化列表（冒号和后面的赋值操作都是可以省略的）
//函数体可以为空，表示只进行赋值，不进行其他操作

//在类的外部定义构造函数
//同样需要指明该构造函数是哪个类的
SalesData::SalesData(istream & is) {
	read(is, *this);
}
//这个this就是指向当前对象的指针，对其解引用返回的值可以作为引用
//这个构造函数也完全可以定义在类的内部，都可以

//构造函数的调用：只能在声明的同时调用构造函数(与java不同)
//默认构造函数不必显式调用
//其他构造函数在声明之后写一个括号（），其中加上参数即可

//测试构造函数
void testInitialFunc() {
	SalesData item1;//调用默认构造函数
	print(cout, item1)<<endl;
	SalesData item2("123-000-1121");//调用构造函数1
	print(cout, item2)<<endl;
	SalesData item3("123-000-1121", 10, 239.9);//调用构造函数2
	print(cout, item3)<<endl;
	SalesData item4(cin);//调用构造函数3
	print(cout, item4)<<endl;
}

//用构造函数重写countItems
void countItems2() {
	SalesData item(cin);
	if (!item.isbn().empty()) {
		while (cin) {
			SalesData trans(cin);
			if (item.isbn() == trans.isbn()) {
				item.combine(trans);
			} else {
				print(cout, item) << endl;
				item = trans;
			}
		}
		print(cout, item) << endl;
	} else {
		cerr << "No data" << endl;
	}
}

int main(void) {
	testInitialFunc();
	countItems2();
	return 0;
}




