/*
 * 374associativecontainer.cpp
 *
 *  Created on: 2016��9��7��
 *      Author: songx
 */

#include <cctype>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <algorithm>

using namespace std;
//��������
//set��map
//��������ظ��ؼ��֣���ǰ�����multi
//�����������ǰ�����unordered
//map��multimap������ͷ�ļ�map��
//set��multiset������ͷ�ļ�set��
//��������������ͷ�ļ�unordered_map(unordered_map,unordered_multimap)��unordered_set(unordered_set,unordered_multiset)

//��������Ҳ��ģ�壬��Ҫָ�����Ͳ���
//map����pair��ɵģ�pair��һ��ģ�����ͣ�����������Ϊfirst��second�ĳ�Ա����
//map��ʹ�õ�pair��first����key����second����value

void test1() {
	map<string, string::size_type> wordCount;
	set<string> exclude = { "The", "But", "And", "Or", "An", "A", "the", "but",
			"and", "or", "an", "a" };
	string word;
	while (cin >> word) {
		if (exclude.find(word) == exclude.end()) {
			wordCount[word]++;
		}
	}
	for (const auto & w : wordCount) {
		cout << w.first << "  " << w.second << endl;
	}
}
void test2() {
	map<string, string::size_type> wordCount;
	string word;
	while (cin >> word) {
		for (auto & ch : word) {
			ch = tolower(ch);
		}
		//����remove_if()�Ƴ�����[start, end)������Ӧ����ν��p����true��Ԫ��.
		//�˺�������һ��ָ���޼������е����һ��Ԫ�ص�����.
		//remove_if()������ʵ���Ƴ�����[start, end)�е�Ԫ��; �����һ��������Ӧ��remove_if(), �����ĳ��Ȳ�����ı�
		//(remove_if()�����ܽ�ͨ���������ı�����������), ���е�Ԫ�ض�������������.
		//ʵ��������, remove_if()������Ӧ���Ƴ���Ԫ�ض��ƶ���������β��������һ���ֽ�ĵ�����. �Ƴ�������Ԫ����Ȼ����ͨ�����صĵ��������ʵ�.
		//Ϊ��ʵ���Ƴ�Ԫ��, �������������е���erase()�Բ�����Ҫ�Ƴ���Ԫ��.
//		auto punctStart = remove_if(word.begin(), word.end(), ispunct);
//		word.erase(punctStart, word.end());
		wordCount[word]++;
	}
	for (const auto & w : wordCount) {
		cout << w.first << "  " << w.second << endl;
	}
}

