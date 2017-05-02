#include <iostream>
using namespace std;
//局部静态变量
//static 变量
//在程序执行路径第一次经过对象定义语句时初始化，并且直到整个程序运行完才被销毁。在此期间即使对象所在的函数结束执行也不会对它有影响。
//如果没有显式初始化，那么局部静态变量将执行值初始化（内置类型置为0）
size_t countCalls() {
	static size_t counter = 0;
	return ++counter;
}
int main(void) {
	for (int i = 0; i < 10; i++) {
		cout << countCalls() << endl;
	}
}
