/*
 * 595MemberTemplate.cpp
 *
 *  Created on: 2016年9月29日
 *      Author: songx
 */

#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

//成员模板
//一个类（无论是否是类模板）可以包含本身是模板的成员函数，这种成员被称为成员模板。成员模板不能是虚函数
//我们定义 一个类，类似于unique_ptr所使用的默认删除器类型。
//将包含一个重载的函数调用运算符，接受一个指针并对此指针执行delete操作。
//由于希望删除器适用于任何类型，因此将该调用运算符定义为一个模板

class DebugDelete{
public:
	DebugDelete(ostream & s = cerr):os(s){}
	template<typename T> 
	void operator()(T * p)const{
		os<<"deleteing unique_ptr"<<endl;
		delete p;
	}
	
private:
	ostream & os;
};
//成员模板时以模板参数列表开始的
void test30(){
	double * p = new double;
	DebugDelete d;
	d(p);
	int * ip = new int;
	DebugDelete()(ip);//创建一个临时的DebugDelete对象
}
//我们可以将DebugDelete用作unique_ptr的删除器
void test31(){
	unique_ptr<int,DebugDelete> p(new int,DebugDelete());
	unique_ptr<string,DebugDelete> sp(new string,DebugDelete());
	//无论何时unique_ptr的析构函数实例化时，DebugDelete的调用运算符都会实例化
}

//对于类模板，我们也可以为其定义成员模板；在此情况下，类和成员各自有自己的、独立的模板参数。
//Blob类：为其定义一个构造函数，接受两个迭代器，因为希望接受不同类型的跌打爱妻，因此将构造函数定义为模板

template<typename T>class Blob{
public:
	template<typename It> Blob(It begin,It end);
	Blob() = default;
private:
	shared_ptr<vector<T>> data;
};
//当我们在类模板外定义一个成员模板时，必须同时为类模板和成员模板提供模板参数列表。类模板的参数列表在前，后跟成员自己的模板参数列表。
template<typename T>
template<typename It>
Blob<T>::Blob(It begin,It end):data(make_shared<vector<T>>(begin,end)){}


//为了实例化一个类模板的成员模板，我们必须同时提供类和函数模板的实参
void test32(){
	vector<int> iVec = {0,1,2,3};
	Blob<int> b(iVec.begin(),iVec.end());
	int arr[] = {1,2,3,4};
	Blob<int> b2(begin(arr),end(arr));
}

//***********************************************************************************************************

//控制实例化
//当模板被使用时才会进行实例化。
//这一特性意味着相同的实例可能出现在多个对象文件中。当两个或多个独立编译的源文件使用了相同的模板，并提供了相同的模板参数时，每个文件中就都会有该模板的一个实例
//在大系统中，在多个文件中实例化相同模板的额外开销可能非常严重。在新标准中，我们可以通过显式实例化来避免这种开销。
//一个显式实例化有如下格式：
//template declaration
//extern template declaration

//在一个文件中（出现一次）
template class Blob<string>;//实例化定义
//在多个文件中（可以出现多次）
extern template class Blob<string>;//实例化声明

//当编译器遇到extern实例化声明时，它不会在本文件中生成实例化代码。将一个实例化声明为extern就承诺在程序其他位置有该实例化定义（不带有extern的）
//对于一个给定的实例化版本，可能有多个extern声明，但只有一个实例化定义。

//由于编译器在使用一个模板时自动对其实例化，所以extern声明必须出现在任何使用此实例化版本的代码之前。

/////////////////////////////////////////////////
//pplication.cpp 
extern template class Blob<string>;//放在函数外
void test35(){
	//以上为实例化声明
	Blob<string> s1,s2;
	Blob<int> a1;
}

//templateBulid.cpp
//template class Blob<string>;

//////////////////////////////////////////////////

//当编译器遇到一个实例化定义时，它会为其生成代码。
//当我们编译此应用程序时，必须将Application.o和templateBuild.o链接到一起
//对某个实例化声明，程序中某个位置必须有其显式对的实例化定义


//一个类模板的实例化定义会实例化该模板的所有成员，包括内联的成员函数，当编译器遇到一个实例化定义，它不了解程序会使用哪些成员函数。
//因此，与处理类模板的普通实例化不同，编译器会实例化该类的所有成员。即使我们不使用某个成员，它也会被实例化。
//因此，我们用来显式实例化一个类模板的类型，必须能用于模板的所有成员。

//在一个类模板的实例化定义中，所用类型必须能用于模板的所有成员函数。









