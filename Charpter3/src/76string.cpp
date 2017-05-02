#include <iostream>
#include <string>
//使用string类必须包含string类的头文件
using namespace std;
void testString() {
	string s1;
	string s2(10, 'c');//括号初始化，第一个参数是重复次数，第二个参数是一个字符
	s1 = "helloworld";
	cout << s1 << endl;
	cout << s2 << endl;
	s2 = s1;//这里相当于将s1的内容复制一份，赋到s2上
	cout << s2 << endl;
	//使用等号，属于拷贝初始化；不使用等号，属于直接初始化

	//初始化之后的赋值，可以采用=的方式，比如
	s2 = "haha";
	//也可以采用拷贝初始化，括号的方式；相当于创建一个临时变量初始化为10个c，然后拷贝初始化到s2上。
	s2 = string(10, 'c');
}
int main(void) {
	string str;

	cin >> str;
	cout << str << endl;
	//cin读取的时候会从第一个非空白符到之后的第一个空白符，然后读取到的字符中不包含前后的空白符；一次输入多个字符串时空白符可以用来隔开
	string s1, s2;
	cin >> s1 >> s2;
	cout << s1 << s2 << endl;

	//读取未知数量的字符串（单词，遇到空白符就结束）
	while (cin >> str) {
		cout << str << endl;
	}

	//使用getline方法读取一整行，包括空白符
	//第一个参数是一个输入流如cin，第二个参数是字符串
	//遇到换行符时读取结束，赋到字符串上，不含换行符
	//如果一开始就是换行符，那么字符串就是一个空串
	while (getline(cin, str)) {
		cout << str << endl;
	}

	//string类还有empty和size方法
	while (getline(cin, str)) {
		if (!str.empty()) {
			cout << str << endl;
		}
	}
	//size方法返回值的类型是size_type类型，是一种无符号类型，不可与int类型混用
	//可以使用auto类型变量来接收它的返回值
	cin >> str;
	auto len = str.size();
	cout << len << endl;


	//string还重载了== != < > <= >= 等运算符
	//重载了+ 和+= 运算符，进行字符串的拼接
	string s2 = "Hello";
	string s3 = "World";
	s3 += s2;
	cout << s3 << endl;
	//字符串的拼接不仅适用于字符串之间，也适用于其他的字面量，如字符、字符串常量
	//要求是+号两侧至少有一个是string
	s3 += '2';
	s3 += "!";
	cout << s3 << endl;
	//但是不能字符串字面量相加
//	string s4 = "hlo" + "wol";//error
	return 0;
}
