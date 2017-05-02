/*
 * 355parambind.cpp
 *
 *  Created on: 2016年9月7日
 *      Author: songx
 */

#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using namespace std::placeholders;
//lambda的使用也存在局限，只适用于只在一两个地方使用的简单操作，如果要在多个地方使用，那么还是函数更好。
//因为将函数作为谓词存在缺陷，就是缺乏灵活性，不能传递参数
//为了弥补这一缺陷，实现和lambda一样的效果，我们可以使用bind函数实现。原理类似于适配器，就是将函数进行包装，添加参数，然后得到一个包装后的新的函数
bool checkSize(const string & str,string::size_type sz){
	return str.size() > sz;
}
//对于这个函数，如果要作为一元谓词，那么需要给第二个参数一个值，并且使该函数表现为只接受一个参数
//标准库函数bind可以实现这一点，定义在functional头文件中
//auto newCallable = bind(callable,argsList);
//当我们调用newCallable时，newCallable会调用callable，并将它传递给argsList
//argsList可以包含实际的实参，对于想要保留的参数，可以加上占位符，形式是_n
//如果想这个位置的参数作为新的函数的第一个参数，占位符应该写成_1，以此类推
//这样的话，除了可以添加实参之外，也可以调整参数的顺序

//名字_n定义在一个名为placeholders的命名空间中，这个命名空间本身定义在std命名空间。为了使用这些名字，这两个命名空间都要写上。
//using namespace namespace_name; 这条语句可以使得所有来自namespace_name的名字都可以在我们的程序中直接使用。
//这个命名空间定义在functional头文件中

//注意，和lambda还有区别的一点是bind函数默认都是拷贝其参数，为了实现传引用
//还需要使用标准库函数ref，得到一个对象的引用
void print(ostream & os,const string & s){
	os<<s<<"\t";
}
bool compare(const string &s1,const string &s2){
	return s1.size()<s2.size();
}
void test32(){
	vector<string> sVec = { "the", "quick", "red", "fox", "jumps", "over",
			"the", "slow", "red", "turtle" };
	sort(sVec.begin(), sVec.end(),compare);
	auto biggerStart = find_if(sVec.begin(), sVec.end(),
			bind(checkSize,_1,4));
	for_each(biggerStart, sVec.end(),bind(print,ref(cout),_1));
	cout << endl;
}
