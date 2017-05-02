/*
 * 514ClassTypeConvert.cpp
 *
 *  Created on: 2016年9月17日
 *      Author: songx
 */

#include <iostream>
using namespace std;

//类的类型转换
//将一个对象转为另一个类的对象是通过类的构造函数实现的，可以隐式地将一个对象转为类的对象
//这个构造函数称为隐式构造函数
//还可以将类的对象转为另一个对象，使用的是类型转换运算符

//类型转换运算符是类的一种特殊成员函数，负责将一个类的对象转为其他类型。
//形式如下：operator type() const;
//type 是目标类型
//类型转换运算符可以面向任意类型进行定义（除void），只要该类型能作为函数的返回类型
//我们不允许转为数组或函数，但可以转为指针（函数指针、数组指针）或引用类型

//类型转换运算符没有显式的返回类型，没有形参，而且必须为成员函数，通常情况下不应该修改对象，所以定义为const
//实例：
class SmallInt {
public:
	SmallInt(int i = 0) :
			val(i) {
		if (i < 0 || i > 255) {
			throw out_of_range("Bad SmallInt Value");
		}
	}
	operator int() const {
		return val;
	}
private:
	size_t val;
};

//SmallInt定义了两种类型的转换，从int转为SmallInt,从SmallInt转为int
//默认情况下都是隐式的转换
void test70() {
	SmallInt si;
	si = 4; //首先将4隐式转为SmallInt，然后调用SmallInt::operator=
	si + 3; //首先将si隐式转为int，然后执行整数加法
}
//编译器一次执行执行一个用户定义的类型转换
//但是隐式的类的类型转换可以放在一个隐式内置的类型转换之前或之后（比如算术类型的值之间的转换）
//因此，我们可以将任何算术类型传递给SmallInt的构造函数，也能使用类型转换运算符将一个SmallInt对象转为int，然后将int转为其他算术类型
void test71() {
	SmallInt si = 3.14;
	si + 3.14; //ok
}
//使用类型转换运算符时要注意：如果二者不存在严格的一对一的关系，那么最好不要定义。
//由于内置类型转换的存在，所以当定义了转为bool的类型转换运算符，也有可能作为int来使用

//为了避免这种情况，引入了显式的类型转换运算符
class SmallInt2 {
public:
	SmallInt2(int i = 0):val(i) {
		if(i<0 || i >255) {
			throw out_of_range("Bad SmallInt Value");
		}
	}
	explicit operator int() const {
		return val;
	}
	explicit operator bool() const{
		return val;
	}
private:
	size_t val;
};
//加入explicit之后，就无法实现隐式的类型转换了，必须使用static_cast<T>来实现显式类型转换
//一个例外是，如果对象被用作条件，那么仍然是隐式的执行类型转换
//if while do...while for(;;) ! && || ?:
//转为bool:向bool的转换通常用于条件部分，因此operator bool()一般定义为explicit
void test72() {
	SmallInt2 si2 = 3;
//	si + 3;//error
	static_cast<int>(si2) + 3; //ok
	if(si2){
		cout<<"True"<<endl;
	}
}


