/*
 * 376intro.cpp
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
//关联容器支持以下操作：
//C c  C c(c1) 构造
//C c(begin,end)
//C c = {};
//赋值swap  c1 = c2  c1.swap(c2)
//大小 c.size()  c.empty()
//迭代器 begin、end rbegin、rend
//insert、emplace、erase等插入删除操作

void test3() {
	map<string, string> authors = { 
			{ "Joyce", "James" }, 
			{ "Austen", "Jane" },
			{ "Dickens", "Charles"} 
	};
	set<string> exclude = {"the","but","and"};
	//初始化map的时候，一个键值对要用一个花括号括起来
	map<string,vector<string>> family;
	family["Song"].push_back("S");
	family["Song"].push_back("R");
	for(const auto & e:family){
		cout<<e.first<<endl;
		for(const auto & child:e.second){
			cout<<child<<"\t";
		}
		cout<<endl;
	}
}
//11.8
//用vector模拟set
void test4(){
	vector<int> iVec;
	int i = 0;
	while(cin >> i){
		if(find(iVec.begin(),iVec.end(),i) == iVec.end()){
			iVec.push_back(i);
		}
	}
	ostream_iterator<int> osIt(cout,"\t");
	copy(iVec.cbegin(),iVec.cend(),osIt);
	cout<<endl;
}


