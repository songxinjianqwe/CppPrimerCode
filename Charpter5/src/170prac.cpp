#include <iostream>
#include <string>
using namespace std;

void pro5() {
	string s1, s2;
	do {
		cout << "Please enter 2 strings:" << endl;
		cin >> s1 >> s2;
		if (s1.size() < s2.size()) {
			cout << "The smaller string:" << s1 << endl;
		}
		else {
			cout << "The smaller string:" << s2 << endl;
		}
	} while (!s1.empty() && !s2.empty());
}
