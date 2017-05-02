/*
 * StrBlob.cpp
 *
 *  Created on: 2016Äê9ÔÂ15ÈÕ
 *      Author: songx
 */

#include "StrBlob.h"

#include <stddef.h>
#include <iterator>

bool operator==(const StrBlob & lhs, const StrBlob & rhs) {
	if (lhs.data->size() == rhs.data->size()) {
		for (auto beginL = lhs.data->begin(), beginR = rhs.data->begin();
				beginL != lhs.data->end(); beginL++, beginR++) {
			if (*beginL != *beginR) {
				return false;
			}
		}
		return true;
	} else {
		return false;
	}
}
bool operator!=(const StrBlob & lhs, const StrBlob & rhs) {
	return !(lhs == rhs);
}

bool operator<(const StrBlob & lhs, const StrBlob & rhs) {
	size_t i = 0;
	for (auto beginL = lhs.data->begin(), beginR = rhs.data->begin();
			i != lhs.size() && i != rhs.size(); beginL++, beginR++, i++) {
		if (*beginL < *beginR) {
			return true;
		}
	}
	if (i == lhs.size()) {
		return true;
	} else {
		return false;
	}
}

string & StrBlob::operator[](size_t n) {
	return (*data)[n];
}
const string & StrBlob::operator[](size_t n) const {
	return (*data)[n];
}
