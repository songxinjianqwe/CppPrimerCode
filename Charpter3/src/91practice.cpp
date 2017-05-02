#include <iostream>
#include <string>
#include <vector>
using namespace std;
void test(void) {
	vector<int> iVec;
	int i = 0;
	while (cin >> i) {
		iVec.push_back(i);
	}
	vector<string> sVec;
	string s;
	while (cin >> s) {
		sVec.push_back(s);
	}
	for (auto str : sVec) {
		cout << str << endl;
	}
	vector<string>::size_type size = sVec.size();
	cout << size << endl;
	//下标访问
	vector<int> scores(11, 0);//定义11个元素
	vector<int>grades = { 100,23,12,42,24,66,45,88,56,86,90,96,77,86,77,66 };
	for(auto grade:grades){
		scores[grade / 10]++;
	}
	for (int i = 0; i < 11; i++) {
		cout << i*10 << "-" << (i == 10 ? 100:(i+1) * 10) << ":" << scores[i] << endl;
	}
	//注意，添加元素只能使用push_back函数，并且只能添加到尾部
	//不能使用下标的形式添加
}
