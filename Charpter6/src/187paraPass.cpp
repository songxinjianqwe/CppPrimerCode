#include <iostream>
using namespace std;
//参数传递只有两种情况：传值调用；传引用调用
//无论是元素or指针，都是将实参的值拷贝给形参，形参和实参是两个没有关系的变量
//传引用调用是指形参是实参的别名，对形参操作也同时对实参进行操作

//当需要访问函数外部的对象时，C++常使用引用类型来实现，而非指针类型

//使用引用的另一个特点是不需要进行拷贝，如果对象比较大，那么拷贝的效率很低
//如果不想修改变量的值的话，可以将形参声明为常量引用类型，这样不仅可以避免拷贝，也可以防止通过引用修改值

//使用引用还有一个特点：可以作为一种返回值类型，除了return的返回值，将形参声明为引用类型还可以将其他的返回值存放在形参中（当然也改变了实参）
//
void reset(int * pi) {
	*pi = 0;//通过指针修改val的值，pi的值和&val的值一致，但不是同一个变量
	pi = 0;//对&val没有影响
}

//传引用调用
void reset(int &i) {
	i = 0;
}
void swap(int * a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
bool isShort(const string&  s1, const string &  s2) {
	if (s1.size() < s2.size()) {
		return true;
	} else {
		return false;
	}
}
string::size_type findChar(const string & str, char ch, string::size_type &occurs) {
	//返回在这个字符串中该字符第一次出现的位置（返回值）和出现次数（存放在occurs）
	auto index = str.size();
	for (decltype(index) i = 0; i != str.size(); i++) {
		if (str[i] == ch) {
			if (index == str.size()) {
				index = i;
			}
			occurs++;
		}
	}
	return index;
}
int main(void) {
	int val = 20;
	reset(&val);
	cout << val << endl;
	int i = 321, j = 123;
	swap(&i, &j);
	cout << i << "\t" << j << endl;

	reset(i);
	reset(j);
	cout << i << "\t" << j << endl;
	string::size_type occurs = 0;
	
	cout << findChar("I am the king of the world!", 't', occurs) << endl;
	cout << "t occurs " << occurs << " times" << endl;
	return 0;
}
