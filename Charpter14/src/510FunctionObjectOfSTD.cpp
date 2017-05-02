/*
 * 510标准库定义的函数对象.cpp
 *
 *  Created on: 2016年9月17日
 *      Author: songx
 */

#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;
using namespace placeholders;


//标准库定义了一组表示算术运算符、关系运算符和逻辑运算符的类，每个类分别定义了一个执行命名操作的调用运算符
//plus类定义了一个函数调用运算符用于对一对调用对象执行加法操作
//这些类被定义为模板类型，可以为其制定具体的类型，这里的类型就是调用运算符的形参类型
//plus<string> 令string加法运算符作用于string对象
//定义在functional头文件中
//完整：
//plus minus multiplies divides modulus negate
//equal_to not_equal_to greater greater_equal less less_equal
//logical_and logical_or logical_not


void test40(){
	plus<int> intAdd;
	negate<int> intNegate;
	int sum = intAdd(3,5);
	sum = intNegate(2);
	cout<<sum<<endl;
	//在标准库算法中使用标准库函数对象
	vector<string> sVec = {"a","b","c"};
	sort(sVec.begin(),sVec.end(),greater<string>());
	//创建了一个临时的greater对象，替代了string的<运算符，类似于java的comparator
	
	//对于存储的是指针对象而言，使用<运算符会比较指针值，而我们希望的是比较指针所指向的值
	//标准库的函数对象是定义良好的，它会比较指针所指向的值
	//使用functionObject<key_type>排序
	vector<string *> nameTable;
//	sort(nameTable.begin(),nameTable.end(),[](string *a,string *b){return a<b;});//error
	//目的不是比较指针
	sort(nameTable.begin(),nameTable.end(),less<string *>());
	
}

void prac1(){
	vector<int> iVec = {2048,2047,12023,232,12334,12};
	cout<<count_if(iVec.begin(),iVec.end(),bind(greater<int>(),_1,1024))<<endl;
}
void prac2(){
	vector<string> sVec = {"pooh","pooh","hole"};
	auto begin = find_if(sVec.begin(),sVec.end(),bind(not_equal_to<string>(),_1,"pooh"));
	cout<<*begin<<endl;
}
void prac3(){
	vector<int> iVec = {23,4,2321,23,23,2321,123,42};
	transform(iVec.begin(),iVec.end(),iVec.begin(),bind(multiplies<int>(),_1,2));
	copy(iVec.begin(),iVec.end(),ostream_iterator<int>(cout,"\t"));
	cout<<endl;
}
bool canDividedExactly(int val,const vector<int> & iVec){
//	return !accumulate(iVec.begin(),iVec.end(),3,modulus<int>());
	modulus<int> mod;
	return any_of(iVec.begin(),iVec.end(),[&](int i){return 0 == mod(val,i);});
}


int main(void){
	vector<int> iVec = {3,6,9,12};
	cout<<canDividedExactly(3,iVec)<<endl;
}




