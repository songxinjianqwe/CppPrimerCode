#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;
//������������
//iter+ / - n ��ǰ/���ƶ�n��λ��
//iter+= / -= 
//iter1- iter2 :����������֮��ľ��룬ǰ�����������������������ָ��ͬһ�������е�Ԫ��
// ����С�� :������λ���ں���Ĵ���ǰ���С��ǰ��ͬ��
bool  binarySearch() {
	int i = 0;
	vector<int> iVec = { 2,4,6,8,8,123,234,556,2424};
	cout << "Please enter the number you want to search:" << endl;
	if (cin >> i) {
		auto start = iVec.begin();
		auto end = iVec.end()-1;
		decltype(iVec.begin()) mid;
		while (start < end) {
			mid = start + (end - start) / 2;
			if (i > *mid) {
				start = mid + 1;
			}
			else if (i < *mid) {
				end = mid;//֮���Բ�����mid-1����Ϊ��������������ָ���һ��Ԫ��֮ǰ��λ��
			}
			else {
				return true;
			}
		}
	}
	return false;
}
int main(void) {
	if (binarySearch()) {
		cout << "Found it!" << endl;
	}
	else {
		cout << "Not Found!" << endl;
	}
	return 0;
}
