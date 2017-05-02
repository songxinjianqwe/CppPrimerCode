#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>


using namespace std;

//函数在灵活性上不足，为了弥补这一点，引入lambda
//之前的函数写死了比多少个字符大的条件，如果我们想将这个字符个数作为参数传入，是不可行的。
//lambda可以做到这一点

//可调用对象：对于任何一个表达式，如果可以对其使用调用运算符（），则称其为可调用的。
//共有四种可调用对象：函数、函数指针、重载了函数调用运算符的类、lambda表达式

//一个lambda表达式表示一个可调用的代码单元。我们可以将其理解为一个未命名的内联函数。
//一个lambda表达式具有一个返回类型，一个参数列表，一个函数体，表达式没有名字，可以定义在函数中。
//格式：[capture list](parameter list)->return type {body}
//捕获列表是一个lambda所在函数中定义的局部变量的列表，可以为空
//其中参数列表和返回类型是可以忽略的，但捕获列表和函数体是不可忽O略的
//如果忽略返回类型，lambda会根据函数体中的代码推断出返回类型，如果lambda的函数体包含任何单一return语句之外的内容，且未指定返回类型，则返回void

//向lambda传参
//实参和形参类型必须匹配，并且不能有默认参数
//空捕获列表表示此lambda表达式不适用它所在函数体中的任何局部变量

//使用捕获列表
//一个lambda通过将局部变量包含在其捕获列表中来指出将会使用这些变量，捕获列表指引lambda在其内部包含访问局部变量所需的信息
//lambda可以直接使用局部静态变量和在它所在函数之外声明的函数
extern void deDuplication(vector<string> & sVec);

void test15() {
	auto f = [] {return 42;};
	//定义了一个可调用对象f，可以使用调用运算符来调用
	cout << f() << endl;
	vector<string> sVec = { "the", "quick", "red", "fox", "jumps", "over",
			"the", "slow", "red", "turtle" };
	deDuplication(sVec);
	stable_sort(sVec.begin(), sVec.end(),
			[](const string & s1,const string &s2) {return s1.size() < s2.size();});
	for (const auto & s : sVec) {
		cout << s << "\t";
	}
}

//find_if算法
//接受三个参数，前两个表示范围，第三个是一个一元谓词，对 序列中的每个元素调用给定的这个谓词，它返回第一个使谓词返回非0值的元素，如果不存在，那么返回尾后迭代器（第二个参数）
//for_each算法
//接受三个参数，前两个表示范围，第三个是一个一元谓词，对序列中的每个元素都调用此谓词
//
//输出字符串容器中大于给定长度的字符串，这个长度由我们动态指定
//先将容器按长度排序，然后找到第一个长度大于给定值的迭代器，从此处到末尾的元素都是长度大于给定值的元素，最后for_each算法输出
void test16(string::size_type sz) {
	vector<string> sVec = { "the", "quick", "red", "fox", "jumps", "over",
			"the", "slow", "red", "turtle" };
	deDuplication(sVec);//去重
	//按长度排序
	stable_sort(sVec.begin(),sVec.end(),[](const string &s1,const string &s2){return s1.size()<s2.size();});
	auto start = find_if(sVec.begin(), sVec.end(),
			[sz](const string & str) {return str.size() > sz;});
	for_each(start,sVec.end(),[](const string & s){cout<<s<<"\t";});
	cout<<endl;
}
