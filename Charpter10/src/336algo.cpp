#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <list>
using namespace std;
//大多数算法都定义在algorithm和numeric头文件中
//这些算法不直接操作容器，而是遍历由两个迭代器指定的一个元素范围
//这些算法都是泛型的，可以支持任意容器和数组
//算法不会执行容器的操作，而是执行迭代器的操作，算法永远不会改变底层容器的大小，可能会改变元素的值，可以会移动元素，但不会直接插入删除元素
//标准库定义了一种特殊的迭代器称为插入器，可以在底层的容器上执行插入操作

void test1(){
	vector<int> iVec = {2,3,4,5,6,6,6,6,6,6};
	auto result = find(iVec.cbegin(),iVec.cend(),2);
	//如果找不到，那么返回第二个参数，也就是尾后迭代器
	cout<<"The result:"<<(result != iVec.cend() ? "Found!":"Not Found")<<endl;
	
	//对于内置数组
	int iArr[] = {2,3,4,5};
	int * result1 = find(begin(iArr),end(iArr),4);
	cout<<"The result:"<<(result1 != end(iArr) ? "Found!":"Not Found")<<endl;
	
	cout<<count(iVec.begin(),iVec.end(),6)<<endl;
}
int myCount(const vector<int> & iVec,int val){
	return count(iVec.cbegin(),iVec.cend(),val);
}

int myCount(const list<string> & sList,const string & val){
	return count(sList.cbegin(),sList.cend(),val);
}
int main(void){
	test1();
	vector<int> iVec ={2,3,4,5,5,5,5,5,5,5,5};
	list<string> sList = {"ks","ks","ks","12","sd"};
	cout<<myCount(iVec,5)<<endl;
	cout<<myCount(sList,"ks")<<endl;
	return 0;
}
