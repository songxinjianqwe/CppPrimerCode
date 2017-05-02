/*
 * 684exception.cpp
 *
 *  Created on: 2016年10月1日
 *      Author: songx
 */

#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;
//异常
//通过抛出一条表达式来引发一个异常
//当执行一个throw时，跟在throw后面的语句不再被执行。相反，程序的控制权从throw转移到与之匹配的catch模块。
//该catch可能是同一个函数中的局部catch，也可能位于直接或间接调用了发生异常的函数的另一个函数中。
/*

 catch(my_error & obj){
 obj.status = errCodes::severeErr;
 throw;
 }catch(other_error obj){
 obj.status = errCodes::badErr;//只修改了异常对象的局部副本，异常对象没有改变
 throw;
 }
 */
void manip() {
	try {
		//
	} catch (...) {
		//
	}
}
//try块和构造函数
//构造函数在进入函数体之前首先执行初始值列表，因为在初始值列表抛出异常时构造函数体内的try块还没生效，所以catch语句无法处理
//在构造函数初始值列表抛出的异常
//解决办法是将构造函数携程函数try语句块的形式。
//函数try语句使得一组catch语句既能处理构造函数体，也能处理构造函数的初始化过程。
template<typename T>
Blob<T>::Blob(initializer_list<T> il)
try :
		data(make_shared < vector < T >> (il)) {
}
catch (bad_alloc & e) {
	handle_out_of_memory(e);
}
//处理构造函数初始值的唯一方法是将构造函数写成函数try语句块
//*****************************************************************************
//noexcept异常说明
//可以通过提供noexcept说明指定某个函数不会抛出异常。形式是关键字noexcept紧跟在函数的参数列表后面，用以标识该函数不会抛出异常
void recoup(int) noexcept;
//对一个函数而言noexcept说明要么出现在该函数的所有声明语句和定义语句中，要么一次也不出现。该说明在函数的尾置返回类型之前。
//在成员函数中，noexcept说明符需要跟在const及引用限定符之后，而非final、override或虚函数=0之前。

//违反异常说明
//编译器并不会在编译时检查noexcept说明，如果一个函数在说明了noexcept的同时又含有throw语句或调用了可能抛出异常的其他函数
//编译器将顺利编译通过。
void f() noexcept{
	throw exception();
}

//一旦一个noexcept函数抛出了异常，程序就会调用terminate以确保遵守不再运行时抛出异常的承诺。
//异常说明的实参
//noexcept说明符接受一个可选的实参。该实参需要能转为bool类型。
//如果实参是true，则函数不会抛出异常；如果是false，那么函数可能抛出异常。
void recoup(int) noexcept(true);
void alloc(int ) noexcept(false);
void g();
//noexcept运算符
//noexcept说明符的实参常常与noexcept运算符混合使用。
//noexcept运算符是一个一元运算符，它的返回值是一个bool类型的右值常量表达式
//用于表示给定的表达式是否会抛出异常。
//和sizeof类型，noexcept也不会求其运算对象的值
int i = 2;
noexcept(recoup(i));//返回true
noexcept(e);//当e调用的所有函数都做了不抛出说明且e本身不含有throw语句时，上述表达式为true；否则为false

void f() noexcept(noexcept(g()));//f和g的异常说明一致
//如果函数g承诺了不会抛出异常，则f也不会抛出异常；如果g没有异常说明符，或者g有异常说明符但是允许抛出异常，则f也可能抛出异常
//noexcept有两层含义：当跟在函数参数列表后面时它是异常说明符；而当作为noexcept异常说明的bool实参出现时，它是一个运算符

//异常说明与指针、虚函数和拷贝控制
//函数指针几该指针所指向的函数必须具有一致的异常说明。如果我们为某个指针做了不抛出异常的声明，则该指针只能指向不抛出异常的函数。
//相反，如果我们显式或隐式说明了指针可能抛出异常，则该指针可以指向任何函数，即使承诺了不抛出异常的函数也可以

void test(){
	void (*pf1)(int) noexcept = recoup;
	void (*pf2)(int) = recoup;
	//ok
//	pf1 = alloc;//error
	pf2 = alloc;
}
//如果一个虚函数承诺了它不会抛出异常，则后续派生出来的虚函数也必须做出同样的承诺；
//与之相反，如果基类的虚函数允许抛出异常，则派生类对应函数既可以抛出异常，也可以不允许抛出异常。
class Base{
public:
	virtual double f1(double) noexcept;
	virtual int f2() noexcept(false);
	virtual void f3();
};
class Derived:public Base{
public:
//	double f1(double);//error
	int f2() noexcept(false);//ok
	void f3() noexcept;//ok
};
//当编译器合成拷贝控制成员时，同时也生成一个异常声明。如果对所有成员和基类的所有操作都承诺了不会抛出一长，则合成的成员是noexcept
//如果合成成员调用的任意一个函数可能抛出一长，则合成的成员是noexcept(false);

//异常类层次
//               exception
//             /           \
//        bad_cast /  \     bad_alloc
//                /    \
//       runtime_error logic_error
//            |             |
//            |             |
//    overflow_error    domain_error
//    underflow_error   invalid_argument
//    range_error       out_of_range
//                      length_error

//exception定义了拷贝构造函数，拷贝赋值运算符，一个虚析构函数和一个名为what虚成员。
//what函数返回一个const char *。该指针指向一个以null结尾的字符数组，并且确保不会抛出任何异常。
//exception 、bad_alloc、bad_cast定义了默认构造函数。runtime_error、 logic_error没有默认构造函数
//但是有一个可以接受C风格字符串或string的构造函数。这些实参负责提供关于错误的更多信息。
//what负责返回用于初始化异常对象的信息。因为what是虚函数，所以当我们捕获基类的引用时，对what函数的调用将执行与异常对象动态类型对应的版本
//为书店程序写一个异常类
class out_of_stock:public runtime_error{
public:
	explicit out_of_stock(const string & s):runtime_error(s){}
};
class isbn_mismatch:public logic_error{
public:
	explicit isbn_mismatch(const string & s):logic_error(s){}
	isbn_mismatch(const string & s,const string & lhs,const string & rhs):
		logic_error(s),left(lhs),right(rhs){}
	const string left,right;
};
class SalesData{
	friend istream & operator>>(istream & is,SalesData & sd);
	friend SalesData operator+(const SalesData & lhs,const SalesData & rhs);
public:
	SalesData() = default;
	string  isbn() const{
		return bookNo;
	}
	SalesData & operator+=(const SalesData & rhs);
private:
	string bookNo;
	unsigned unitsSold;
	double revenue;
};
SalesData & SalesData::operator+=(const SalesData & rhs){
	if(isbn() != rhs.isbn()){
		throw isbn_mismatch("wrong isbns",isbn(),rhs.isbn());
	}
	unitsSold += rhs.unitsSold;
	revenue += rhs.revenue;
	return *this;
}
void test2(){
	SalesData item1,item2,sum;
	while(cin>>item1>>item2){
		try{
			sum = item1 + item2;
		}catch(const isbn_mismatch & e){
			cerr<<e.what()<<e.left<<e.right<<endl;
		}
	}
}






