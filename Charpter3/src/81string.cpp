#include <iostream>
#include <string>
using namespace std;
int main(void) {
	//3.4
	string s1, s2;
	cin >> s1 >> s2;
	if (s1 > s2) {
		cout << "�ϴ���ַ����� " << s1 << endl;
	}
	else if (s1 < s2) {
		cout << "�ϴ���ַ����� " << s2 << endl;
	}
	else {
		cout << "���ַ������" << endl;
	}

	//3.4 2)
	string s1, s2;
	cin >> s1 >> s2;
	if (s1.size() > s2.size()) {
		cout << "�ϳ����ַ����� " << s1 << endl;
	}
	else if (s1.size() < s2.size()) {
		cout << "�ϳ����ַ����� " << s2 << endl;
	}
	else {
		cout << "���ַ����������" << endl;
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
