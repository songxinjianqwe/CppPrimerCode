#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;
//3.22
void test6() {
	vector<string> sVec = { "HW","Try","","2","HEl","45545" };
	//对一个vector使用迭代器
	for (auto it = sVec.begin(); it != sVec.end() && !it->empty(); it++) {
		//对一个string使用迭代器
		for (auto sIt = it->begin(); sIt != it->end(); sIt++) {
			*sIt = toupper(*sIt);
		}
		cout << *it << endl;
	}
}
//3.23
void test7() {
	vector<int> iVec = { 20,120,2130,20,120,401 ,23,1,4,24};
	for (auto it = iVec.begin(); it != iVec.end(); it++) {
		*it = 2 * (*it);
		cout << *it << endl;
	}
} 
