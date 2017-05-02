/*
 * 624templateSpeclization.cpp
 *
 *  Created on: 2016年10月1日
 *      Author: songx
 */

#include <algorithm>
#include <cstddef>
#include <cstring>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

//模板特例化
//在某些情况下，通用模板的定义对特定类型是不适合的，通用定义可能编译失败或做的不正确。
//当我们不能活不希望使用模板版本时，可以定义类或函数模板的一个特例化版本。

//适用于任何类型
template<typename T>
int compare(const T&, const T&);

//仅适用于数组引用
template<size_t N, size_t M>
int compare(const char (&)[N], const char (&)[M]);

//当我们传递给compare字符串字面量或字符数组会调用第二个版本，此外都会调用第一个版本
//如果传递一个字符指针，会调用第一个版本
//为了处理字符指针，可以为第一个版本的compare定义一个模板特例化的 版本。一个特例化版本就是模板的一个独立的定义，在其中一个或多个模板参数被指定为特定的类型

//函数模板特例化
//当我们特例化一个函数模板时，必须为原模板中的每个模板参数都提供实参。为了指出我们正在特例化一个模板，应使用关键字template后跟一个<>
//空尖括号指出我们将为原模板的所有模板参数提供实参

template<>
int compare(const char * const & p1, const char * const & p2) {
	return strcmp(p1, p2);
}
//当我们定义一个特例化版本，函数参数类型必须与一个先前声明的模板中对应的类型匹配。本例中我们特例化第一个模板
//其中函数参数为const引用。我们希望定义一个特例化版本，T为const char*。
//我们的函数要求一个指向此类型const版本的引用。一个指针类型的const版本是一个常量指针
//我们需要在特例化版本中使用的类型是const char *const& ，即一个指向const char的const指针的引用。

//函数重载与模板特例化
//当定义函数模板的特例化版本时，我们本质上接管了编译器的工作。即，我们为原模板的一个特殊实例提供了定义。一个特例化版本本质上是一个实例。
//而非函数名的一个重载。因此，特例化不影响函数匹配

//注意！
//为了特例化一个模板，原模板的声明必须在作用域中。而且，在任何使用模板实例的代码之前，特例化版本的声明也必须在作用域中。
//模板及其特例化版本应该声明在同一个头文件中，所有同名模板的声明应该放在前面，然后是这些模板的特例化版本。
//******************************************************************************************************

//类模板特例化

class SalesData {
	friend class hash<SalesData> ;
private:
	string bookNo;
	unsigned unitsSold;
	double revenue;
};

//我们可以为标准库hash模板定义一个特例化版本，可以用它来讲SalesData对象保存在无序容器中。
//默认情况下，无序容器使用hash<key_type>来组织其元素。
//为了让自己的数据类型也能使用这种默认组织方式，必须定义hahs模板的一个特例化版本。
//一个特例化hahs类必须定义：
//一个重载的调用运算符，它接受一个容器关键字类型的对象，返回一个size_t
//两个类型成员，result_type argument_type，分别为调用运算符的返回类型和参数类型
//默认构造函数和拷贝赋值运算符，可以隐式定义

//唯一复杂的地方在于，必须在原容器的命名空间中特例化它。
//花括号之间的任何定义都将成为命名空间std的一部分
namespace std {
template<>
struct hash<SalesData> { //注意这里类名后面有一个尖括号
	using result_type = size_t;
	using argument_type = SalesData;
	size_t operator()(const SalesData && s) const;
};
size_t hash<SalesData>::operator ()(const SalesData && s) const {
	return hash<string>()(s.bookNo) ^ hash<unsigned>()(s.unitsSold)
			^ hash<double>()(s.revenue);
}
}

//我们可以在类内或类外定义特例化版本的成员，本例中就是在类外定义的
//重载的调用运算符必须为给定类型的值定义一个哈希函数。对于一个给定值，任何时候调用此函数应该返回相同的结果。
//一个好的哈希函数对不相等的对象应该产生不同的结果。
//我们的hash函数计算所有三个数据成员的哈希值，从而与我们为SalesData定义的operator==是兼容的。
//类似于java中的hashCode和equals
//假定我们的特例化版本在作用域中，当将SalesData作为容器的关键字时，编译器就会自动使用此特例化版本。

//由于hash<SalesData>使用SalesData的私有成员，我们必须将它声明为SalesData的友元

//为了能让SalesData的用于能使用hash的特例化版本，我们应该在SalesData的头文件中定义该特例化成员。

//类模板部分实例化
//类模板的实例化不必为所有模板参数提供实参，我们可以只指定一部分而非所有模板参数，或者是参数的一部分而不是全部退恶心。
//一个类模板的部分实例化本身是一个模板，使用它时用户还必须为那些在特例化版本中未指定的模板参数提供实参。
//我们只能部分实例化类模板，而不能部分实例化函数模板。
template<typename T> class my_remove_reference {
public:
	using type = T;
};
template<typename T> class my_remove_reference<T&> { //左值引用
public:
	using type = T;
};

template<typename T> class my_remove_reference<T&&> { //右值引用
public:
	using type = T;
};
//部分特例化版本，将用于左值引用和右值引用
//由于一个部分特例化版本本质是一个模板，我们首先定义模板参数。
//部分特例化版本的名字与原模板的名字相同。对每个未完全确定类型的模板参数，在特例化版本的模板参数列表中都有一项与之对应
//在类名之后，我们要为特例化的模板参数指定实参，这些实参位于模板名之后的尖括号中。
//这些实参与原始模板的参数按位置对应。

//部分特例化版本的模板参数列表是原始模板的参数列表的一个子集或者是一个特例。
//这个例子中，特例化版本的模板参数的数目与原始模板相同，但是类型不同。
void test67() {
	my_remove_reference<decltype(42)>::type a = 0;
	cout << a << endl;
	int i = 42;
	my_remove_reference<decltype(i)>::type b = 0;
	cout << b << endl;
	my_remove_reference<decltype(move(i))>::type c = 0 ;
	cout << c << endl;
	//a b c均为int类型
	//这个就是脱去引用的原理
}

//特例化成员而不是类
//我们可以只特例化成员函数而不是特例化整个模板。
template <typename T> class Foo{
public:
	Foo(const T & t = T()):mem(t){}
	void Bar(){}
private:
	T mem;
};
//特例化Bar这个函数
template<>
void Foo<int>::Bar(){
	cout<<"特例化成员函数"<<endl;
}
void test68(){
	Foo<string>fs;
	fs.Bar();
	Foo<int>fi;
	fi.Bar();
}
//如果使用Foo<int>的成员Bar时，就会使用我们定义的特例化版本



