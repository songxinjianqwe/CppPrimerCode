/*
 * 666IO.cpp
 *
 *  Created on: 2016年10月1日
 *      Author: songx
 */




#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

//IO库
//格式化输入输出
//标准库定义了一组操纵符来修改流的格式状态，一个操纵符是一个函数或是一个对象，会影响流的状态，并能用作输入输出运算符的运算对象。
//类似输入和输出运算符，操纵符也会影响它所处理的流对象，因此我们可以在一条语句中组合操纵符和数据。
//操纵符用于两大类输出控制：控制数值的输入形式以及控制补白的数量和位置，大多数改变格式状态的操纵符都是设置/复原成对的。
//一个操纵符用来将格式状态设置为一个新值，而另一个用来将其复原，恢复为正常的默认格式。

//当操纵符改变流的格式状态时，通常改变后的状态对所有后续IO都生效。
//通常最好在不再需要特殊格式时尽快将流恢复到默认状态


//1.控制布尔值的格式
//boolalpha将布尔值打印值设置为true false 
//noboolalpha返回原状

void test10(){
	cout<<true<<"\t"<<false<<endl;
	cout<<boolalpha<<true<<"\t"<<false<<noboolalpha<<endl;
}
//2.指定整型值的进制
//oct 8  hex 16 dec 10 
//使用dec返回原状
void test11(){
	cout<<hex<<20<<dec<<endl;
	cout<<oct<<20<<dec<<endl;
	cout<<dec<<20<<endl;
}
//附加表示进制的符号
//showbase 
//noshowbase返回原状

void test12(){
	cout<<showbase;
	cout<<hex<<20<<dec<<endl;
	cout<<oct<<20<<dec<<endl;
	cout<<dec<<20<<endl;
	cout<<noshowbase;
}

//3.控制浮点数的格式
//包括精度、进制（表示法）、是否打印小数点
//precision成员/setprecision函数控制精度，即打印的数字的总数，不含小数点
//precision 是重载的，一个版本接受一个int，将精度设置为此值；另一个版本不接受参数，返回当前精度值。
//这些控制符定义在iomanip头文件中
//数学库函数cmath

void test13(){
	cout<<sqrt(2.0)<<endl;
	cout.precision(12);
	cout<<sqrt(2.0)<<endl;
	cout<<setprecision(3);
	cout<<sqrt(2.0)<<endl;
}




int main(){
	test13();
}
