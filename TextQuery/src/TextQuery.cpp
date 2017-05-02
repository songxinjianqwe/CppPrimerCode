/*
 * TextQuery.cpp
 *
 *  Created on: 2016Äê9ÔÂ26ÈÕ
 *      Author: songx
 */

#include "../header/TextQuery.h"

#include <iterator>




QueryResult TextQuery::query(const string & target) {
	size_t lineCount = 0;
	for(auto begin = textPtr->begin();begin != textPtr->end();begin++){
		istringstream is(*begin);
		string word;
		while (is >> word) {
			if (word == target) {
				auto & lineSet = lineNum[target];
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

