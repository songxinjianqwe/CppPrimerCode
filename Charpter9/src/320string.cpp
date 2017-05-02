/*
 * 320string.cpp
 *
 *  Created on: 2016年10月3日
 *      Author: songx
 */


#include <iostream>
#include <string>
#include <vector>

using namespace std;

//构造string
//构造函数接受一个string或一个const char *参数。
void test20(){
	const char * pc = "HelloWorld";
	char noNull[] = {'H','i'};
	string s1(pc);
	string s2(noNull,2);//s2 = "Hi"
	string s3(noNull);//error
	string s4(pc+5,5);
	string s5(s1,5,5);
	string s6(s1,5);
	string s7(s1,6,20);//只拷贝到s1的末尾
//	string s8(s1,16);//error抛出异常
}

//substr 返回一个string的一部分或者全部的拷贝
//可以传递给string一个可选的开始位置和计数值
void test21(){
	string s("Hello World");
	string s2 = s.substr(0,5);
	string s3 = s.substr(6);
	string s4 = s.substr(6,11);
//	string s5 = s.substr(12);//error 抛出异常
}
//从一个vector<char>构造一个string
void test22(vector<char> cVec){
	string s(cVec.begin(),cVec.end());
	cout<<s<<endl;
}
//******************************************************************
//改变string
//支持赋值运算符和assign、insert、erase操作
//除此之外，还定义了额外的insert和erase操作
void test23(){
	string s = "Hello World";
	//string特有的接受下标的insert版本，下标指出了开始位置
	s.insert(s.size(),5,'!');
	s.erase(s.size()-5,5);
	cout<<s<<endl;
	//string还提供了接受C风格字符数组的insert和assign
	const char * pc = "Shush....";
	string s2;
	s2.assign(pc,5);//从pc开始的前5个字符
	s2.insert(s2.size(),pc+5);//将pc+5指向的字符数组的字符拷贝到s2的尾部
	cout<<s2<<endl;
}
void test24(){
	string s = "some",s2 = "thing";
	s.insert(0,s2);
	cout<<s<<endl;
	s.insert(0,s2,0,s2.size());//第一个参数是开始位置，第二个参数是待拷贝字符串，第三四个是待拷贝字符串的开始结束位置
	cout<<s<<endl;
}


//append和replace函数
//append是末尾添加，replace是替换
//注意表示范围：如果用下标，就是start，len；如果是迭代器，就是being，end
void test25(){
	string s("C++ Primer"),s2 = s;
	s.insert(s.size()," 5th Ed.");
	s2.append(" 5th Ed.");
	cout<<s<<endl;
	cout<<s2<<endl;
	
	s.replace(11,3,"4th");//第一个参数是开始位置，第二个参数是删除字符数，第三个是替换为的字符串
	cout<<s<<endl;
}
//将一个字符串中的旧子串替换为新子串
void test26(string & s,const string & oldStr,const string & newStr){
	for(string::size_type i = 0; i != s.size(); ){
		if(s.substr(i,oldStr.size()) == oldStr){
			s.replace(i,oldStr.size(),newStr);
			i += newStr.size();
		}else{
			++i;
		}
	}
	cout<<s<<endl;
}

//将一个字符串的前缀和后缀添加后返回
string test27(const string & s,const string & prefix,const string &suffix){
	string newStr(s);
	newStr.insert(0,prefix);
	newStr.append(suffix);
	return newStr;
}
//**************************************************************************88
//string搜索
//每个搜索函数都返回一个string::size_type值，表示匹配发生位置的下标。
//如果搜索失败，则返回一个string::npos的静态成员，并初始化值为-1
void test28(){
	string name = "AnnaBella";
	auto pos1 = name.find("Anna");//pos1 == 0
	string lowercase("annabella");
	pos1 = lowercase.find("Anna");//pos1 == npos
	string numbers("0123456789");
	name = "r2d2";
	auto pos = name.find_first_of(numbers);
	//返回name中的第一个数字的位置
	auto pos2 = name.find_first_not_of(numbers);
	//返回name中的第一个不是数字的位置
}
//指定搜索范围
void test29(){
	string name("r2d2");
	string numbers("0123456789");
	string::size_type pos = 0;
	while((pos = name.find_first_not_of(numbers,pos)) != string::npos){
		cout<<"found number at index:"<<pos<<" element is "<<name[pos]<<endl;
		++pos;
	}
}
//逆向搜索
void test30(){
	//rfind函数搜索最后一个匹配
	string river("Mississippi");
	auto firstPos = river.find("is");
	auto lastPos = river.rfind("is");//字符串会倒过来，返回的位置是从右数的位置
	cout<<"firstPos "<<firstPos<<endl;//1
	cout<<"lastPos "<<lastPos<<endl;//4
}
int main(){
//	vector<char> cVec = {'H','i'};
//	test22(cVec);
//	test23();
//	test24();
//	string s = "PlusPlusPlusHahhahahahahahha....";
//	string s1 = "Plus",s2 = "Sub";
//	test26(s,s1,s2);
//	string s = "NewSong";
//	string s1 = "Mr.";
//	string s2 = "III";
//	cout<<test27(s,s1,s2)<<endl;
	test30();
}
