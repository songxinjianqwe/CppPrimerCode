#include <iostream>
using namespace std;
//4.10
void p1() {
	int i;
	while (cin >> i && i != 42) {
		cout << i << "\t";
	}
	cout << endl;
}
//4.11
bool p2(int a,int b,int c ,int d) {
	if (a > b && b > c && c > d) {
		return true;
	}
	else {
		return false;
	}
}
