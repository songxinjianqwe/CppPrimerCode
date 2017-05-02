/*
 * 376intro.cpp
 *
 *  Created on: 2016��9��8��
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
//��������֧�����²�����
//C c  C c(c1) ����
//C c(begin,end)
//C c = {};
//��ֵswap  c1 = c2  c1.swap(c2)
//��С c.size()  c.empty()
//������ begin��end rbegin��rend
//insert��emplace��erase�Ȳ���ɾ������

void test3() {
	map<string, string> authors = { 
			{ "Joyce", "James" }, 
			{ "Austen", "Jane" },
			{ "Dickens", "Charles"} 
	};
	set<string> exclude = {"the","but","and"};
	//��ʼ��map��ʱ��һ����ֵ��Ҫ��һ��������������
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
//��vectorģ��set
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


