/*
 * WordQuery.h
 *
 *  Created on: 2016Äê9ÔÂ26ÈÕ
 *      Author: songx
 */

#ifndef WORDQUERY_H_
#define WORDQUERY_H_

#include <string>

#include "QueryBase.h"
#include "QueryResult.h"
#include "TextQuery.h"

class WordQuery: public QueryBase {
	friend class Query;
private:
	WordQuery(const string & s) :
			queryWord(s) {
	}
	QueryResult eval(TextQuery &tq) const {
		return tq.query(queryWord);
	}
	string rep() const {
		return queryWord;
	}
	string queryWord;
};

#endif /* WORDQUERY_H_ */
