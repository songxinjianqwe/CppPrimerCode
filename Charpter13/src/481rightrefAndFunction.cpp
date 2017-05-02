/*
 * 481rightrefAndFunction.cpp
 *
 *  Created on: 2016年9月14日
 *      Author: songx
 */
#include <iostream>
#include "StrVec.h"
using namespace std;

//右值引用和成员函数
//除了构造函数or运算符，拷贝和移动的区别也可以用在普通的函数上。
//一个成员函数可以同时提供拷贝和移动版本，一个版本接受一个const& const左值引用，一个版本接受一个&&右值引用

void StrVec::push_back(const string & e) {
	check_n_copy();
	alloc.construct(firstFree++, e);
	//第一个参数是指针，指向微构造的内存空间，剩余参数确定用哪个构造函数来构造对象(这里调用的是string的拷贝构造)
}
//重载的接受一个右值引用的函数
void StrVec::push_back(string &&e) {
	check_n_copy();
	alloc.construct(firstFree++, move(e));
}

//当我们调用push_back时，实参类型决定了新元素是拷贝还是移动到容器中
void test50() {
	StrVec vec;
	string s = "HelloWorld";
	vec.push_back(s); //调用第一个版本
	vec.push_back("done"); //调用第二个版本
}

//通常我们在一个对象上调用成员函数，而不管这个对象是左值还是右值
void test51() {
	string s1 = "Hello", s2 = "World";
	(s1 + s2) = "wow";
	//在这里s1+s2是一个右值，此处我们对一个右值进行了赋值（没有语法错误，但是在java中是禁止的）
}
//新标准库仍然允许向右值赋值，但是我们可能希望在自己的类中阻止这种用法，我们希望强制左侧运算对象是一个左值
//与定义const成员函数相同，在参数列表后放置一个引用限定符。
//引用限定符可以是&或&&，分别指出this可以指向一个左值或右值。类似const限定符，引用限定符只能用于非静态成员函数，且必须同时出现在函数的声明和定义中。
//对于&限定的函数，我们只能将它用于左值；对于&&限定的函数，只能用于右值
class Foo {
public:
	Foo & operator=(const Foo&) &; //只能用于左值
};
Foo & Foo::operator =(const Foo & foo) & {
	return *this;
}

Foo & retRef1(Foo& f) {
	return f; //返回一个左值引用，
}
Foo retVal1() {
	return Foo(); //返回一个值，也是右值引用
}
void test52() {
	Foo i, j;
	retRef1(j) = i;
//	retVal() = j;//error
	i = retVal1();
}
//一个函数可以同时用const和引用限定，引用限定符必须在const之后
class Foo2 {
public:
	Foo someMem() const &;
};

//引用限定符也可以区分重载版本，而且可以综合引用限定符和const来区分一个成员函数的重载版本
//const & 表示是所有对象都可以调用，并且this是一个左值，也就是操作有可能会改变对象，const也限制了不能修改对象
//&&表示this是一个右值引用，也就是临时变量，没有其他用户，因此可以自由修改对象

class Foo3 {
public:
	Foo3 sorted() &&;
	Foo3 sorted() const &;
private:
	vector<int> data;
};
Foo3 Foo3::sorted() && {
	sort(data.begin(), data.end());
	return *this;
}
Foo3 Foo3::sorted() const & {
	Foo3 t(*this);
	sort(t.data.begin(), t.data.end());
	return t;
}

Foo3 & retRef(Foo3& f) {
	return f; //返回一个左值引用，
}
Foo3 retVal() {
	return Foo3(); //返回一个值，也是右值引用
}
void test53() {
	Foo3 i, j;
	retVal().sorted(); //调用的是Foo3::sorted() &&
	retRef(i).sorted(); //调用的是Foo3::sorted() const &
}

//当我们定义const成员函数时，可以定义两个版本：唯一的差别是一个版本有const，一个版本没有
//引用限定的函数不同，如果定义两个及以上具有相同名字和参数列表的成语函数，那么它们必须都要有引用限定符、
