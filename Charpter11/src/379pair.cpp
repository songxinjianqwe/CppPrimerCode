/*
 * 379pair.cpp
 *
 *  Created on: 2016��9��8��
 *      Author: songx
 */

#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;
//pair��׼������
//������ͷ�ļ�utility
//����������Ա������first��second������public��
//��Ҫ�ṩ������������pair�ĳ�Ա���������ж�Ӧ������
//Ĭ�Ϲ��캯���������ݳ�Ա����ֵ��ʼ��

//������
//pair<T1,T2> p;
//pair<T1,T2> p = {v1,v2};
//pair<T1��T2> p();  {v1,v2};  make_pair(v1,v2)
//�������ַ�ʽ���ܵõ�һ��pair���󣬺����ַ�ʽ���������ɱ������ƶϳ�����
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


