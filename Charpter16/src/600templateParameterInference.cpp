/*
 * 600templateParameterInference.cpp
 *
 *  Created on: 2016年9月29日
 *      Author: songx
 */


#include <iostream>
#include <string>
#include <type_traits>

using namespace std;

//模板实参推断
//对于函数模板，编译器利用调用中的函数实参来确定其模板参数，从函数实参来确定模板实参的过程被称为模板实参推断。
//在模板实参推断过程中，编译器使用函数调用中的实参类型来寻找模板实参，用这些模板实参生成的函数版本与给定的函数调用最为匹配
//
//类型转换与模板类型参数
//
//只有很有限的几种类型转换会自动地应用于这些实参。编译器通产不是对实参进行类型转换，而是生成一个新的模板实例。
//顶层const都会被忽略
//在其他的类型转换中，能在调用中应用于函数模板的包括以下两项：
//const转换:非const转const（引用、指针）
//数组或函数指针转换（数组名转为数组首元素指针；函数名转为函数指针）


//其他类型转换，如算术转换、派生类向基类的转换以及用户定义的转化，都不能用于函数模板
//注意：两个相同的模板参数为数组引用，如果传递数组实参中两个数组大小不同，那么不能通过，被视为两个不同类型

//如果希望对函数实参进行正常的类型转换，我们可以将函数模板定义为两个类型参数：
template<typename A,typename B>
int flexibleCompare(const A & v1,const B& v2){
	if(v1 < v2){
		return -1;
	}else if(v1 > v2){
		return 1;
	}else{
		return 0;
	}
}

//函数模板可以有 普通类型的参数。这种函数实参不进行特殊处理，可以进行正常的类型转换
template<typename T>
ostream & print(ostream &os,const T & obj){
	return os<<obj;
}
//第一个实参可以是ofstream，可以转换为ostream &
//如果函数参数类型不是模板参数，则对实参进行正常的类型转换。


//**********************************************************************************

//函数模板显示实参

//在某些情况下，编译器无法推断出模板实参的类型，在其他情况下，我们希望允许用户控制模板实例化。当函数返回类型与参数列表中任何类型都不相同时，这两种情况最常出现。
//指定显式模板实参
//返回类型
template <typename T1,typename T2,typename T3>
T1 sum(T2 t1,T3 t2){
	return t1+t2;
}

//没有任何函数实参的类型可以用来推断T1的类型。每次调用sum时调用者都必须为T1提供一个显示模板实参。
//我们提供显式模板实参的方式与定义类模板实例的方式相同，显示模板实参在尖括号中给出，位于函数名之后，参数列表之前。
int i = 2;
long lng = 23;
auto val3 = sum<long long>(i,lng);
//显式模板实参由从左到右的顺序与对应的模板参数匹配；第一个模板实参与第一个模板参数匹配，依次类推。
//只有最右参数的显式模板实参可以忽略，而且前提是它们可以从函数参数推断出来。
//糟糕的设计
template <typename T1,typename T2,typename T3>
T3 alternative_sum(T2 t1 ,T1 t2){
	return t1+t2;
}
//如果要调用
auto val2 = alternative_sum<long long,int,long>(i,lng);

//对于模板类型参数已经显式指定了的函数实参，也进行正常的类型转换
template<typename T>
int compare(T t1,T t2){
	if(t1 < t2){
		return -1;
	}else if(t1 > t2){
		return 1;
	}else{
		return 0;
	}
}
void test40(){
	compare<long>(lng,1024);//正确，实例化compare(long,long)
	compare<int>(lng,1024);//正确，实例化compare(int,int)
}

//如果我们显式指定模板类型参数，就可以进行正常类型转换了。因此，上面compare<long>中1024被自动转为了long;compare<int>中lng被自动转为了int

//****************************************************************************************************************
//尾置返回类型与类型转换

//当我们希望用户确定返回类型时，用显式模板参数表示模板函数的返回类型是有效的
//但在其他情况下，要求显式指定模板实参会给用户增添额外负担，而且不会带来什么好处
//template <typename It>
//??? & fcn(It being,It end){
//	return *begin;
//}

//我们并不知道返回结果的准确类型，但知道所需类型是所处理的序列的元素类型
//我们知道函数应该返回*begin，而且知道我们可以用decltype(*begin)来获取此表达式的类型
//但是，在编译器遇到函数的参数列表之前，begin都是不存在的。为了定义此函数，我们必须使用尾置返回类型。
//由于尾置返回出现在函数参数列表之后，它可以使用函数的参数
template<typename It>
auto fcn(It begin,It end) -> decltype(*begin){
	return *begin;
}
//解引用运算符返回一个左值引用

//使用类型转换的标准库模板类
//有时我们无法直接获得所需要的类型，比如我们希望返回一个元素的值而非引用
//但是所有迭代器操作都不会生成元素，只能生成元素的引用。
//为了获得元素的类型，我们可以使用标准库的类型转换模板。定义在头文件type_traits中。
//我们可以使用remove_reference来获得元素类，该模板有一个模板类型参数和一个名为type的类型成员。
//如果我们用一个引用类型实例化remove_reference，则type将表示被引用的类型。
//如果我们实例化remove_reference<int&>，则type成员将是int。
//remove_reference<decltype(*begin)>::type是begin指向元素的值
//脱去引用，剩下元素类型本身

template<typename It>
auto fcn2(It begin,It end) ->typename remove_reference<decltype(*begin)>::type{
	return *begin;
}

//type是一个类的成员，而该类依赖于一个模板参数，因此，我们必须在返回类型的声明中使用typename来告知编译器，type表示一个类型。
//emove_reference
//add_const
//add_lvalue_reference
//add_rvalue_reference
//remove_pointer

//每个模板都有一个名为type的public成员，表示一个类型。
//如果不可能转换模板参数，则type成员就是模板参数类型本身。

//**************************************************************************************************************
//当我们用一个函数模板初始化一个函数指针或为一个函数指针赋值时，编译器使用指针的类型来推断模板实参。

template<typename T>
int compare(const T &,const T &);
int (*pf)(const int &,const int &) = compare;

//pf中参数类型决定了T的模板实参类型。T的模板实参类型为int。指针pf指向compare的int版本实例。如果不能从函数指针类型确定函数实参，则产生错误。

void func(int(*)(const string & ,const string &));
void func(int(*)(const int &,const int &));
void test41(){
//	func(compare);
//  
}

//通过func的参数类型无法确定模板实参的唯一类型
//我们可以通过使用显式模板实参来消除func
//func(compare<int>);
//此表达式调用的func版本接受一个函数指针，该指针指向的函数接受两个const int &参数
//当参数是一个函数模板实例的地址时，程序上下文必须满足；对每个模板参数，能唯一确定其类型或值



//************************************************************************************************************
//模板实参推断和引用
//从左值引用函数参数推断类型
//当一个函数参数是模板类型参数的一个普通（左值）引用，绑定规定告诉我们，只能传递给它一个左值。
//实参可以是const类型，也可以不是；如果实参是const，则T将被推断为const类型

template<typename T>
void f1(T&){//实参必须为一个左值引用
}

void test46(){
	int i = 2;
	f1(i);
	long lng = 23;
	f1(lng);
//	f1(5);//error 是右值
}


//如果一个函数参数类型是const T&，正常的绑定规则是可以传递给它任何类型的实参（一个对象、临时对象、字面量）
//当函数参数本身是const的时候，T的类型推断结果不会是一个const类型。const已经是函数参数类型的一部分。因此，它不会也是模板参数类型的一部分。
template<typename T>
void f2(const T &){//可以接受一个左值或右值
	
}
void test47(){
	int i = 2;
	f2(i);
	const int  ci = 23;
	f2(ci);
	f2(5);
	//因为T本身就是const的，所以实参中的const是无关的
	//在每个调用中，f2的函数参数都被推断为const int &；其中T都被推断为int
}	


//从右值引用函数参数推断类型
//当一个函数是右值引用类型（T&&），正常绑定规则是可以传递给它一个右值。当我们这样做时，类型推断过程类似于普通左值引用函数参数的推断过程。
//推断出的T的类型是该右值实参的类型
template<typename T>
void f3(T&&){
	
}
//f3(42);//实参类型是int&&，模板参数T为int


//类型推断是根据T和它的修饰符，如& && const，组合起来就是t的类型，所以T就是t的类型的一部分，const T &/&& 才是t的真实类型
//f(T&)  f(i)  T = int  type(i) = T & = int &
//f(T)   f(42) T = int 
//f(T &) f(ci) T = const int type(ci) = T & = const int &

//但是，如果将一个左值引用传给T&&,其实是不可以的，编译器为了支持这种赋值，定义了引用折叠，它的实参推断和上述规则是不同的。
//不是T&& = 参数类型，而是T = 参数类型，然后 “参数类型 &&”再进行引用折叠 
//f(T &&)  f(i)  T = int &  type(i) = T && = int & && = int &
//f(T &&)  f(42) T = int &&  type(42) = T && = int && && = int &&


//*****************************************************************************************************************

//引用折叠和右值引用参数
//如果i是int类型，那么f3(i)是不合法的，因为i是一个左值，而我们通常不能将一个右值引用绑定到左值上。
//但是C++在正常绑定规则之外定义了两个例外规则，允许这种绑定，这两个例外规则是move工作的基础。

//第一个例外是当我们将一个左值传递给函数的右值引用参数，且此右值引用是模板类型参数（T&&）时，编译器推断模板类型参数(!不是函数参数)为实参的左值引用类型。
//因为T被推断为int &,所以T&& 就是 int & && 
//通常我们不能直接定义一个引用的引用，但是通过类型别名或通过模板类型参数间接定义是可以的。
//在此情况下，第二个例外是：如果我们间接创建一个引用的引用，则这些引用形成了折叠。在所有情况下（除一个例外），引用会折叠成一个普通的左值引用类型。
//只有一种情况引用会折叠为右值引用：右值引用的右值引用。
//对于X：
//X &    X& &&   X&& & 都会被折叠成类型X&
//X&& && 会被折叠成X&&

//引用折叠只能引用于间接创建的引用的引用，如类型别名或模板参数

//根据这两个规则，我们可以将任何类型参数传递给f3.当我们将一个左值传递给f3时，编译器推断T为一个左值引用。
//f3(i)  T-> int &
//f3(ci) T-> const int &
//当一个模板参数被推断为引用类型，折叠规则告诉我们函数参数T&&折叠为一个左值引用类型。
//类似于：void f3<int &>(int & &&)
//即使f3的参数形式是一个右值引用，此调用也会用一个左值引用类型实例化f3
//void f3<int &>(int &)
//这两个规则导致了两个重要结果：

//1.如果一个函数参数是一个指向模板类型参数的右值引用，则它可以被绑定到一个左值
//2.并且如果实参时一个左值，则推断出的模板类型实参是一个左值引用，且函数参数将被实例化为一个普通的左值引用参数T&
//可以将任意类型的实参传递给T&&类型的函数参数，对于这种类型的函数，可以传递给它右值，也可以传递给它左值

//编写接受右值引用参数的模板函数
template <typename T>
void f4(T && val){
	T t = val;//拷贝还是绑定引用
	t = fcn(t);//赋值只改变t，还是既改变t又改变val
	if(val == t){
		
	}
}
//当代码中涉及的类型既可能是非引用类型，也可能是引用类型时，编写正确的代码就变得非常困难。
//在实际中右值引用通常用于两种情况：模板转发其实参或模板重载


//***********************************************************************************************************
//理解move
//虽然不能直接将一个右值引用绑定到一个左值上，但可以用move获得一个绑定到左值上的右值引用

//move的定义

template<typename T>
typename remove_reference<T>::type && move(T && t){
	return static_cast<typename remove_reference<T>::type &&>(t);
}
//move的函数参数T&&是一个指向模板类型参数的右值引用。通过引用折叠，此参数可以与任何类型的实参匹配。我们既可以传递给move一个左值，又可以传递给move一个右值

//示例1
//move(string("bye"));
//推断出的T是string类型
//因此，remove_reference使用string进行实例化
//remove_reference<string>的type成员是string
//move的返回类型是string&&
//move的参数类型t的类型是string&&

//实例化move: string&&move(string&& t) 
//类型转换什么都不做，因此调用的结果就是它所接受的右值引用


//示例2
//string s1("bye");
//move(s1);
//推断出的T是string&
//因此，remove_reference使用string&进行实例化
//remove_reference<string&>的成员是string
//move的返回类型仍是string&&
//move的函数参数t实例化为string& && ，会折叠为string&
//实例化string && move(string & t)

//从一个左值static_cast到一个右值引用是允许的


//*********************************************************************************


//转发
//某些函数需要将其一个或多个实参连同类型不变地转发给其他函数。在此情况下，我们需要保持被转发实参的所有性质,包括实参类型是否是const以及实参是左值or右值
template <typename F,typename T1,typename T2>
void flip1(F f,T1 t1,T2 t2){
	f(t2,t1);
}
//当f为一个接受引用参数的函数是会出错
void f(int v1,int & v2){
	cout<<v1<<"  "<<++v2<<endl;
}
//f改变了绑定到v2的实参的值。但是如果通过flip1调用f，f所做的改变就不会影响实参。
//flip(f,j,42)
//问题在于j被传递给t1，这个参数是一个普通类型int，而非int&，j的值拷贝到t1,因此t1的改变不会影响j。
//因此，这个flip1会实例化为
//void flip1(void (*fcn)(int, int &),int t1,int t2);

//定义能保持类型信息的函数参数
//除了希望保持左值or右值属性，还希望保持参数的const属性。
//通过将函数参数定义为一个指向模板类型参数右值引用，我们可以保持其对应实参的所有类型信息。
//而使用引用参数使得我们可以保存const属性，
//因为在引用类型中的const是底层的（const& 常量引用，不可以通过引用修改指向的对象的值；const * 指向常量的指针，不能通过指针改变指向的对象的值）
//如果我们将函数参数定义为T1 && T2 &&，通过引用折叠就可以保持翻转实参的左右值属性。
template<typename F,typename T1,typename T2>
void flip2(F f,T1 && t1,T2 && t2){
	f(t2,t1);
}
//如果一个函数参数是指向模板类型参数的右值引用，它对应的实参的const属性和左右值属性将得到保持。
//这个版本解决了一半问题，它对于接受一个左值引用的函数工作得很好，但不能用于接受右值引用参数的函数。
void g(int && i,int &j){
	cout<<i<<"  "<<j<<endl;
}

//如果通过flip2调用g，那么参数t2将被传递给g的右值引用参数i，即使我们传递给一个右值给flip2
//flip2(g,i,42)//error不能从一个左值实例化int&&
//函数参数与其他任何变量一样，都是左值表达式，虽然t2的类型是右值引用，但是它是一个变量（而非临时变量或表达式），所以是一个左值。
//左值是不能直接绑定到右值引用上的，


//完美转发   std:;forward
//我们可以使用forward这个标准库设施来传递flip2的参数，它能保持原始实参的类型（当时推断出来的类型）
//forward定义在头文件utility中。
//forward必须通过显式模板实参来调用，返回该显示实参的类型的右值引用，即forward<T> 的返回类型是T&&
//通常情况下，我们使用forward传递那些定义为模板类型参数的右值引用的函数参数。通过其返回类型上的引用折叠，forward可以保持给定实参的左右值属性。
template <typename Type> 
void intermediary(Type && args){
	finalFcn(forward<Type>(args));
}

//Type是forward的显式模板实参类型，是从args推断出来的。
//由于args是一个模板类型实参的右值引用，Type将表示传递给args的实参的所有类型信息。
//如果实参是一个右值，那么Type是一个普通类型(Type && = args && --> Type = args的类型)，forward<Type>将返回Type&&
//如果实参是一个左值，则通过引用折叠，Type本身是一个左值 (Type = args & )
//forward<Type>进行引用折叠，返回一个左值引用类型
//!!!!!!!!!!!!!!关键就是forward<Type> 中的Type就是当时推断出的类型，也就是模板实参的类型，没有转换过的。

//示例
template<typename F,typename T1,typename T2>
void flip(F f, T1 && t1,T2 && t2){
	f(forward<T2>(t2),forward<T1>(t1));
}






