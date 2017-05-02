#include <iostream>
#include <string>
using namespace std;
//默认实参
//有些情况下，在函数的多次调用中有些形参都被赋予同样的一个值，这个反复出现的值就是默认实参
//调用含有默认实参的函数时，可以包含该实参，也可以省略该实参
//在函数的声明或定义时添加默认值
//如果想使用默认实参，那么在调用的时候省略该实参即可
using sz = string::size_type;
string screen(sz height = 231, sz weight = 2313, char background = 'c'){
	
}
void call() {
	string s;
	s = screen();//三个参数全部采用默认值
	s = screen(223);//第一个参数修改，其他参数仍为默认值
	s = screen(212, 32);//第一二个参数修改，其他参数仍为默认值
	s = screen(232, 123, '1');//全部修改
}
//由此可见，经常使用默认值的形参最好放在后面，不经常使用默认值的形参最好放在前面

//由于函数可以声明多次，所以添加默认值也可以多次进行
//规则是先添加后面的参数，再添加前面的参数
//每个参数都只能赋一次默认值
//讲道理，应该在函数声明中至多默认实参，并将该声明放在头文件中（一次即可）

//默认实参的值不可以为局部变量，可以为全局变量和字面量和函数返回值
sz weight = 23;
char def = '2';
sz height();
//string screen(sz = height(), sz = weight, char = def);
//格式为类型= 值

//6.42


string makePlural(size_t count, const string & word, const string & ending = "s") {
	return count > 1 ? word + ending : word;
}

void foo() {
	cout << makePlural(2, "success") << endl;
	cout << makePlural(1, "success") << endl;
	cout << makePlural(2, "failure") << endl;
	cout << makePlural(1, "failure") << endl;
}



