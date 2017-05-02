#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using namespace std::placeholders;
//10.22
bool isShorterOrEqual(const string & str,string::size_type sz){
	return str.size() <= sz;
}

void test33(){
	vector<string> sVec = { "the", "quick", "red", "fox", "jumps", "over",
				"the", "slow", "red", "turtle" };
	auto res = count_if(sVec.cbegin(),sVec.cend(),bind(isShorterOrEqual,_1,4));	
	cout<<res<<endl;
}
//10.24
bool checkSize(int i,const string & str){
	return i > str.size();
}
void test34(){
	vector<int> iVec = {2,3,4,5,6,7};
	auto res = find_if(iVec.cbegin(),iVec.cend(),bind(checkSize,_1,"string"));
	cout<<*res<<endl;
}




