#include <iostream>
#include <vector>
using namespace std;
void rangeFor() {
	vector<int> vec = { 2,3,4,5,6 };
	for (auto & i : vec) {
		i *= 2;
	}
	for (auto i : vec) {
		cout << i << "\t";
	}
	cout << endl;
}
//与之等价的普通for循环
void normalFor() {
	vector<int> vec = { 2,3,4,5,6 };
	for (auto begin = vec.begin(); begin != vec.end(); begin++) {
		*begin *= 2;
	}
	for (auto i : vec) {
		cout << i << "\t";
	}
	cout << endl;
}
