#include <iostream>
using namespace std;
//6.21
int max(int val,const int *ptr) {
	if (val > *ptr) {
		return val;
	} else {
		return *ptr;
	}
}
//6.22
//交换指针的值
void swapPtr(int * &p1, int * &p2) {
	int * temp = p1;
	p1 = p2;
	p2 = temp;
}
//6.23
void print(const int arr[], size_t size) {
	for (size_t i = 0; i != size; i++) {
		cout << arr[i] << endl;
	}
}
void print(const int * ptr) {
	//适合有结束标志的情况
	while (ptr) {
		cout << *ptr++ << endl;
	}
}
void print(const int * begin, const int * end) {
	while (begin != end) {
		cout << *begin << endl;
		begin++;
	}
}
void print(const int(&arr)[2]) {
	for (auto i : arr) {
		cout << i << endl;
	}
}

//如果写成数组形式，那么没有必要在声明处加上长度；直接加一个参数说明长度即可
//如果写成指针形式，那么也是加上一个长度的参数
//只有写成引用的形式，才必须加上数组的长度，此时也不用加参数了

int main(void) {
	int arr[2] = { 1,2 };
	print(arr);
	print(begin(arr), end(arr));
	print(arr, 2);
}
