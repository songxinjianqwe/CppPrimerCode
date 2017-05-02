#include <iostream>
#include <vector>
#include <string>
using namespace std;
//5.14
void pro2() {
	string str;
	string lastStr = "";
	vector<int> appearCount;
	vector<string> appearStrings;
	size_t currentPtr = -1;
	while (cin >> str && str !="") {
		if (str == lastStr) {
			appearCount[currentPtr]++;
		}
		else {
			appearStrings.push_back(str);
			appearCount.push_back(1);
			currentPtr++;
			lastStr = str;
		}
	}
	int maxAppearIndex = 0;
	for (size_t i = 1; i != appearCount.size(); i++) {
		if (appearCount[i] > appearCount[maxAppearIndex]) {
			maxAppearIndex = i;
		}
	}
	if (lastStr != "") {
		cout << appearStrings[maxAppearIndex] << " appear " << appearCount[maxAppearIndex] << " times." << endl;
	}
	else {
		cout << "No word appears repeately!" << endl;
	}
}
