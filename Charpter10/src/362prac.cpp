/*
 * 362prac.cpp
 *
 *  Created on: 2016年9月7日
 *      Author: songx
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
//10.29
void test44() {
	ifstream ifstrm("D:/test.txt");
	istream_iterator<string> isIter(ifstrm), eof;
	vector<string> sVec(isIter, eof);
	ostream_iterator<string> osIter(cout, "\t");
	copy(sVec.cbegin(), sVec.cend(), osIter);
	cout << endl;
}
//10.30
void test45() {
	istream_iterator<int> isIter(cin), eof;
	vector<int> iVec(isIter, eof);
	//另一种实现方式
//	vector<int> iVec;
//	while(isIter != eof){
//		iVec.push_back(*isIter++);
//	}
	sort(iVec.begin(), iVec.end());
	ostream_iterator<int> osIter(cout, "\t");
	copy(iVec.cbegin(), iVec.cend(), osIter);
	cout << endl;
}
//10.31
void test46() {
	istream_iterator<int> isIter(cin), eof;
	vector<int> iVec(isIter, eof);
	vector<int> iVec2;
	sort(iVec.begin(), iVec.end());
	unique_copy(iVec.begin(),iVec.end(),back_inserter(iVec2));
	ostream_iterator<int> osIter(cout, "\t");
	copy(iVec2.cbegin(), iVec2.cend(), osIter);
	cout << endl;
}

//10.33
void test47(string inFile,string evenFile,string oddFile){
	ifstream ifstrm(inFile);
	ofstream osEven(evenFile),osOdd(oddFile);
	istream_iterator<int> isIter(ifstrm),eof;
	ostream_iterator<int> osItEven(osEven," "),osItOdd(osOdd,"\n");
	while(isIter != eof){
		if(*isIter % 2 == 1){
			*osItOdd++ = *isIter++;
		}else{
			*osItEven++ = *isIter++;
		}
	}
	osEven.close();
	osOdd.close();
}

int main(void) {
	test47("D:/input.txt","D:/even.txt","D:/odd.txt");
	return 0;
}

