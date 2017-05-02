/*
 * 391wordConvert.cpp
 *
 *  Created on: 2016年9月8日
 *      Author: songx
 */

#include <fstream>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
#include <sstream>
using namespace std;

map<string, string> buildMap(const string & fileName) {
	ifstream ifstrm(fileName);
	map<string, string> rules;
	string key, value;
	while (ifstrm >> key && getline(ifstrm, value)) {
		if (value.size() > 1) {
			rules[key] = value.substr(1); //去掉前面的空格
		} else {
			throw runtime_error("no rule for " + key);
		}
	}
	ifstrm.close();
	return rules;
}

const string & transfromAWord(const map<string, string>& rules,
		const string & word) {
	auto it = rules.find(word);
	if (it != rules.end()) {
		return it->second;
	} else {
		return word;
	}
}

void transform(const string & ruleName, const string & text) {
	map<string, string> rules = buildMap(ruleName);
	string line;
	ifstream ifstrm(text);
	bool isFront = true;
	while (getline(ifstrm,line)) {
		istringstream is(line);
		//line存放一行数据，将这一行按空白字符拆开
		string word;
		while (is >> word) {
			//word存放一个单词的数据
			if (isFront) {
				isFront = false;
			} else {
				cout << " ";
			}
			cout << transfromAWord(rules, word);
		}
		isFront = true;
		cout << endl;
	}
	ifstrm.close(); 
}

int main(void) {
	transform("D:/rule.txt", "D:/text.txt");
	return 0;
}

