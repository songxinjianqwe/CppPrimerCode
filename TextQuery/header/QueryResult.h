/*
 * QueryResult.h
 *
 *  Created on: 2016Äê9ÔÂ26ÈÕ
 *      Author: songx
 */

#ifndef QUERYRESULT_H_
#define QUERYRESULT_H_

#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <string>
#include <vector>

using namespace std;

class QueryResult {
	friend ostream& operator<<(ostream &os, const QueryResult & r);
public:
	QueryResult(const string & s, shared_ptr<vector<string>> t,	shared_ptr<set<int>> lines) :
			word(s), text(t), lineNum(lines) {
	}
	set<int>::iterator begin() {
		return lineNum->begin();
	}
	set<int>::iterator end() {
		return lineNum->end();
	}
	shared_ptr<vector<string>> getFile() {
		return text;
	}
private:
	string word;
	shared_ptr<vector<string>> text;
	shared_ptr<set<int>> lineNum;
};

#endif /* QUERYRESULT_H_ */
