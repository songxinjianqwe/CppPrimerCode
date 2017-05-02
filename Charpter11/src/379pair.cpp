/*
 * 379pair.cpp
 *
 *  Created on: 2016年9月8日
 *      Author: songx
 */

#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;
//pair标准库类型
//定义在头文件utility
//保存两个成员变量，first和second，都是public的
//需要提供两个类型名，pair的成员变量将具有对应的类型
//默认构造函数将对数据成员进行值初始化

//操作：
//pair<T1,T2> p;
//pair<T1,T2> p = {v1,v2};
//pair<T1，T2> p();  {v1,v2};  make_pair(v1,v2)
//以上三种方式都能得到一个pair对象，后两种方式的类型是由编译器推断出来的
void test7(){
	pair<string,string> author = {"James","Joice"};
}

pair<string,int> process(vector<string> & sVec){
	if(!sVec.empty()){
//		return {sVec.back(),sVec.size()};
		return make_pair(sVec.back(),sVec.size());
	}else{
		return pair<string,int>();
	}
}
//11.12
void test8(){
	vector<pair<string,int>> pVec;
	int i;
	string s;
	while(cin >>s>>i){
//		pVec.push_back(make_pair(s,i));
//		pVec.push_back(pair<string,int>(s,i));
		pVec.push_back({s,i});
	}
	for(const auto & p:pVec){
		cout<<p.first<<"\t"<<p.second<<endl;
	}
}


