/*
 * 517Ambiguity.cpp
 *
 *  Created on: 2016年9月17日
 *      Author: songx
 */
#include <iostream>
using namespace std;

//避免有二义性的转换
//如果类中包含一个或多个类型转换，则必须确保在类类型和目标类型之间只存在唯一一种转换方式。否则具有二义性
//两种情况会产生二义性：
//1.A类定义一个接受B类对象的转换构造函数，B类定义了转换目标是A类的类型转换运算符，它们提供了相同的类型转换
//2.类定义了多个转换规则，而这些转换涉及的类型本身可以通过其他类型转换联系在一起。最典型的是算术运算符
//不要为类定义相同的类型转换，也不要在类中定义两个及以上转换源或转换目标是算术类型的转换。

class B;
class A{
public:
	A() = default;
	A(const B &b);
};
class B{
public:
	operator A() const;
};
A fun(const A & a){
	cout<<"convert"<<endl;
}
void test80(){
	B b;
//	A a = fun(b);
	//一种解决方法是
//	A a1 = fun(b.operator A());
//	A a2 = fun(A(b));
}

class C{
public:
	C(int i = 0){}
	C(double d){}
	operator int()const;
	operator double()const;
	
};
void fun2(long l);
void test81(){
	C c;
//	fun2(c);//error
	long l = 3;
//	C c2(l);//error
	//没有最佳匹配
	//long->int  long->double 优先级一致
	//之所以会产生二义性，根本原因是它们所需的标准类型转换级别一致
	//当我们使用用户定义的类型转换时，如果转换过程包含标准类型转换，则标准类型转换的级别将决定编译器选择最佳匹配的过程
	short s = 23;
	C C3(s);//ok
	//short->int 优先级高于short->double
}
//党我们使用两个用户定义的类型转换时，如果转换函数以前或之后存在标准类型转换，则标准类型转换将决定最佳匹配是哪一个
//注意！
//1.不要令两个类执行相同的类型转换
//2.避免转换目标是内置算术类型的类型转换。
//当已经定义了一个转换成算术类型的类型转换时，不要再定义接受算术类型的重载运算符，不要定义转换到多种算术类型的类型转换



//重载函数与转换构造函数
//当多个重载函数的参数是多个不同的类类型，如果这些类定义了同样的转换构造函数，那么会产生二义性
class D{
public:
	D(int){}
};
class E{
public:
	E(int){}
};
void manip(const D&);
void manip(const E&);

void test82(){
//	manip(10);//error
	//解决方法是
//	manip(D(10));//ok
}

//重载函数与用户定义的类型转换

//因为调用重载函数锁清秋的用户定义的类型转换不止一个且彼此不同，所以该调用具有二义性 。
//即使其中一个调用需要额外的标准类型转换而另一个调用能精确匹配，编译器也会报错
//在调用重载函数时，如果需要额外的标准类型转换，则该转换的级别只有当所有可行函数都请求同一个用户定义的类型转换时才有用。
class F{
public:
	F(double d){}
};
void manip2(const E&);
void manip2(const F&);
void test83(){
//	manip2(10);//error
}


class LongDouble{
public:
	LongDouble(double = 0){}
	operator double()const;
	operator float()const;
};
void prac10(){
	LongDouble ld;
//	int ex1 = ld;//error
//	float ex2 = ld;//ok
}




//函数匹配与重载运算符
//当我们调用一个命名的函数时，具有该名字的成员函数和非成员函数不会彼此重载，这是因为我们用来调用命名函数的语法对于成员函数
//和非成员函数是不同的
//当我们通过类类型的对象（或指针、引用）进行函数调用时，只考虑该类的成员函数。
//而当我们在表达式中使用重载的运算符时，无法判断正在使用的是成员函数还是非成员函数，因此它们都在考虑的范围内。

class SmallInt3{
	friend SmallInt3 operator+(const SmallInt3&,const SmallInt3 &);
public:
	SmallInt3(int i = 0):val(i){}//转换构造函数
	operator int()const {//类型转换运算符
		return val;
	}
private:
	size_t val;
};
SmallInt3 operator+(const SmallInt3& lhs,const SmallInt3 &rhs){}
void test84(){
	SmallInt3 s1,s2;
	SmallInt3 s3 = s1 + s2;//调用的是非成员函数版本
//	int i = s3 + 0;//这里存在问题，是s3转为int还是0转为SmallInt?
}
//当我们对同一个类既提供了转换目标是算术类型的类型转换，也提供了重载的运算符，则会遇到重载运算符和内置运算符的二义性问题。

