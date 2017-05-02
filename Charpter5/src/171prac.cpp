#include <iostream>
#include <string>
using namespace std;
void pro8() {
	string str;
	string lastStr;
	bool sameWordExists = false;
	while (cin >> str && !str.empty()) {
		if (!isupper(str[0])) {
			continue;
		}
		if (str == lastStr) {
			cout << "The repeated word:" << str << endl;
			sameWordExists = true;
			break;
		}
		lastStr = str;
	}
	if (!sameWordExists) {
		cout << "No word appears repeately!" << endl;
	}
}
