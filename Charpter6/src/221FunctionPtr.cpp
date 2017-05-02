#include <iostream>
using namespace std;

//函数指针指向的是函数，由它的返回类型和形参类型共同确定，与函数名无关
//声明一个函数
bool lengthCompare(const string &s1, const string & s2);
//声明一个指向该函数的指针，只需要用(*ptr)代替函数名即可
bool (*pf)(const string &s1, const string & s2);
//注意括号不能省略

//使用函数指针
void test() {
	bool(*pLengthComp)(const string &s1, const string & s2);
	pLengthComp = &lengthCompare;//注意，这里的取地址符可有可无，但是为了保持一致不致混淆，所以以后都加上&
	//调用
	bool res = (*pLengthComp)("hello", "world!");
	//函数指针如果没有指向任何函数，可以赋值为nullptr
	pLengthComp = nullptr;
}
//如果函数指针指向重载函数，俺么函数指针的类型必须与某一个重载函数精确匹配


//形参作为函数指针，将整个指针的声明作为形参（也可以省略*）
void useBigger(const string &s1, const string &s2, bool(*pf)(const string &s1, const string & s2)) {
	
}
//简化函数指针的写法
typedef decltype(lengthCompare) Func;//Func就代表了函数类型
typedef decltype(lengthCompare) *pFunc;//pFunc是函数指针类型
//也可以写全
typedef bool Func(const string &s1, const string & s2);//Func代表函数类型
typedef bool (*pFunc) (const string &s1, const string & s2);//pFunc是函数指针类型



//返回值为函数指针（函数不能返回函数，但是可以返回函数指针）
//有几种方式，类似于返回数组指针的形式
//和函数类型的形参不同，返回类型不会自动转为指针，必须显式声明为指针
//1.使用类型别名
using Func = bool(const string &, const string &);
using pFunc = bool(*)(const string &, const string &);
//示例
Func* foo1(void);
pFunc foo2(void);

//2.使用尾置返回类型
auto foo3(void) -> bool(*)(const string &, const string &);
//3.直接写全
bool(*foo4(void))(const string &, const string &);

//4.使用decltype，适用于已经存在该函数的情况
decltype(lengthCompare)* foo5(void);


void call() {
	useBigger("hello", "world!", lengthCompare);
	pFunc pf = foo1();
	pFunc pf2 = foo2();
	Func * pf3 = foo3();
}


bool lengthCompare(const string &s1, const string & s2) {
	return s1.size() > s2.size();
}