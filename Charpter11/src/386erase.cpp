/*
 * 386erase.cpp
 *
 *  Created on: 2016��9��8��
 *      Author: songx
 */

#include <stddef.h>
#include <iostream>
#include <map>
#include <string>
#include <utility>

using namespace std;

//ɾ��Ԫ��
//�������汾��erase
//��һ���汾�Ǹ���һ����������ɾ���õ�����ָ���Ԫ��
//�ڶ����汾�Ǹ���������������ɾ������֮���Ԫ��
//�������汾�ǽ���һ��key��ɾ�����ж�Ӧ��key��value������ɾ����Ԫ�ظ���


void test15(){
	map<string,size_t> wordCount;
	wordCount.emplace("word",1);
	cout<<wordCount.erase("word")<<endl;
	for(const auto &w:wordCount){
		cout<<w.first<<"  "<<w.second<<endl;
	}
}

//map���±����
//map��unordered_map�����ṩ���±��������һ����Ӧ��at����
//set��֧���±꣬multimap��unordered_multimapҲ��֧���±꣨һ�Զࣩ
//c[key] ���عؼ���Ϊkey��value�����k����c�У���ô���һ���ؼ���Ϊkey��Ԫ�أ����������ֵ��ʼ��
//c.at(key) ���ʹؼ���Ϊkey��Ԫ�أ���������飬���key����c�У���ô�׳�out_of_range�쳣

//����һ��map�����±����ʱ����õ�һ��value���󣻵�������һ��map�ĵ�����ʱ������һ��pair
//map���±�������ص���һ����ֵ�����Լȿɶ��ֿ�д
void test16(){
	map<string,size_t> wordCount;
	wordCount["Anna"] = 1;
	cout<<wordCount["Anna"]<<endl;
	wordCount["Anna"]++;
	cout<<wordCount["Anna"]<<endl;
}


