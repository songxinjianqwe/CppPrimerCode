#include <iostream>
using namespace std;

//内联函数
//因为调用函数比求等价表达式的速度要慢一些
//为了提高速度，将函数指定为内联函数，将它在每个调用点上内联地展开。
//在函数返回类型之前加上inline关键字，就声明该函数为内联函数
//内联说明只是向编译器发出一个请求，编译器可以选择忽略这个请求

inline const string & shorterString(const string & s1, const string & s2) {
	return s1.size() > s2.size() ? s2 : s1;
}
//conexpr函数
//能用于常量表达式的函数
//规定：函数的返回值类型和所有形参的类型都必须是字面值类型（不包括库类型、类类型）
//函数体中必须有且只有一条return语句

//执行初始化任务时，编译器把对constexpr函数的调用替换为其结果值，为了在编译过程中随时展开，constexpr函数被隐式指定为内联函数
//constexpr函数的参数为常量表达式时，它的返回值也是常量表达式。如果结果恰好不是常量表达式，那么编译器将报错
//注意！constexpr函数未必一定返回常量表达式

//内联函数和constexpr函数可以在程序中多次定义，但是定义必须完全一致。它们通常定义在头文件中

//constexpr bool isShorter(const string & s1, const string & s2) {
//	return s1.size() - s2.size();
//}
//error 这不是常量表达式，因为参数类型是string，不是字面值类型

constexpr int newSize() {
	return 542;
}
//ok