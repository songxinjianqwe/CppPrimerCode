/*
 * 365prac.cpp
 *
 *  Created on: 2016年9月7日
 *      Author: songx
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

using namespace std;

//10.34
void test50(){
	vector<int> iVec = {2,3,4,5,6,7};
	ostream_iterator<int> osIt(cout,"\t");
	copy(iVec.crbegin(),iVec.crend(),osIt);
	cout<<endl;
}
//10.35
//prev算法，返回当前迭代器的前一个位置
void test51(){
	vector<int> iVec = {2,3,4,5,6,7};
	for(auto it = prev(iVec.cend());it != prev(iVec.cbegin());it--){
		cout<<*it<<"\t";
	}
	cout<<endl;
}

//10.36
void test52(){
	list<int> iList = {2,3,4,5,6,0,23,0,2};
	auto itZero = find(iList.crbegin(),iList.crend(),0);
	ostream_iterator<int> osIt(cout,"\t");
	copy(itZero.base(),iList.cend(),osIt);
	cout<<endl;
}
//迭代器可以直接+n
//10.37
void test53(){
	vector<int> iVec = {0,1,2,3,4,5,6,7,8,9};
	vector<int> iVec2;
//	copy(iVec.crbegin()+2,iVec.crbegin()+7,back_inserter(iVec2));
	for(auto it = iVec.crbegin()+2;it != iVec.crbegin()+7;it++){
		iVec2.push_back(*it);
	}
	for(auto i:iVec2){
		cout<<i<<"\t";
	}
	cout<<endl;
}



