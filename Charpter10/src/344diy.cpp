#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
 
//定制操作：
//比如排序，默认是按照<运算符重载进行排序的
//如果没有重载，或者需要多种排序策略，可以自己定制，一种定制方法就是传入比较的函数
//注意函数作为参数时不要写()
extern void deDuplication(vector<string> & sVec);

//我们希望将单词先按长度排序，长度相同的按字典排序
//需要我们先按字典排序，再按照长度排序，并且长度排序算法对于长度相等的元素不改变它们的次序
//sort还有一个版本，接受第三个参数，是一个谓词
//谓词是一个可调用的表达式，其返回结果是一个能用做条件的值。
//有一元谓词和二元谓词，一元谓词意味着只接受单一参数，二元谓词接受两个参数
//接受一个二元谓词参数的sort函数用这个谓词来代替<运算符。
bool isShorter(const string & s1,const string & s2){
	return s1.size() < s2.size();
}
//按长度升序

//stable_sort算法，稳定排序算法，保持了相等元素的原有顺序

void test12(){
	vector<string> sVec = { "the", "quick", "red", "fox", "jumps", "over",
			"the", "slow", "red", "turtle" };
	deDuplication(sVec);
	stable_sort(sVec.begin(),sVec.end(),isShorter);
	for(const auto & s:sVec){
		cout<<s<<"\t";
	}
	cout<<endl;
}


