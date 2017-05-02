#include <iostream>
#include <stdexcept>
using namespace std;
//异常处理
//stdexcept头文件定义了几种常用的异常类
//当定义这几种异常类时，必须提供一个字符串作为参数，该字符串将会被设置为该异常对象的内部异常信息
//异常类都具有what（）方法，这个方法会返回内部的异常信息(字符串)
//5.23 
void except1() {
	int i = 0, j = 0;
	while (cin >> i >> j) {
		cout << i / static_cast<double>(j) << endl;
		cout << static_cast<double>(i) / j << endl;
		//以上两种方式都可以
		//将i转为double的效果是j也要转为double
		//即使分母为0，也会变成近似于0的数字，那么除的结果就不是直接停止运行而是输出infinity
	}
}
//5.25
void except2() {
	int i = 0, j = 0;
	while (cin >> i >> j) {
		try {
			if (j == 0) {
				throw runtime_error("The denominator can not be zero!");
			}
			cout << "The result:" << i / j << endl;
		} catch (runtime_error err) {
			cout << err.what();
			cout << " Please enter again" << endl;
		}
	}
}
int main(void) {
	except2();
	return 0;
}