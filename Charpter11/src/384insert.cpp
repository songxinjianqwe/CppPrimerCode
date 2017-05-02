/*
 * 384insert.cpp
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

//����������insert������
//c.insert(val)
//c.emplace(args)
//c.insert(begin,end)
//c.insert({.....})
//c.insert(p,val)
//c.insert(p,args)
//�������������ʾ������pָ���˴����￪ʼ������Ԫ��Ӧ�ô洢��λ�ã�����һ����������ָ����и����ؼ��ֵ�Ԫ��
//����set
void test11(){
	vector<int> iVec = {8,7,6,5,4,3,2};
	set<int> iSet;
	iSet.insert(iVec.begin(),iVec.end());
	iSet.insert({9,10,11,12});
	ostream_iterator<int> osIt(cout,"\t");
	copy(iSet.cbegin(),iSet.cend(),osIt);
	cout<<endl;
}
//����map
void test12(){
	map<string,int> wordCount;
	wordCount.insert({"my",1});
	wordCount.insert(make_pair("me",1));
	for(const auto & w:wordCount){
		cout<<w.first<<":"<<w.second<<endl;
	}
}

//insert �ķ���ֵ
//���ڲ������ظ�Ԫ�ص�������inset��emplace����һ��pair��first��Ա��һ����������ָ����и����ؼ��ֵ�Ԫ�أ�second��Ա��һ��boolֵ��ָ��Ԫ���ǲ���ɹ������Ѿ�������������
void test13(){
	map<string,size_t> wordCount;
	string word;
	while(cin>>word){
//		auto ret = wordCount.insert({word,1});
//		if(!ret.second){
//			ret.first->second++;//ret��first��Ա��ָ��word�ĵ������������õ������õ���pair��second��Ա
//		}
		//����һ��д����
		wordCount.insert({word,0}).first->second++;
		//����ɹ�����ôfirst��ָ���������Ԫ�صĵ������������value��һ
		//���ʧ�ܣ���ô�Լ�һ
	}
	for(auto it = wordCount.cbegin();it!= wordCount.cend();it++){
		cout<<it->first<<"\t"<<it->second<<endl;
	}
}
//��map�в���Ԫ�ػ���һ�ַ�ʽ��ʹ���±꣬�����Ϊ�±��key�����ڣ���ô�������key��value����map[key]
//��������ʹ���±�汾���£�
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




