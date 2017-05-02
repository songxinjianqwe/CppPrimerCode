#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;
//迭代器可以用于容器类和string
//容器类和string都有两个方法begin()和end()，它们可以返回迭代器
//begin指向第一个元素，end指向最后一个元素的后一个元素
//迭代器的类型因容器不同而不同
//迭代器的方法（类似于指针):*iter 取值 ;iter->属性或方法;++ -- 移动到下一个或上一个位置 ;== != 可以用来判断何时结束（不用大于小于，因为不是全部容器都支持）
//容器为空时begin和end相等
//使用解引用运算符*可以修改值
//cbegin cend是不可变的迭代器，不可使用迭代器去改变值，只读
//如果容器本身是const，那么begin、end和cbein、cend都是const的；如果容器本身不是const，那么begin、end不是const，cbegin、cend是const的
//使用迭代器时，不可以改变容器的大小（比如vector不可使用push_back方法）
void test1() {
	//将一个字符串的首字母变大写
	string str = "some string";
	if (str.begin() != str.end()) {
		auto it = str.begin();
		*it = toupper(*it);
	}
	cout << str << endl;
}
void test2() {
	//将字符串的第一个空格之前的字符转为大写
	string str = "some string";
	for (auto it = str.begin(); it != str.end() && !isspace(*it); it++) {
		*it = toupper(*it);
	}
	cout << str << endl;
}
void test3() {
	//存放string的vector，输出第一个空字符串之前的所有字符串
	vector<string> sVec = { "HW","Try","","2","HEl","45545" };
	for (auto it = sVec.begin(); it != sVec.end() && !it->empty(); it++) {
		cout << *it << endl;
	}
}

