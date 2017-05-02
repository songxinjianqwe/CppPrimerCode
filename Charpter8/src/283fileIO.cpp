#include <iostream>
#include <fstream>
#include <string>
#include "SalesData.h"
using namespace std;

//文件输入输出

//可以使用getline和IO运算符>> << 来读写内容
//对于iftream、ofstream、fstream 有以下操作：
//构造函数，传入一个字符串或字符数组指针: 创建一个流并打开该文件
//重载的构造函数，传入一个字符串和模式
//open(s) 打开一个文件
//close() 关闭一个文件
//is_open() 是否打开


//测试程序
void testFileIO() {
	string file = "D:/test,txt";
	ifstream in(file);
	
}
void testSalesData(string in,string out) {
	ifstream input(in);
	ofstream output(out);
	SalesData total;
	if (read(input, total)) {
		SalesData trans;
		while (read(input, trans)) {
			if (total.isbn() == trans.isbn()) {
				total.combine(trans);
			} else {
				print(output, total)<<endl;
				total = trans;
			}
		}
		print(output, total)<<endl;
	} else {
		cerr << "No data" << endl;
	}
	input.close();
	output.close();
}
//open函数可能会调用失败，failbit被置位
//if（out） 需要这样的检测
//当一个fstream对象离开其作用域时，与之关联的文件会自动关闭

//文件模式
//in 读模式
//out 写模式
// app 追加模式
//ate 打开文件后立即定位到文件结尾
//trunc 截断模式（清空）
//binary 二进制模式

//ifstream 默认为in，ofstream默认为out
//每个流可以设置多个模式
//构造函数的第二第三等等的参数都可以用来设置模式
//只有当out模式被设定后可以设定trunc模式，ofstream默认是trunc，也就是清空文件。如果想要追加，那么应同时设置out和app模式
//app模式下，即使没有显式指定out模式，文件也总是以输出方式打开

//每次打开文件时，都要设置文件格式，可能是显式的，也可能是隐式的
void testMode() {
	string file1 = "1.txt";
	string file2 = "2.txt";
	ofstream output(file1);
	ofstream output2(file1, ofstream::out);
	ofstream output3(file1, ofstream::out | ofstream::trunc);
	//以上三种情况都是out和trunc，会截断文件

	ofstream output4(file2, ofstream::app);
	ofstream output5(file2, ofstream::out | ofstream::app);
	//以上两种情况都是out和app，不会截断文件

}

int main(void) {
	testSalesData("D:/in.txt", "D:/out.txt");
	return 0;
}
