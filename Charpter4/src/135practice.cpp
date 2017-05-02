#include <iostream>
#include <vector>
#include <string>
using namespace std;
//4.21
void pro1() {
	vector<int> iVec = { 2,3,5,2,1,5,2,2,4,5 };
	for (auto & i : iVec) {
		i = i % 2 == 1 ? i * 2 : i;
	}
	for (auto i : iVec) {
		cout << i << "\t";
	}
	cout << endl;
}
//4.22 1)
void pro2() {
	int grade = 21;
	string finalResult = grade < 60 ? "fail" : grade < 75 ? "low pass" : grade < 90 ? "pass" : "high pass";
	cout << finalResult << endl;
}
//4.22 2)
void pro3() {
	int grade = 63;
	string finalResult;
	if (grade < 60) {
		finalResult = "fail";
	}
	else if (grade < 75) {
		finalResult = "low pass";
	}
	else if (grade < 90) {
		finalResult = "pass";
	}
	else {
		finalResult = "high pass";
	}
	cout << finalResult << endl;
}
