#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;
//3.17
void p1() {
	vector<string> sVec;
	string s;
	while (cin >> s) {
		sVec.push_back(s);
	}
	for (auto &s : sVec) {
		for (auto &ch : s) {
			ch = toupper(ch);
		}
	}
	for (auto s : sVec) {
		cout << s << endl;
	}
}
//3.19 
void p2() {
	vector<int> iVec(10,42);
	vector<int> iVec2;
	for (int i = 0; i < 10; i++) {
		iVec2.push_back(42);
	}
	//vector<int> iVec3 = {42,42,42,42,42,42......}
}
//3.20 1)
void p3() {
	//将每对相邻正数的和输出
	vector<int> iVec;
	int i = 0;
	while (cin >> i) {
		iVec.push_back(i);
	}
	if (iVec.empty()) {
		cout << "No data" << endl;
	}
	else if (iVec.size() == 1) {
		cout << iVec[0] << endl;
	}
	else {
		for (decltype(iVec.size()) i = 0; i < iVec.size() - 1; i++) {
			cout << (iVec[i] + iVec[i + 1]) << endl;
		}
	}
}
//3.20 2)
void p4() {
	vector<int> iVec;
	int i = 0;
	while (cin >> i) {
		iVec.push_back(i);
	}
	if (iVec.empty()) {
		cout << "No data" << endl;
	}
	else if (iVec.size() == 1) {
		cout << iVec[0] << endl;
	}
	else {
		for (decltype(iVec.size()) i = 0; i < iVec.size()/2; i++) {
			cout << (iVec[i] + iVec[iVec.size()-i-1]) << endl;
		}
		if (iVec.size() % 2 == 1) {
			cout << iVec[iVec.size() / 2] << endl;
		}
	}
}
