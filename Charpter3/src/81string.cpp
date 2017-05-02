#include <iostream>
#include <string>
using namespace std;
int main(void) {
	//3.4
	string s1, s2;
	cin >> s1 >> s2;
	if (s1 > s2) {
		cout << "较大的字符串是 " << s1 << endl;
	}
	else if (s1 < s2) {
		cout << "较大的字符串是 " << s2 << endl;
	}
	else {
		cout << "两字符串相等" << endl;
	}

	//3.4 2)
	string s1, s2;
	cin >> s1 >> s2;
	if (s1.size() > s2.size()) {
		cout << "较长的字符串是 " << s1 << endl;
	}
	else if (s1.size() < s2.size()) {
		cout << "较长的字符串是 " << s2 << endl;
	}
	else {
		cout << "两字符串长度相等" << endl;
	}

	//3.5
	string longStr;
	string str;
	while (cin >> str) {
		longStr += str;
//		longStr += " ";
	}
	cout << longStr << endl;

	return 0;
}
