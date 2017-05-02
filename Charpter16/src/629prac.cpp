/*
 * 629prac.cpp
 *
 *  Created on: 2016Äê10ÔÂ1ÈÕ
 *      Author: songx
 */

#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<typename T>
int countE(const vector<T> &vec, T t) {
	int count = 0;
	for (auto i : vec) {
		if (i == t) {
			count++;
		}
	}
	return count;
}

//T --> const char *
template<>
int countE(const vector<const char *>& vec, const char * t) {
	int count = 0;
	for (auto i : vec) {
		if (strcmp(i,t)) {
			count++;
		}
	}
	return count;
}
void test70() {
	vector<string> sVec = { "23", "1as2", "s", "s", "sda", "s", "sadsd" };
	cout << countE(sVec, string("s")) << endl;
	vector<const char *> sVec2 = { "23", "1as2", "s", "s", "sda", "s", "sadsd" }; 
	cout << countE(sVec2, "s") << endl;
}

int main(void) {
	test70();
	return 0;
}

