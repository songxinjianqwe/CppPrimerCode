/*
 * 378key.cpp
 *
 *  Created on: 2016��9��8��
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
//�ؼ������͵�Ҫ��
//�ؼ������ͱ�������<������������ṩһ���ȽϺ����������ϸ�����Ԫ��֮��Ĵ�С��ϵ
//���һ�����Ͷ�������Ϊ������<��������������������ؼ�������
//����setʱ������ؼ���û�ж���<�����������Ҫ�ṩһ���ȽϺ�������ô��Ҫ���������Ͳ�����һ���ǹؼ������ͣ�һ���Ǻ���ָ��
//������Ҫ���Ϲ��캯������-->����ָ��
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
//	set<SalesData,decltype(compareIsbn) *> bookstore(compareIsbn);//����������ʾ������ָ�룬��Ȼ����&Ҳ����
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
	//ʹ��ʱ������⣬û�ж���<�����
}
