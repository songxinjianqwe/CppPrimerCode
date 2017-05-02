#include <iostream>
#include <string>
#include <vector>
using namespace std;
//返回类型可以是引用类型，也就是别名，不会进行值的拷贝
//不可以返回局部对象的引用或指针

const string & shorterString(const string& s1, const string & s2) {
	if (s1.size() < s2.size()) {
		return s1;
	} else {
		return s2;
	}
} 
//如果函数的返回类型是引用，那么函数返回值可以作为左值
//除此之外，函数返回值统一为右值
char & getChar(string & str, string::size_type index) {
	return str[index];
}
int main(void) {
	string s = "Hello";
	getChar(s, 2) = 'A';
	cout << s << endl;
}
//列表初始化返回值
//返回值可以以列表的形式
//如果是内置类型，那么列表中至多有一个元素；如果是类类型，那么按照类初始化的形式
//可以返回一个空的列表，表示对返回值进行值初始化
vector<string> process() {
	string excepted, actual;
	if (excepted.empty()) {
		return{};
	} else if(excepted == actual ){
		return{ "functionX","okay" };
	} else {
		return{ "functionX",excepted,actual };
	}
}

