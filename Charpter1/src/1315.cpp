# include <iostream>
using namespace std;
//���벻���������������֣������
//����������������ļ�������Ctrl+Zʱ�������������Ϊ��
int summer() {
	int value = 0, sum = 0;
	while (cin >> value) {
		sum += value;
	}
	return sum;
}
//ͳ������ʱÿ�������ĳ��ִ���
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
