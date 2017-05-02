#include <iostream>
using namespace std;
void testP45() {
	int i = 100, sum = 0;
	for (int i = 0; i < 10; i++) {
		sum += i;
	}
	cout << i << "  " << sum << endl;
}
//尝试使用无符号数
void test2() {
	unsigned u = 10, u2 = 42;
	cout << u2 - u << endl;
	cout << u - u2 << endl;
	int i = 10, i2 = 42;
	cout << i2 - i << endl;
	cout << i - i2 << endl;
	cout << i - u << endl;
	cout << u - i << endl;
	string str("New Song");
//	extern int i;
//	i = 10;//ok
//	extern int j = 10; //error!
//	int _ = 12;
//	double Double = 21.21;

	testP45();
}
