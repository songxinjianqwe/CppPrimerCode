/*
 * 638ReturnWithTuple.cpp
 *
 *  Created on: 2016年10月1日
 *      Author: songx
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

//使用tuple返回多个值
//tuple一个常见用途就是从函数返回多个值
class SalesData;
class SalesData {
	friend ostream & operator<<(ostream & os,const SalesData & sd);
	friend bool compareIsbn(const SalesData & lhs,const SalesData & rhs);
public:
	SalesData(const string &book):SalesData(book,0,0){}
	SalesData(const string & book,unsigned units,double  rev):bookNo(book),unitsSold(units),revenue(rev){}
private:
	string bookNo;
	unsigned unitsSold;
	double revenue;
};
bool compareIsbn(const SalesData & lhs,const SalesData & rhs){
	return lhs.bookNo < rhs.bookNo;
}
ostream & operator<<(ostream & os,const SalesData & sd){
	os<<sd.bookNo<<"\t"<<sd.revenue<<"\t"<<sd.unitsSold;
	return os;
}
using matches = tuple<vector<SalesData>::size_type,vector<SalesData>::const_iterator,vector<SalesData>::const_iterator>;
//封装了一个书店的索引，以及给定书籍在该家书店的元素范围

vector<matches> findBook(const vector<vector<SalesData>> & files,const SalesData & book){
	vector<matches> ret;
	for(auto it = files.cbegin(); it != files.cend();++it){
		auto found = equal_range(it->cbegin(),it->cend(),book,compareIsbn);
		if(found.first != found.second){
			ret.push_back(make_tuple(it-files.cbegin(),found.first,found.second));
		}
	}
	return ret;
}
void test(){
	vector<SalesData> sdVec1;
	sdVec1.push_back(SalesData("01",23,20));
	sdVec1.push_back(SalesData("02",22,20));
	vector<SalesData> sdVec2;
	sdVec2.push_back(SalesData("01",23,20));
	sdVec2.push_back(SalesData("02",22,20));
	vector<vector<SalesData>> vec;
	vec.push_back(sdVec1);
	vec.push_back(sdVec2);
	
	auto result = findBook(vec,SalesData("01"));
	for(const auto & store:result){
		cout<<get<0>(store)<<endl;
		for(auto it = get<1>(store);it != get<2>(store);++it){
			cout<<*it<<endl;
		}
		cout<<endl;
	}
}

