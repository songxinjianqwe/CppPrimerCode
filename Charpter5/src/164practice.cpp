#include <iostream>
#include <cctype>
using std::cout;
using std::endl;
using std::cin;
//5.9 5.10 5.11 5.12
void pro1() {
	char ch;
	int aCount = 0, eCount = 0, iCount = 0, oCount = 0, uCount = 0;
	int spaceCount = 0, tabCount = 0, newlineCount = 0;
	int ffCount = 0, flCount = 0, fiCount = 0;
	bool lastCharIsF = false;
	while (cin >> ch) {
		ch = tolower(ch);
		switch (ch) {
		case 'a':++aCount; break;
		case 'e':++eCount; break;
		case 'i':++iCount;
			if (lastCharIsF) {
				++fiCount;
			}
			break;
		case 'o':++oCount; break;
		case 'u':++uCount; break;
		case ' ':++spaceCount; break;
		case '\t':++tabCount; break;
		case '\n':++newlineCount; break;
		case 'f':
			if (!lastCharIsF) {
				lastCharIsF = true;
			}
			else {
				++ffCount;
				lastCharIsF = false;
				//如果不设为false，那么第三个字符还是f那么三个字符就算作两组了
			}
			break;
		case 'l':
			if (lastCharIsF) {
				++flCount;
			}
			break;
		default:break;
		}
		if (ch != 'f') {
			lastCharIsF = false;
		}
	}
	cout << "aCount:" << aCount << endl;
	cout << "eCount:" << eCount << endl;
	cout << "iCount:" << iCount << endl;
	cout << "oCount:" << oCount << endl;
	cout << "uCount:" << uCount << endl;
	cout << "spaceCount:" << spaceCount << endl;
	cout << "tabCount:" << tabCount << endl;
	cout << "newlineCount:" << newlineCount << endl;
	cout << "ffCount:" << ffCount << endl;
	cout << "flCount:" << flCount << endl;
	cout << "fiCount:" << fiCount << endl;
}
