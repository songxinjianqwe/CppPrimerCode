#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main(void) {
	//3.6
	string str = "sadasdqweq";
	for (auto &ch : str) {
		ch = 'X';
	}
	cout << str << endl;
	string s;
	cout << s[0] << endl;

	const string str2 = "Keep Out!";
	for (auto & ch : str2) {
//		ch = 'X';//error
	}
	string input, output;
	if (getline(cin,input)) {
		for (auto ch : input) {
			if (!ispunct(ch)) {
				output += ch;
			}
		}
	}
	cout << output << endl;
	return 0;
}
