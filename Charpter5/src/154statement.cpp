#include <iostream>
#include <string>
using namespace std;
void p1() {
	char ch;
	int vowelCount = 0;
	int otherCount = 0;
	while (cin >> ch) {
		switch (ch) {
		case 'a':case 'e':case 'i':case 'o':case 'u'://这种写法也是可以的
			++vowelCount;
			break;
		default:
			++otherCount;
		}
	}
	cout << "元音字符个数:" << vowelCount << endl;
	cout << "其他字符个数:" << otherCount << endl;
}
//switch内部的变量定义
//如果在某处一个带有初值的变量位于作用域之外，在另一处该变量位于作用域之内，则从前一处跳转到后一处的行为是非法行为
void p2() {
	bool t = false;
	switch (t) {
	case true:
		string fileName;//error 不允许跨过变量的初始化语句直接跳转到该变量作用域的另一个位置
		int i = 0;//error 跳过了i的初始化
		int j;
		break;
	case false:
		j = 32;
		if (fileName.empty()) {
			//
		}
		break;
	}
}
//如果需要为一个case分支定义并初始化一个变量，那么应该把变量定义在代码块中，从而保证后面的所有case标签都在变量的作用域之外
void p3() {
	bool t = false;
	switch (t) {
	case true: 
		{
			string fileName;//error 不允许跨过变量的初始化语句直接跳转到该变量作用域的另一个位置
			int i = 0;
			int j;
		}
		break;
	case false:
		
		break;
	}
}
