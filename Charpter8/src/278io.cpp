#include <iostream>
#include <string>
using namespace std;

//除了istream和ostream之外，标准库还提供了其他一些IO类型。三种类型定义在三个头文件中
//iostream :istream/ostream/iostream 从流中读写
//fstream  :ifstream/ofstream/fstream 读写文件
//sstream  :istringstream/ostringstream/stringstream 读写字符串

//还有一对宽字符版本，在名字的前面加一个w
//wcin wcout wcerr分别对应cin、cout、cerr

//对于这三种IO类型而言，它们的操作都是相同的，因为ifstream,istringstream 继承自istream，
//ofstream,ostringstream 继承自ostream

//IO对象不可以拷贝、赋值、
//不能将形参或返回类型设置为流类型
//只能以引用方式传递和返回流，因为流在使用时会改变其内容，所以不能是const的

//条件状态
//流有多种状态
//strm::iostate是一种IO类型，表示了IO对象此时的状态
//内部存放有多个二进制位，每个位表示了一种状态
//有多个函数可以返回这些状态:eof() 如果达到文件末尾，那么eofbit被置位，返回true
//fail()如果一个IO操作失败了(可恢复错误)，failbit被置位，返回true
//bad() 如果流已崩溃(系统级错误)，badbit被置位，返回true
//good() 如果流处于有效状态，那么返回true
//clear() 将所有条件状态位复位，流的状态设置为有效，返回void
//clear(iostate) 将流的状态设置为参数的状态
//setstate(iostate) 同上
//rdstate() 返回流的当前状态，返回值类型为strm::iostate

//while(cin>>string)这种方式可以检测流是否处于有效状态，但是不能告诉我们具体发生了什么。
//这些具体函数可以返回状态，也可以设置流的状态
void processInput(istream & is) {
	string s;
	is >> s;
}
void test() {
	auto oldState = cin.rdstate();
	cin.clear();
	processInput(cin);
	cin.setstate(oldState);
	//设置某些状态位
	cin.clear(cin.rdstate()& ~cin.failbit&~cin.badbit);//将failbit和badbit复位，其他位不变
}

istream & prac(istream& is) {
	string s;
	while (!is.eof()) {
		is >> s;
		cout << s << endl;
	}
	is.clear();
	return is;
}
//管理输出缓冲
//每个输出流都管理一个缓冲区，用来保存程序读写的数据
//导致缓冲刷新的原因
//1.程序正常结束(main)
//2.缓冲区满
//3.endl显式刷新
//4.使用操作符unitbuf设置流的状态，清空缓冲区
//cerr默认设置了unitbuf，所以cerr是立即刷新的
//5.一个输出流可能关联到另一个流。当读写被关联的流时，关联到的流会被刷新
//默认cin和cerr都关联到cout，所以读cin或写cerr都会导致cout的缓冲区被刷新

//IO库有类似于endl的操作符：flush和ends
//flush刷新缓冲区
//ends向缓冲区插入一个空字符，然后刷新缓冲区
void test23() {
	cout << "hi" << flush;
	cout << "hi!" << ends;
}
//unitbuf
//告诉流在接下来的每次写操作之后都进行一次flush操作
//nounitbuf操作符是重置流
void t(){
	cout << unitbuf;
	cout << nounitbuf;
}
//如果程序崩溃（异常终止），输出缓冲流不会被刷新

//关联输入和输出流
//tie函数
//每个流最多关联到一个流，但多个流可以同时关联到一个ostream
void tt() {
	cin.tie(&cout);//cin绑定到cout上，默认就是这样的
	ostream * oldTie = cin.tie(nullptr);//解除绑定，并返回之前绑定的输出流
	cin.tie(&cerr);//cin关联到cerr上
	cin.tie(oldTie);
}

int main(void) {
	prac(cin);
	return 0;
}
