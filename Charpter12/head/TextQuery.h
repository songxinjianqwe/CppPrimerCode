/*
 * TextQuery2.cpp
 *
 *  Created on: 2016年9月11日
 *      Author: songx
 */


/*
 * TextQuery.cpp
 *
 *  Created on: 2016年9月10日
 *      Author: songx
 */

#include <stddef.h>
#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <string>
#include <utility>
#include <sstream>
#include <fstream>
#include "StrBlob.h"

using namespace std;
class QueryResult;
class TextQuery {
public:
	TextQuery(ifstream &ifstrm) {
		textPtr = make_shared<StrBlob>();
		string line;
		while (getline(ifstrm, line)) {
			textPtr->push_back(line);
		}
	}

	QueryResult query(string & target);
private:
	shared_ptr<StrBlob> textPtr;
	map<string, shared_ptr<set<int>>> lineNum;
};

class QueryResult {
	friend ostream& printResult(ostream &os, const QueryResult & r);
public:
	QueryResult(const string & s, shared_ptr<StrBlob> t,
			shared_ptr<set<int>> lines) :
			word(s), text(t), lineNum(lines) {
	}
	set<int>::iterator begin(){
		return lineNum->begin();
	}
	set<int>::iterator end(){
		return lineNum->end();
	}
	shared_ptr<StrBlob> getFile(){
		return text;
	}
private:
	string word;
	shared_ptr<StrBlob> text;
	shared_ptr<set<int>> lineNum;
};

ostream & printResult(ostream &os, const QueryResult & r) {
	os << r.word << " occurs " << r.lineNum->size() << " times" << endl;
	for (auto begin = r.lineNum->begin(); begin != r.lineNum->end(); begin++) {
		ConstStrBlobPtr curr(*r.text,*begin);
		os << *begin+1 << ":" <<curr.deref() << endl;
	}
	return os;
}

QueryResult TextQuery::query(string & target) {
	size_t lineCount = 0;
	for(auto begin = textPtr->cbegin();begin != textPtr->cend();begin.inc()){
		istringstream is(begin.deref());
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
	return QueryResult(target, textPtr, lineNum[target]);
}





