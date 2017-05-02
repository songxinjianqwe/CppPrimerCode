/*
 * TextQuery.cpp
 *
 *  Created on: 2016Äê9ÔÂ10ÈÕ
 *      Author: songx
 */

#include <stddef.h>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <string>
#include <utility>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;
class QueryResult2;
class TextQuery {
public:
	TextQuery(ifstream &ifstrm) {
		textPtr = make_shared<vector<string>>();
		string line;
		while (getline(ifstrm, line)) {
			textPtr->push_back(line);
		}
	}

	QueryResult2 query(string & target);
private:
	shared_ptr<vector<string>> textPtr;
	map<string, shared_ptr<set<int>>> lineNum;
};

class QueryResult2 {
	friend ostream& print(ostream &os, const QueryResult2 & r);
public:
	QueryResult2(const string & s, shared_ptr<vector<string>> t,
			shared_ptr<set<int>> lines) :
			word(s), text(t), lineNum(lines) {
	}
private:
	string word;
	shared_ptr<vector<string>> text;
	shared_ptr<set<int>> lineNum;
};

ostream & print(ostream &os, const QueryResult2 & r) {
	os << r.word << " occurs " << r.lineNum->size() << " times" << endl;
	for (auto begin = r.lineNum->begin(); begin != r.lineNum->end(); begin++) {
		os << *begin+1 << ":" << (*r.text)[*begin] << endl;
	}
	return os;
}

QueryResult2 TextQuery::query(string & target) {
	size_t lineCount = 0;
	for (const auto & line : *textPtr) {
		istringstream is(line);
		string word;
		while (is >> word) {
			if (word == target) {
				auto & lineSet = lineNum[word];
				if (!lineSet) {
					lineSet = make_shared<set<int>>();
				}
				lineSet->insert(lineCount);
			}
		}
		lineCount++;
	}
	return QueryResult2(target, textPtr, lineNum[target]);
}


void runQuery(ifstream & ifstrm) {
	TextQuery tq(ifstrm);
	cout << "Enter word to look for:";
	string word;
	while (cin >> word) {
		print(cout, tq.query(word))<<endl;
		cout << "Enter word to look for:";
	}
}

int main(void){
	ifstream ifstrm("D:/text.txt");
	runQuery(ifstrm);
	ifstrm.close();
	return 0;
}
