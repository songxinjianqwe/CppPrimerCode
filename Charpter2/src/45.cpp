#include <iostream>
using namespace std;
int main(void) {
	int val = 1024;
	int & refVal = val;
	cout << val << endl;
	cout << refVal << endl;//引用就是别名，可以直接输出，相当于输出原值
	//引用不是对象，没有实际地址
	//引用在定义时需要加&，使用时不需要再加这个，所以命名时最好加上标识，提示这个是引用类型
	//在定义的同时必须给予一个初值（变量而非字面量），也就是必须绑定到一个变量身上，
	refVal = 2014;
	cout << val << endl;//通过引用可以修改原值
	int val2 = 3;
	refVal = val2;//引用不能重新绑定到另一个变量上，这样做实际上是将另一个变量的值赋给原来的变量
	cout << refVal << endl;
	cout << val << endl;

	double val3 = 20.14;
	refVal = val3; //实际上是将double 类型的值转为int然后赋给val
	cout << refVal << endl;
	refVal = 10.21;//实际上是将double 类型的值转为int然后赋给val
	cout << refVal << endl;

	//注意绑定的时候变量和引用必须是同一类型
	int i = 2;
	int & refi = i;
	//	double & refi = i;//error
	double d = 32;
	double & refd = d;
	i = refd;//可以将引用赋给一个变量，相当于将引用指向变量的值转型后赋给该变量
	refd = i;//也可以将变量赋给引用，相当于该变量的值赋给该引用指向的变量
	refi = refd;//也可以将一个引用赋给另一个引用，相当于将后一个引用指向变量的值赋给前一个引用指向的值
	cout << i << endl;
	cout << endl;
	//练习2.17
	int i2, &refI2 = i2;
	i2 = 5;
	refI2 = 10;
	cout << i2 << "  " << refI2 << endl;
	return 0;
}
