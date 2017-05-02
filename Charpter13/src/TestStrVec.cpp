/*
 * TestStrVec.cpp
 *
 *  Created on: 2016Äê9ÔÂ13ÈÕ
 *      Author: songx
 */

#include <fstream>
#include <iostream>
#include <string>

#include "TextQuery.h"

using namespace std;


void runQuery(ifstream & ifstrm) {
	TextQuery tq(ifstrm);
	cout << "Enter word to look for:";
	string word;
	while (cin >> word) {
		printResult(cout, tq.query(word))<<endl;
		cout << "Enter word to look for:";
	}
}

int main(void){
	ifstream ifstrm("D:/text.txt");
	runQuery(ifstrm);
	ifstrm.close();
	return 0;
}
