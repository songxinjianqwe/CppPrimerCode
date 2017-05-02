#include <iostream>
#include <string>
using namespace std;

//静态成员，包括静态成员变量和静态成员函数
//关键字static
class Account {
public:
	void calculate() {
		amount += amount*interestRate;
	}
	static double rate() {
		return interestRate;
	}
	static void rate(double);
private:
	string owner;
	double amount;
	static double interestRate;//这称为静态成员变量的声明
	static double initRate();
};
//静态成员函数不与任何对象绑定在一起，它们不包含this指针，不能声明为const，而且也不能在static函数体内使用this指针

//******************************************************************************************************************************

//不能在创建类的对象的时候初始化静态成员变量
//不能在类的内部初始化静态成员变量
//必须在类的外部初始化每个静态成员变量，可以直接赋值也可以通过静态成员函数赋值
double Account::interestRate = initRate();//这称为静态成员变量的定义和初始化


//静态成员函数可以在类的内部定义，也可以在类的外部定义
//在类的外部定义静态成员函数时，不能重复static关键字；static关键字只出现在类内部的声明语句中
void Account::rate(double newRate) {
	interestRate = newRate;
}
double Account::initRate() {
	return 0.08;
}

//******************************************************************************************************************************
//通常情况下，类的静态成员变量不应该在类内初始化，但是可以为其提供const整数类型的类内初始值，不过要求静态成员必须是字面值常量类型的constexpr，初始值必须是常量表达式
class Account2{
public:
	/*static double rate() {
		return interestRate;
	}
	static void rate(double);*/
private:
	static constexpr int period = 20;//period是常量表达式
	static const int period2 = 20;//这个也是可以的
	double dailyTtable[period2];
};
constexpr int Account2::period;
//即使一个静态常量成员变量在类内部被初始化了，也应该在类的外部进行定义。



//******************************************************************************************************************************
//静态成员变量的不同之处：可以是不完全类型（声明之后，定义之前）
class Bar {
private:
	static Bar mem1;
	Bar * mem2;
//	Bar mem3;//error 成员变量必须是完全类型
};
//另一个不同之处：可以使用静态成员变量作为默认实参
class Screen {
public:
	Screen & clear(char = background);
private:
	static const char background;
};


//******************************************************************************************************************************
//在类外，使用作用域运算符访问静态成员，也可以使用对象的引用或指针访问静态成员
void test8() {
	double r;
	r = Account::rate();//通过一个静态成员函数返回一个静态成员变量
	Account a;
	Account * pA = &a;
	r = a.rate();
	r = pA->rate();
}
//成员函数不使用作用域运算符就能直接使用静态成员
int main(void) {
	return 0;
}