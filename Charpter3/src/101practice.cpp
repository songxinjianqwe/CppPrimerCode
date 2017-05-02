#include <iostream>
#include <string>
#include <vector>

using namespace std;
void prpg() {
	vector<int> scores(11, 0);//定义11个元素
	vector<int>grades = { 100,23,12,42,24,66,45,88,56,86,90,96,77,86,77,66 };
	for (auto grade : grades) {
		(*(scores.begin() + grade / 10))++;
	}
	for (int i = 0; i < 11; i++) {
		cout << i * 10 << "-" << (i == 10 ? 100 : (i + 1) * 10) << ":" << scores[i] << endl;
	}
}
