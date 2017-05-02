#include <iostream>
#include <vector>
#include <string>
using namespace std;
//类型转换规则：
//1、比int小的整型值首先提升为较大的整数类型，如果能存放在int中就放在int中，放不下就放在unsigned int
//2、条件中非布尔值转为布尔值
//3、赋值语句，右侧运算对象转为左侧运算对象的值
//4、如果算术运算或关系运算有多种类型，需要转为同一类型
//5、无符号类型的运算对象：首先进行整数提升
//如果一个是有符号类型，另一个是无符号类型，分为两种情况：
//1) 有符号类型>=无符号类型，那么有符号类型转为无符号类型（正数不变，负数加上无符号数的模）
//2) 有符号类型<无符号类型，那么：如果无符号类型的所有值都能存在该有符号类型，那么无符号类型的运算对象转为有符号类型，否则，有符号类型转为无符号类型

//允许将指向非常量的指针/引用转换成指向相应的常量类型的指针/引用
//int i ;
//const int & j = i;
//const int * p = &i;
//int & k = j;//error

//强制类型转换
//语法：cast-name<type>(expression)
//cast-name 有static_cast,dynamic_cast,const_cast,reinterpret_cast
void cast() {
	//static_cast
	//任何具有明确定义的类型转换，只要不包含底层const（指向常量的指针），都可以使用static_cast
	int i = 23,j = 12;
	double d = static_cast<double>(i) / j;
	cout << d << endl;
	
	//const_cast
	//只能改变运算对象的底层const
	//将常量对象转为非常量对象的行为，称为去掉const性质。
	//一旦去掉const性质，编译器就不能阻止对该对象进行写操作了。
	//如果该对象非常量，那么是合法的；如果是常量，那么会产生未定义的后果
	const char * pc = "hhh";
	char * p = const_cast<char*>(pc);
	//const_cast常用于函数重载的上下文中

	//reinterpret_cast
	//通常为运算对象的位模式提供较低层次上的重新解释
	//本质上依赖于机器
}
