#include <iostream>
using namespace std;

//重载与const_cast
//如果有一个函数它的参数和返回值都是常量引用，然后我们想重载一个函数，参数和返回值都是普通引用，并且在整个函数中调用前一个函数
//在重载中const_cast可以将const转为非const，也可以将非const转为const

//版本1
const string & shorterString2(const string & s1, const string & s2) {
	return s1.size() > s2.size() ? s2 : s1;
}
//重载版本
string & shorterString2(string &s1, string &s2) {
	auto & r = shorterString2(const_cast<const string &>(s1), const_cast<const string &>(s2));
	return const_cast<string &>(r);
}
//这种转换是安全的


