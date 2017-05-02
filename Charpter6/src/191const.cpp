#include <iostream>
#include <vector>
using namespace std;
//const与形参
//形参类型为const时，一旦实参赋值之后，不可以修改形参的值
//同时，实参可以是const，也可以不是const

//const与指针或引用形参
//赋值时的规则是：非常量可以转换成常量，反之不可

//指针或引用是可以修改实参的值的，因此如果实参是const的话，那么形参一定是const
//实参为常量，那么形参必须为常量
//实参为非常量，那么形参可以是常量，也可以是非常量

//对指针而言：顶层const是指常量指针；底层const是指 指向常量的指针
//对变量而言，顶层const是指常量变量
//对引用而言，只有常量引用一种类型

//有一个原则，只要没有改变实参的必要，将引用类型都声明为常量引用
//好处1：避免误修改实参
//好处2：扩大实参的范围。从上面可知，常量引用比普通引用所能接收的实参的范围更大；而且如果主调函数的形参就是常量引用，那么如果被调函数的形参不是常量引用，就无法传递
//比如findChar方法，如果第一个参数不是常量引用，而是string & str ，那么字符串常量就无法直接传入（实参为常量，形参也必须为常量）
void reset(int * i);
void reset(int & i);

void call2() {
	int i = 21;
	reset(&i);//实参为非常量，那么对形参没有要求
	const int ci = 21;
//	reset(&ci);//error 实参为常量，那么形参也必须为常量

	reset(i);//实参为非常量，对形参没有要求
//	reset(ci);//error 

//	reset(42);//error 只有常量引用才可以指向一个字面量
}

vector<int>::iterator changeVal(int val, vector<int>::iterator it) {
	return it;
}
