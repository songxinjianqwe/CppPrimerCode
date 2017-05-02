/*
 * TextQuery.h
 *
 *  Created on: 2016Äê9ÔÂ26ÈÕ
 *      Author: songx
 */

#ifndef TEXTQUERY_H_
#define TEXTQUERY_H_

#include <stddef.h>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <string>
#include <utility>
#include <vector>
#include "QueryResult.h"
#include <fstream>
#include <sstream>
using namespace std;
class QueryResult;


class TextQuery {
public:
	TextQuery(ifstream &ifstrm) {
		textPtr = make_shared<vector<string>>();
		string line;
		while (getline(ifstrm, line)) {
			textPtr->push_back(line);
		}
	}

	QueryResult query(const string & target);
private:
	shared_ptr<vector<string>> textPtr;
	map<string, shared_ptr<set<int>>> lineNum;
};





#endif /* TEXTQUERY_H_ */
