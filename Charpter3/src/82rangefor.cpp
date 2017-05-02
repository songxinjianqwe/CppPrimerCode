#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main(void) {
	//使用rangeFor循环和cctype类来输出一个字符串中标点符号的数目

	string str = "!!!HelloWorld!!!";
	decltype(str.size()) sizeCount = 0;
	for (auto ch : str) {
		if (ispunct(ch)) {
			sizeCount++;
		}
	}
	cout << sizeCount << " punctuation characters in " << str << endl;

	//使用rangeFor和引用来修改字符串中的字符
	//全部转为大写
	//引用可以修改值
	string s2 = "HelloWorld";
	for (auto & ch : s2) {
		ch = toupper(ch);
	}
	cout << s2 << endl;


	//注意rangeFor循环必须访问每一个字符，如果想访问一部分字符，那么可以使用下标或迭代器
	//使用下标的方式也可以修改字符串中的字符
	string s3 = "hahahaha";
	if (!s3.empty()) {
		cout << s3[0] << endl;
		s3[0] = toupper(s3[0]);
		cout << s3 << endl;
	}
	
	
	//使用普通for循环和下标的方式来遍历字符串
	//将字符串第一个空白字符之前的部分转为大写
	string s4 = "hello World";
	for (decltype(s4.size()) index = 0; index < s4.size() && !ispunct(s4[index]); index++){
		s4[index] = toupper(s4[index]);
	}
	cout << s4 << endl;

	//将输入的十进制数转为十六进制并输出
	const string hexdigits = "0123456789ABCDEF";
	cout << "Enter a series of numbers between 0 and 15 separated by spaces .Hit Enter when finished." << endl;
	string result;
	string::size_type n;
	while (cin >> n) {
		if (n < hexdigits.size()) {
			result += hexdigits[n];
		}
	}
	cout << result << endl;
	return 0;
}
