/*
 * QueryResult.cpp
 *
 *  Created on: 2016��9��26��
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

