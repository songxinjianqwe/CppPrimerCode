#include "184prac.h"

#include <iostream>

using namespace std;
//推荐将函数声明和全局变量的声明放在头文件中
//6.3
int fact(int n) {
	int ret = 1;
	for (int i = n; i > 1; i--) {
		ret *= i;
	}
	return ret;
}
//6.4
int fact() {
	int n = 0;
	cout << "Please enter the parameter:";
	cin >> n;
	int ret = 1;
	for (int i = n; i > 1; i--) {
		ret *= i;
	}
	return ret;
}
int abs(int num) {
	return num < 0 ? -num : num;
}
int main(void) {
	cout << fact(5) << endl;
	cout << fact() << endl;
	cout << abs(-21) << endl;
	return 0;
}
