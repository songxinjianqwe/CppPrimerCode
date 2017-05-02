#include <iostream>
using namespace std;
extern int i2 = 23;
void testConst() {
	//const与变量，变量值不可修改，相当于java中的final
	const int i = 3;
//	i = 5;//error
	//编译过程中，会将所有const变量出现的地址替换为其值
	//const变量仅在文件内有效，即使多个不同文件定义了同名的const变量，也互不影响

	//如果想让一个const变量在多个文件中共享，那么需要加上extern关键字
	//不管声明还是定义都需要加上extern
}
void testConst2() {
	//const与引用
	//对常量的引用，简称常量引用
	//要求引用必须是一个const引用，而变量可以加const，也可以不加const
	//当变量和其引用都是const的时候，该变量本身不可变，也不能通过其引用来改变它
	//当变量不是const，而其引用是const的时候，该变量本身可变，但不能通过其引用来改变它
	//const引用可以指向一个字面量
	//1.
	const int i = 12;
	const int & refI = i;
//	refI = 21;//error
	//2.
	int i2 = 123;
	const int & refI2 = i2;
//	refI2 = 1234;//error
	i2 = 21;//ok
	const int & refI3 = 32;//const引用可以指向一个字面量
}
