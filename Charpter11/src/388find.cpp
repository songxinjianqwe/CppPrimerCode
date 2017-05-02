/*
 * 388find.cpp
 *
 *  Created on: 2016��9��8��
 *      Author: songx
 */

#include <stddef.h>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

//����Ԫ��
//c.find(key) ����һ����������ָ���һ���ؼ���Ϊkey��Ԫ�أ���������ڣ���ô����β�������
//c.count(key( ���عؼ���Ϊkey��Ԫ�ظ��������ڲ������ظ��ؼ��ֵ�����������ֵ��Զ��0��1
//c.lower_bound(key) ����һ����������ָ���һ���ؼ���>=key��Ԫ��
//c.upper_bound(key) ����һ�������������ص�һ���ؼ���>key��Ԫ��
//c.equal_range(key) ����һ��������pair����ʾ�ؼ��ֵ���key�ķ�Χ�����key�����ڣ���ôpair��������Ա��Ϊβ�������

//lower_bound upper_bound����������������
//�±��at���������ڷ�const��map��unordered_map
//����map���ԣ������Ҫ���ң���ô���ʹ��find�������±��������Ϊ�±���ڸ�����

void test17() {
	map<string, size_t> wordCount;
	if (wordCount.find("Anna") == wordCount.end()) {
		cout << "Anna is not in the map" << endl;
	}
}
//����multimap����multiset���ԣ����ұȽϸ���
//��Ҫ����һ����Χ
//��������ʵ�ַ�ʽ
//1��ʹ��find��count����������ͬkey��Ԫ���Ƿ���һ�����ʵ
void test18(multimap<string, string> authors) {
	auto entries = authors.count("Anna");
	for (auto it = authors.find("Anna"); entries != 0; it++, entries--) {
		cout << it->first << "  " << it->second << endl;
	}
}
//2��ʹ��lower_bound��upper_bound
//��������������Ĳ�����ͬ����key����ô���ǿ��Է���һ����Χ�������Χ����key�ķ�Χ
//���û���ҵ�����ô���ǻ᷵����ȵĵ���������ָ������ؼ��ֵĲ���㣬�ܱ���������Ԫ��˳��Ĳ���λ��
void test19(multimap<string, string> authors) {
	for (auto begin = authors.lower_bound("Anna"), end = authors.upper_bound(
			"Anna"); begin != end; begin++) {
		cout << begin->first << "  " << begin->second << endl;
	}
}
//3��ʹ��equal_range��ֱ�ӷ���һ����Χ
void test20(multimap<string, string> authors) {
	for (auto pos = authors.equal_range("Anna"); pos.first != pos.second;
			pos.first++) {
		cout << pos.first->first << "   " << pos.first->second << endl;
	}
}

//11.28
void test21() {
	map<string, vector<int>> sVMap;
	sVMap.insert( { "key", { 2, 34, 5, 6, 7 } });
	auto value = sVMap.find("key");
	for (auto it = value->second.begin(); it != value->second.end(); it++) {
		cout << *it << "\t";
	}
	cout << endl;
}
//11.31
//����һ������ֵ����multimap��ɾ����
//ʹ��find����һ����count�������
void deleteKey(multimap<string, string> &authors, const string &author,	const string & work) {
	auto count = authors.count(author);
	for (auto it = authors.find(author); count != 0; it++, count--) {
		if (it->second == work) {
			authors.erase(it);
			break;
		}
	}
}

//11.32
//����һ��multimap��Ҫ���䰴��key����������ͬkey��ֵ�������
//�Ƚ�key���򣬲��뵽һ��map���ɣ����map��value��һ��multiset������ʵ��value����
void displayInOrder(multimap<string, string> &authors) {
	map<string, multiset<string>> orderedAuthors;
	for (const auto & a : authors) {
		orderedAuthors[a.first].insert(a.second);
	}
	for (const auto & oa : orderedAuthors) {
		cout << oa.first << ":";
		for (const auto & work : oa.second) {
			cout << work << "\t";
		}
		cout << endl;
	}
}

int main(void) {
	multimap<string, string> authors;
	 authors.emplace("Socket", "UDP");
	 authors.emplace("Anna", "Blues");
	 authors.emplace("Anna", "Blues");
	 authors.emplace("Anna", "Blues");
	 authors.emplace("Stream", "IO");
	 test18(authors);
	 cout<<endl;
	 test19(authors);
	 cout<<endl;
	 test20(authors);
	test21();
	
	multimap<string, string> authors;
	authors.insert( { "Knoth", "C++" });
	authors.insert( { "Yikalos", "Index" });
	authors.insert( { "Knoth", "SE" });
	authors.insert( { "Knoth", "C" });
	deleteKey(authors, "Knoth", "C");
	for (const auto & a : authors) {
		cout << a.first << "\t" << a.second << endl;
	}
	displayInOrder(authors);
	return 0;
}
