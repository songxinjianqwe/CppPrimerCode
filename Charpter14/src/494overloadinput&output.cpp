/*
 * 494overloadinput&output.cpp
 *
 *  Created on: 2016年9月15日
 *      Author: songx
 */

#include <iostream>
#include <string>

#include "../header/StrBlob.h"
#include "../header/StrBlobPtr.h"
#include "../header/StrBlobPtrPtr.h"


//重载输出运算符<<
//第一个参数是一个非常量ostream的引用，第二个参数是一个常亮的引用，希望避免复制实参，并且不修改这个实参
//输出运算符应该尽量减少格式化操作
//输入输出运算符都不是成员函数，而且一般声明为友元函数

//重载输入运算符>>
//第一个参数是一个非常亮的istream的引用，第二个参数是将要读到的对象的引用，注意不是常量，因为会改变这个对象。该运算符会返回某个给定流的引用。
//注意输入运算符应该检查读取是否成功，如果不成功，需要将对象置为默认初始化的状态。
//输入运算符必须处理输入可能失败的情况，而输出运算符不需要
//通过将对象置为合法的状态，我们能保护使用者免于收到错误输入的影响。此时的对象处于可用状态，即它的成员都是被正确定义的。而且该对象也不会产生误导性的结果，因为它的数据在本质上是一体的。
//另外，如果发生错误，需要IO库来标示这些错误。

//算术和关系运算符
//一般定义为非成员函数，形参都是常量的引用
//算术运算符会计算它的两个运算对象得到一个新值，常常位于一个局部变量中，操作完成后返回该局部变量的副本作为其结果
//如果类同时定义的算术运算符和相关的复合赋值运算符，则通常情况下应该使用复合赋值来实现算术运算符（减少拷贝次数）

//相等运算符
//它们对比较对象的每一个数据成员，只有当所有对应的数据成员都相等时才认为两个对象相等，
//如果类定义了==运算符，则这个类也应该定义！=运算符
//相等运算符和不等运算符中的一个应该把工作委托给另外一个，这意味着其中一个运算符应该负责实际比较对象工作，而另一个运算符则只是调用那么真正工作的运算符。

//关系运算符
//关联容器和一些算法要用到小于运算符所以定义operator<比较有用
//关系运算符应该满足：
//1.定义顺序关系，使其与关联容器中对关键字的要求一致
//2.如果类同时含有==运算符的话，则定义一种关系令其与==保持一致；如果两个对象！=，那么一个对象应该<另外一个

//如果要满足上述条件，需要所有的属性都参与比较，只有部分属性参与比较不能满足条件2
//如果存在唯一一种逻辑可靠的<定义，则应该考虑为这个类定义<运算符。如果类同时还包括==，则当且仅当<的定义和==定义产生的结果一致时才定义<运算符


//赋值运算符
//除了拷贝赋值运算符和移动赋值运算符，还有一种用初始化列表的赋值运算符
//如：vector<int> v = {2,1,3};
//赋值运算符都需要返回左侧运算对象的引用
//赋值运算符应该尽量定义为成员函数


//下标运算符
//表示容器的类通常可以通过元素在容器中的位置访问元素，这些类一般会定义下标运算符[]
//下标运算符通常以所访问元素的引用作为返回值
//同时定义下标运算符的常量版本和非常量版本，常量版本的函数声明为const，并且返回的是常量引用（2处const）
//如果一个类包含下标运算符，那么它通常会定义两个版本：一个返回普通引用，另一个是类的常量成员并且返回常量引用
//参数通常是size_t 类型

//递增递减运算符
//改变对象本身状态，应该设置为成员函数
//定义递增递减运算符应该同时定义前置版本和后置版本。这些运算符通常应该被定义为类的成员.
//前置运算符应该返回递增或递减后对象的引用
//并且需要check一下

//为了区别前置和后置版本，后置版本接受一个额外的int类型的形参(可以不为其命名)。当我们使用后置运算符时，编译器为这个形参提供一个值为0的实参。
//尽管从语法上说后置运算符可以使用这个额外的形参，但实际上不会使用。
//后置运算符应该返回对象在递增递减之前的值，返回的形式是一个值
//调用后置运算符不需要check


//解引用运算符和成员访问运算符
//在迭代器类和智能指针类中常用到解引用运算符和箭头运算符
//解引用运算符检查当前指针是否有效，如果是，那么返回对象的一个引用
//箭头运算符不执行自己的操作，而是调用解引用运算符病返回解引用结果元素的地址（相当于返回一个内置的指针）
//箭头运算符必须是类的成员，解引用运算符通常也是类的成员

//这两个运算符一般都是const的，因为获取一个元素并不会改变对象的状态。同时它们的返回值是容器的元素的引用或指针，
//因为非const的智能指针类，只能绑定到非const的类

//对箭头运算符返回值的限定：
//箭头运算符一定会获取成员！可以改变的是头哪个对象中获取成员
//对于形如point->mem，point必须是指向类对象的指针或者一个重载了->运算符的类的对象
//如果point是内置的指针，那么point-mem 相当于 (*point).mem
//如果point是类的一个对象，那么->调用的是重载的->运算符，相当于(p.operator->())->mem，括号内的实际上返回的就是对象的内置指针

//1.如果point是内置指针，那么我们使用内置的箭头运算符。如果point所指向的类没有mem成员，程序会发生错误
//2.如果point是重载了->运算符的类的对象，那么使用point.operator->()的结果来获取mem。如果该结果是一个指针，那么执行第一步。
//如果结果本身含有重载的->运算符，那么重复调用第二步。最终，当这一过程结束时，程序或者返回了所需的内容，或者返回一些表示程序错误的信息
//当point不是指针的时候，编译器会不停的调用point的operator->()直到他变成一个指针，然后才调用->mem获得其成员。


//重载的箭头运算符必须返回类的指针或者自定义了箭头运算符的某个类的对象

void test20(){
	StrBlob sb;
	StrBlobPtr pSB(sb);
	StrBlobPtrPtr ppSB(&pSB);
	ppSB.operator ->()->operator ->()->push_back('A');
	//ppSB.operator->() 相当于 ppSB-> 返回的是StrBlobPtr的指针->，可以直接访问StrBlobPtr的成员
	//ppSB->operator ->() 返回的StrBlob的指针,ppSB->operator ->()->可以直接访问StrBlob的成员
}

//函数调用运算符
//对象可以像函数一样来使用
//函数调用运算符必须是成员函数。一个类可以定义多个不同版本的调用运算符，相互之间应该在参数数量或类型上有所区别
//如果类定义了调用运算符，那么该类的对象称为函数对象

//函数对象常常作为泛型算法的实参

class Abs{
public:
	int operator()(int val)const{
		return val > 0 ? val:-val;
	}
	double operator()(double val) const{
		return val > 0 ? val:-val;
	}
};

void test30(){
	Abs abs;
	cout<<abs(-23)<<endl;
	cout<<abs(23.22)<<endl;
}

class PrintString{
public:
	PrintString(ostream & o = cout,char s = ' '):os(o),sep(s){}
	void operator()(const string & s)const{
		os<<s<<sep;
	}
private:
	ostream & os;
	char sep;
};

class InputString{
public:
	InputString(istream & i = cin):is(i){}
	string  operator()()const{
		string s;
		if(getline(is,s)){
			return s;
		}else{
			return "";
		}
	}
private:
	istream & is;
};

class FuncObj{
public:
	int operator()(int i1,int i2,int i3){
		if(i1){
			return i2;
		}else{
			return i3;
		}
	}
};

class IsEqual{
public:
	IsEqual(const string & v):val(v){}
	bool operator()(const string & s){
		return s == val;
	}
private:
	string val;
};


int main(void){
	test30();
	PrintString printStream(cout,'\t');
	printStream("HelloWorld");
	printStream("HelloWorld");
	cout<<endl;
	InputString inputString(cin);
	vector<string> sVec;
	for(int i = 0; i != 6; ++i){
		sVec.push_back(inputString());
	}
	//用于标准库算法
	for_each(sVec.begin(),sVec.end(),PrintString(cout,'\n'));
	
	replace_if(sVec.begin(),sVec.end(),IsEqual("Ha"),"NEW_VALUE");
	for_each(sVec.begin(),sVec.end(),PrintString(cout,'\n'));
	return 0;
}



//其实lambda表达式就类似于重载函数调用运算符











