#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>


using namespace std;

//10.14
void test17(){
	auto lambda = [](int i,int j)->int{return i+j;};
	cout<<lambda(2,4)<<endl;
}
//10.15
void test18(){
	int i = 21;
	auto lambda = [i](int j){return i+j;};
	cout<<lambda(3)<<endl;
}
//10.16
void test19(){
	vector<string> sVec = { "the", "quick", "red", "fox", "jumps", "over",
			"the", "slow", "red", "turtle" };
	sort(sVec.begin(),sVec.end());
	auto dupStart = unique(sVec.begin(),sVec.end());
	sVec.erase(dupStart,sVec.end());
	stable_sort(sVec.begin(),sVec.end(),[](const string &s1,const string &s2)->bool {return s1.size()<s2.size();});
	string::size_type sz = 4;
	auto bigerStart = find_if(sVec.begin(),sVec.end(),[sz](const string & str){return str.size()>sz;});
	for_each(bigerStart,sVec.end(),[](const string &s){cout<<s<<"\t";});
	cout<<endl;
}
//10.17
class SaleData{
private:
	string bookNo;
public:
	string  isbn()const {
		return bookNo;
	}
	SaleData(const string & s):bookNo(s){}
};

void test20(){
	vector<SaleData> sds = {SaleData("123"),SaleData("1234"),SaleData("12345"),SaleData("1234567")};
	sort(sds.begin(),sds.end(),[](const SaleData &sd1,const SaleData &sd2){return sd1.isbn().size() < sd2.isbn().size();});
	for_each(sds.begin(),sds.end(),[](const SaleData & sd){cout<<sd.isbn()<<"\t";});
	cout<<endl;
}
//10.18
void test21(){
	vector<string> sVec = { "the", "quick", "red", "fox", "jumps", "over",
			"the", "slow", "red", "turtle" };
	sort(sVec.begin(),sVec.end());
	auto dupStart = unique(sVec.begin(),sVec.end());
	sVec.erase(dupStart,sVec.end());
	stable_sort(sVec.begin(),sVec.end(),[](const string &s1,const string &s2)->bool {return s1.size()<s2.size();});
	string::size_type sz = 4;
	auto bigerStart = partition(sVec.begin(),sVec.end(),[sz](const string & str){return str.size()<=sz;});
	for_each(bigerStart,sVec.end(),[](const string &s){cout<<s<<"\t";});
	cout<<endl;
}
//stable_partition稳定分组，不改变true组和false组元素之间的原有次序
//10.19
void test22(){
	vector<string> sVec = { "the", "quick", "red", "fox", "jumps", "over",
			"the", "slow", "red", "turtle" };
	sort(sVec.begin(),sVec.end());
	auto dupStart = unique(sVec.begin(),sVec.end());
	sVec.erase(dupStart,sVec.end());
	stable_sort(sVec.begin(),sVec.end(),[](const string &s1,const string &s2)->bool {return s1.size()<s2.size();});
	string::size_type sz = 4;
	auto bigerStart = stable_partition(sVec.begin(),sVec.end(),[sz](const string & str){return str.size()<=sz;});
	for_each(bigerStart,sVec.end(),[](const string &s){cout<<s<<"\t";});
	cout<<endl;
}

	


