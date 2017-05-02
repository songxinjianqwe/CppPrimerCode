#include <iostream>
#include <string>
using namespace std;
//之前学到的constexpr函数，它的参数和返回值都必须是字面值类型
//类也可以是字面值类型的
//字面值类型的类可能含有constexpr成员函数。这样的成员函数必须符合constexpr函数的所有要求，它们是隐式const的

//数据成员都是字面值类型的聚合类是字面值常量类
//如果一个类不是聚合类，但符合下列要求，也是字面值常量类
//1.数据成员都必须是字面值类型
//2.类必须至少含有一个constexpr构造函数
//3.如果一个数据成员含有类内初始值，则内置类型成员的初始值必须为一条常量表达式；或者如果成员属于某种类类型，则初始值必须使用成员自己的constexpr构造函数
//4.类必须使用析构函数的默认定义，该成员负责销毁类的对象

//构造函数不能是const的，但字面值常量类的构造函数可以是constexpr的函数
//constexpr构造函数可以声明为= default或者删除函数的形式
//除此之外，constexpr构造函数必须既符合构造函数的要求（没有返回语句），又符合constexpr函数的要求(唯一的可执行语句就是返回语句)
//因此，constexpr构造函数体一般是空的

class Debug {
public:
	constexpr Debug(bool b = false) :hardWare(b), io(b), other(b){}
	constexpr Debug(bool hw,bool io,bool oth) : hardWare(hw), io(io), other(oth) {}
	constexpr bool any() {
		return hardWare || io || other;
	}
	void setHardWare(bool b) {
		hardWare = b;
	}
	void setIO(bool b) {
		io = b;
	}
	void setOther(bool b) {
		other = b;
	}
private:
	bool hardWare;
	bool io;
	bool other;
};

void test5() {
	constexpr Debug ioSub(false, true, false);
	if (ioSub.any()) {
		cout << "print approprivate error messages" << endl;
	}
	constexpr Debug prod(false);
	if (prod.any()) {
		cout << "print an error message" << endl;
	}
}

