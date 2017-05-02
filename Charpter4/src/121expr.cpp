#include <iostream>
#include <vector>
#include <string>
using namespace std;
void expr() {
	//运算符得到的结果可能是左值，也可能是右值
	//一个对象被用作右值的时候，用的是对象的值（内容）；当对象被用作左值的时候，用的是对象的身份（在内存中的位置）
	//&取地址符返回一个指针，这个指针是一个右值
	//&解引用运算符的结果是一个左值
	//decltype 如果表达式的结果是左值，那么decltype作用于该表达式（非变量）得到一个引用类型
	int *p;
	int i = 2;
	decltype(*p) ref = i;//ref的类型是int& ，引用类型
	decltype(&p) pp = &p;//pp的类型是int**，指向指针的指针

	//求值顺序
	//优先级规定了运算对象的组合方式，但是没有说明运算对象按照什么顺序求值。在大多数情况下，不会明确指定求值的顺序。
	cout << i << "\t" << ++i << endl;//这个是未定义的，不确定是i先计算还是++i先计算

	//布尔值不应该参与运算
	//当其参与运算时会被提升为int，如果是true，取负的话变成-1，还是true；如果是false，取负的话还是false

	//除法运算
	//如果两个运算对象的符号相同，结果为正；符号不同，结果为负
	//C++11标准规定结果为负值的商向0取整（直接切除小数部分）
	int j = 21;
	int k = -12;
	cout << j / k << endl;//-1
	//取余运算
	//(m/n)*n + m%n == m
	//如果m%n 不为0，那么他的符号与m相同

	//rangeFor循环中使用将变量声明为引用类型，可以避免对元素的拷贝，因为只是指向整个元素，而没有拷贝一份
	//引用可以加上const
	//当变量不是const，而其引用是const的时候，该变量本身可变，但不能通过其引用来改变它
	//const引用的作用是既避免了复制元素，提高效率，又可以保证不改变元素的值
	vector<string> sVec = {"OK","","Happy","Are you ok?","","Yooooooooo."};
	for (const auto & str : sVec) {
		//输出多个字符串，当遇到空串或到了结尾时换行
		cout << str;
		if (str.empty() || str[str.size() - 1] == '.') {
			cout << endl;
		}//只有当字符串不为空时才会检测它的最后一个字符是否为句号
		else {
			cout << "\t";
		}
	}
}
