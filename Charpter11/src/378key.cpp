/*
 * 378key.cpp
 *
 *  Created on: 2016年9月8日
 *      Author: songx
 */

#include <iostream>
#include <list>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;
//关键字类型的要求
//关键字类型必须重载<运算符，或者提供一个比较函数，其中严格定义了元素之间的大小关系
//如果一个类型定义了行为正常的<运算符，则它可以用作关键字类型
//定义set时，如果关键字没有定义<运算符，而需要提供一个比较函数，那么需要有两个类型参数，一个是关键字类型，一个是函数指针
//并且需要加上构造函数参数-->函数指针
class SalesData{
private:
	string bookNo;
public:
	SalesData(const string &s):bookNo(s){}
	string isbn()const{
		return bookNo;
	}
};
bool compareIsbn(const SalesData &s1,const SalesData &s2) {
	return s1.isbn() < s2.isbn();
}

void test5() {
//	set<SalesData,decltype(compareIsbn) *> bookstore(compareIsbn);//函数名即表示函数的指针，当然加上&也可以
	set<SalesData,bool(*)(const SalesData&,const SalesData&)> bookstore(compareIsbn);
	bookstore.insert(SalesData("000-123-000"));
	bookstore.insert(SalesData("000-123-001"));
	for(const auto & s:bookstore){
		cout<<s.isbn()<<"\t";
	}
	cout<<endl;
}

void test6(){
	map<string,list<int>> wordLines;
	map<vector<int>::iterator,int> m1;
	map<list<int>::iterator,int> m2;
	//使用时会出问题，没有定义<运算符
}
