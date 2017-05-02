#include <iostream>
#include <vector>
using namespace std;
int func(int, int);
vector<decltype(func)*> v1;
vector<int(*)(int, int)> v2;
typedef int(*pf)(int, int);
vector<pf> v3;
using pf2 = int(*)(int, int);
vector<pf2> v4;

int add(int a, int b) {
	return a + b;
}
int sub(int a, int b) {
	return a - b;
}
int mul(int a, int b) {
	return a*b;
}
int divide(int a, int b) {
	return a / b;
}
void test2() {
	vector<int(*)(int, int)> pfVec = { &add,&sub,&mul,&divide };
	for (auto pf : pfVec) {
		cout << (*pf)(2, 4) << endl;
	}
}

