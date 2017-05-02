#include <iostream>
#include <string>
#include <vector>
using namespace std;
using std::begin;
using std::end;
//3.35
void program() {
	int arr[] = { 2,4,5,1,2,42 };
	for (auto begin = std::begin(arr); begin != std::end(arr); begin++) {
		*begin = 0;
	}
	for (auto i : arr) {
		cout << i << endl;
	}
}
//3.36 1)
//判断两数组相等
//如果直接传入两个数组，那么在函数中只能识别为两个int指针而非两个数组
//无法得到两个数组的长度，所以只能传入开始结束的指针
bool equals(int *  startA,int * endA,int * startB,int * endB) {
	if ((endA-startA)!= (endB-startB) ) {
		return false;
	}
	for (int *i = startA, *j = startB; i != endA && j != endB; i++, j++) {
		if (*i != *j) {
			return false;
		}
	}
	return true;
}
//3.36 2)
//vector的比较可以直接使用==，如果自己实现的话如下:
bool equals(vector<int> a,vector<int> b) {
	if (a.size() != b.size()) {
		return false;
	}
	for (int i = 0; i != a.size(); i++) {
		if (a[i] != b[i]) {
			return false;
		}
	}
	return true;
}
//int main(void) {
////	vector<int> a = { 1,2,3,4 };
////	vector<int> b = { 1,2,3,4 };
////	cout << equals(a, b) << endl;
//
//	int a[] = { 1,2,3,4 };
//	int b[] = { 1,2,3,4,5 };
//	cout << equals(begin(a), end(a), begin(b), end(b)) << endl;
//	return 0;
//}