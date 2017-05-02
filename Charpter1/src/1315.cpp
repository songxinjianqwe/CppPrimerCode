# include <iostream>
using namespace std;
//输入不定数量的整数数字，并求和
//如果遇到非整数或文件结束符Ctrl+Z时输入结束，条件为假
int summer() {
	int value = 0, sum = 0;
	while (cin >> value) {
		sum += value;
	}
	return sum;
}
//统计输入时每个整数的出现次数
void countNumOccurTimes() {
	int currentVal = 0,val = 0;
	int count = 1;
	if (cin >> currentVal) {
		while (cin >> val) {
			if (currentVal == val) {
				count++;
			}
			else {
				cout << currentVal << "occur " << count << " times"<< endl;
				currentVal = val;
				count = 1;
			}
		}
		cout << currentVal << "occur " << count << " times" << endl;
	}
}
//int main(void) {
////	cout << summer() << endl;
//	countNumOccurTimes();
//	return 0;
//}
