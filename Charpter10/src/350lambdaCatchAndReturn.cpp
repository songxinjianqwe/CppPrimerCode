#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//当定义一个lambda时，编译器生成一个与lambda对应的新的未命名的类类型
//当一个函数传递一个lambda时，同时定义了一个新类型和该类型的一个对象，传递的参数就是此编译器生成的类类型的未命名对象
//当时auto定义一个用lambda初始化的变量时，定义了一个从lambda生成的类型的对象
//从lambda生成的类都包含一个对应该lambda所捕获的变量的成员变量，lambda的成员变量也在lambda对象被创建时被初始化

//有两种捕获方式：值捕获和引用捕获
//值捕获的前提是变量可以拷贝，被捕获的变量的值是在lambda创建时拷贝，而不是调用时拷贝
//被捕获变量的修改不会影响到lambda内对应的值
void test23() {
	int i = 32;
	auto lambda = [i] {return i;};
	i = 0;
	cout << lambda() << endl;
}
//引用捕获，在[]的变量名之前加上&
//我们在lambda函数体内使用该变量时，实际上使用的是引用所绑定的对象。
//lambda捕获的都是局部变量，这些变量在函数结束后就不再存在了。如果lambda可能在函数结束后执行，捕获的引用指向的局部变量已经消失了。
//一个适用场景是将一个流对象传入lambda，流不可复制，只能传引用
void test24(ostream & os) {
	vector<string> sVec = { "the", "quick", "red", "fox", "jumps", "over",
			"the", "slow", "red", "turtle" };
	auto lambda = [&os](const string & s) {os<<s<<"\t";};
	for_each(sVec.begin(), sVec.end(), lambda);
	cout << endl;
}
//可以从一个函数返回一个lambda ，要求这个lambda不能包含引用捕获
//我们应该尽量减少捕获的数据量，来避免潜在的捕获导致的问题，而且应该避免捕获指针或引用

//隐式捕获
//可以让编译器根据lambda函数体中的代码来推断我们要使用哪些变量，为了指示编译器推断捕获列表，应该捕获列表中写一个&或=
//&告诉编译器采用捕获引用方式，=告诉编译器采用值捕获方式
//混合捕获
//如果我们希望对一部分变量采用值捕获，对其他变量采用引用捕获，可以混合使用隐式捕获和显式捕获
//当我们使用混合使用隐式捕获和显式捕获时，捕获列表中的第一个元素必须是一个&或=。此符号指定了默认捕获方式为引用或值
//显示捕获的变量必须使用和隐式捕获不同的方式
void test25(ostream & os) {
	vector<string> sVec = { "the", "quick", "red", "fox", "jumps", "over",
			"the", "slow", "red", "turtle" };
	string::size_type sz = 4;
	sort(sVec.begin(), sVec.end(),
			[](const string & s1,const string & s2) {return s1.size()<s2.size();});
	auto biggerStart = find_if(sVec.begin(), sVec.end(),
			[=](const string & s) {return s.size() > sz;});
	for_each(biggerStart, sVec.end(), [&](const string & s) {os<<s<<"\t";});
	cout << endl;
}

void test26(ostream & os) {
	vector<string> sVec = { "the", "quick", "red", "fox", "jumps", "over",
			"the", "slow", "red", "turtle" };
	string::size_type sz = 4;
	sort(sVec.begin(), sVec.end(),
			[](const string & s1,const string & s2) {return s1.size()<s2.size();});
	auto biggerStart = find_if(sVec.begin(), sVec.end(),
			[=](const string & s) {return s.size() > sz;});
	char c = ' ';
	for_each(biggerStart, sVec.end(), [&,c](const string & s) {os<<s<<c;});
	cout << endl;
	for_each(biggerStart, sVec.end(), [=,&os](const string & s) {os<<s<<c;});
	cout << endl;
}

//可变lambda
//对于值捕获的方式，可以在lambda的参数列表之后加上mutable关键字表示可以修改一个被捕获的变量的值，默认不可以改变的
//因此可变lambda不能省略参数列表
//引用捕获能否改变取决于此引用指向的是否是const
void test27() {
	int i = 32;
	auto lambda = [i]()mutable {return ++i;};
	cout << lambda() << endl; //33
	int j = 12;
	auto lambda2 = [&j] {return ++j;};
	cout << lambda2() << endl; //13
}
//指定lambda的返回类型
//只包含单一return语句的lambda表达式可以省略返回类型
//如果不只有一个return语句，那么编译器假定此lambda返回void
//transform算法
//接受4个参数，前两个是范围，第三个是表示目的位置的迭代器，可以与第一个参数相同，第四个参数是一个可调用对象
//算法对每个元素调用可调用对象，并将结果写在目的位置

//将容器的元素都替换为其绝对值
void test28() {
	vector<int> iVec = { 2, -12, 2, -99, 12, 0, -21 };
	transform(iVec.begin(), iVec.end(), iVec.begin(),
			[](int i) {return i < 0 ? -i:i;});
	for_each(iVec.begin(), iVec.end(), [](int i) {cout<<i<<"\t";});
	cout << endl;
}
//如果将条件表达式写成if,似乎也可以?!
void test29() {
	vector<int> iVec = { 2, -12, 2, -99, 12, 0, -21 };
	transform(iVec.begin(), iVec.end(), iVec.begin(), [](int i) {if(i < 0) {return -i;} else {return i;}});
	for_each(iVec.begin(), iVec.end(), [](int i) {cout<<i<<"\t";});
	cout << endl;
}

//prac 10.20
//count_if算法，接受三个参数，前两个表示范围，第三个参数是一个一元谓词
//计数谓词为真的个数
void test30(){
	vector<string> sVec = { "the", "quick", "red", "fox", "jumps", "over",
				"the", "slow", "red", "turtle" };
	auto res = count_if(sVec.cbegin(),sVec.cend(),[](const string & str){return str.size()>4;});
	cout<<res<<endl;
}
//10.21
void test31(){
	int i = 3;
	auto lambda = [i]() mutable{
		if(i == 0){
			return true;
		}else{
			i--;
			return false;
		}
	};
	while(!lambda()){
		cout<<"Not zero"<<endl;
	}
}

