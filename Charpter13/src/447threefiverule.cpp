/*
 * 447threefiverule.cpp
 *
 *  Created on: 2016年9月12日
 *      Author: songx
 */
#include <iostream>
using namespace std;
//三五法则
//拷贝控制:当前已知有 拷贝构造函数、拷贝赋值运算符、析构函数
//1.有析构函数一定有拷贝构造函数和拷贝控制运算符（存在指针，拷贝时不可以是默认的拷贝指针，而是修改为拷贝值）
//2.拷贝构造函数和拷贝赋值运算符必须同时存在或同时不存在（对析构函数没有要求），比如定义独一无二的序号
int publicId = 0;
class Numbered{
public:
	Numbered():id(++publicId){}
	Numbered(const Numbered & n):id(n.id+1){}
	int id;
};
void f(Numbered s){
	cout<<s.id<<endl;
}
void f(const Numbered &s){
	cout<<s.id<<endl;
}
void test10(){
	Numbered a,b = a,c = b;
	f(a);
	f(b);
	f(c);
	//13.14
	//1 1 1 
	
	//14.15
	//2 3 4 先是1 2 3，调用函数后变为2 3 4 
	
	//14.16
	//1 2 3 
	
}




