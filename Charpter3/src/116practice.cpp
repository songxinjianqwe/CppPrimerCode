#include <iostream>
using namespace std;
void traverseWithRangeFor1() {
	int arr[2][3] = { 1,2,3,4,5,6 };
	for (int(&row)[3] : arr) {
		for (int col : row) {
			cout << col << "\t";
		}
		cout << endl;
	}
}
void traverseWithIndex1() {
	int arr[2][3] = { 1,2,3,4,5,6 };
	for (size_t i = 0; i < 2; i++) {
		for (size_t j = 0; j < 3; j++) {
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}
void traverseWithPtr1() {
	int arr[2][3] = { 1,2,3,4,5,6 };
	for (int(*pRow)[3] = begin(arr); pRow != end(arr); pRow++) {
		for (int *pCol = begin(*pRow); pCol != end(*pRow); pCol++) {
			cout << *pCol << "\t";
		}
		cout << endl;
	}
}
//使用类型别名
void traverseWithRangeFor2() {
	int arr[2][3] = { 1,2,3,4,5,6 };
	using intArray = int[3];
	for (intArray & row  : arr) {
		for (int col : row) {
			cout << col << "\t";
		}
		cout << endl;
	}
}
void traverseWithIndex2() {
	int arr[2][3] = { 1,2,3,4,5,6 };
	for (size_t i = 0; i < 2; i++) {
		for (size_t j = 0; j < 3; j++) {
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}
void traverseWithPtr2() {
	int arr[2][3] = { 1,2,3,4,5,6 };
	using intArray = int[3];
	for (intArray *pRow = begin(arr); pRow != end(arr); pRow++) {
		for (int *pCol = begin(*pRow); pCol != end(*pRow); pCol++) {
			cout << *pCol << "\t";
		}
		cout << endl;
	}
}
//使用auto
void traverseWithRangeFor3() {
	int arr[2][3] = { 1,2,3,4,5,6 };
	for (auto & row : arr) {
		for (auto col : row) {
			cout << col << "\t";
		}
		cout << endl;
	}
}
void traverseWithIndex3() {
	int arr[2][3] = { 1,2,3,4,5,6 };
	for (size_t i = 0; i < 2; i++) {
		for (size_t j = 0; j < 3; j++) {
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}
void traverseWithPtr3() {
	int arr[2][3] = { 1,2,3,4,5,6 };
	for (auto pRow = begin(arr); pRow != end(arr); pRow++) {
		for (auto pCol = begin(*pRow); pCol != end(*pRow); pCol++) {
			cout << *pCol << "\t";
		}
		cout << endl;
	}
}
int main(void) {
	traverseWithRangeFor3();
	traverseWithIndex3();
	traverseWithPtr3();
}