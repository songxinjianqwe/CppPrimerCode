#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;
//迭代器的运算
//iter+ / - n 向前/后移动n个位置
//iter+= / -= 
//iter1- iter2 :两个迭代器之间的距离，前提必须是这两个迭代器必须指向同一个容器中的元素
// 大于小于 :迭代器位置在后面的大，在前面的小，前提同上
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
				end = mid;//之所以不适用mid-1是因为当迭代器不允许指向第一个元素之前的位置
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
