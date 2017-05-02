/*
 * 384insert.cpp
 *
 *  Created on: 2016年9月8日
 *      Author: songx
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

//关联容器的insert操作：
//c.insert(val)
//c.emplace(args)
//c.insert(begin,end)
//c.insert({.....})
//c.insert(p,val)
//c.insert(p,args)
//最后两个函数表示迭代器p指出了从哪里开始搜索新元素应该存储的位置，返回一个迭代器，指向具有给定关键字的元素
//对于set
void test11(){
	vector<int> iVec = {8,7,6,5,4,3,2};
	set<int> iSet;
	iSet.insert(iVec.begin(),iVec.end());
	iSet.insert({9,10,11,12});
	ostream_iterator<int> osIt(cout,"\t");
	copy(iSet.cbegin(),iSet.cend(),osIt);
	cout<<endl;
}
//对于map
void test12(){
	map<string,int> wordCount;
	wordCount.insert({"my",1});
	wordCount.insert(make_pair("me",1));
	for(const auto & w:wordCount){
		cout<<w.first<<":"<<w.second<<endl;
	}
}

//insert 的返回值
//对于不包含重复元素的容器，inset和emplace返回一个pair，first成员是一个迭代器，指向具有给定关键字的元素；second成员是一个bool值，指出元素是插入成功还是已经存在在容器中
void test13(){
	map<string,size_t> wordCount;
	string word;
	while(cin>>word){
//		auto ret = wordCount.insert({word,1});
//		if(!ret.second){
//			ret.first->second++;//ret的first成员是指向word的迭代器，解引用迭代器得到该pair的second成员
//		}
		//还有一种写法是
		wordCount.insert({word,0}).first->second++;
		//如果成功，那么first是指向插入的这个元素的迭代器，将其的value加一
		//如果失败，那么仍加一
	}
	for(auto it = wordCount.cbegin();it!= wordCount.cend();it++){
		cout<<it->first<<"\t"<<it->second<<endl;
	}
}
//向map中插入元素还有一种方式是使用下标，如果作为下标的key不存在，那么插入这个key，value就是map[key]
//这个程序的使用下标版本如下：
void test14(){
	map<string,size_t> wordCount;
	string word;
	while(cin>>word){
		wordCount[word]++;
	}
	for(auto it = wordCount.cbegin();it!= wordCount.cend();it++){
		cout<<it->first<<"\t"<<it->second<<endl;
	}
}
//11.22
//pair<map<string,vector<int>>::iterator,bool> myInsert(map<string,vector<int>> &sVMap,pair<string,vector<int>> p){
//	
//}




