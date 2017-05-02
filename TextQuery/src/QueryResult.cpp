/*
 * QueryResult.cpp
 *
 *  Created on: 2016Äê9ÔÂ26ÈÕ
 *      Author: songx
 */

#include "../header/QueryResult.h"

#include <map>

ostream & operator<<(ostream &os, const QueryResult & r) {
	os << r.word << " occurs " << r.lineNum->size() << " times" << endl;
	for (auto begin = r.lineNum->begin(); begin != r.lineNum->end(); begin++) {
		os << *begin+1 << ":" <<(*r.text)[*begin] << endl;
	}
	return os;
}

