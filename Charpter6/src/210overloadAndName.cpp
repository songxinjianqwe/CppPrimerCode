#include <iostream>
using namespace std;

//重载与作用域
//如果我们在内层作用域中声明名字，它将隐藏外层作用域中声明的同名实体。在不同的作用域中无法重载函数名
string read();

void fooBar() {
	bool read = false;
//	string s = read();//error
}
//一旦在当前作用域找到所需的名字，编译器就会忽略掉外层作用域中的同名实体（与类型无关）。