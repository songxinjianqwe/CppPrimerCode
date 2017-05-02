#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;
//反向迭代器
//在容器中从尾元素到首元素反向移动的迭代器，++和--的含义会颠倒，++会移动到前一个元素，--会移动到后一个元素
//rbegin和rend方法会返回everse_iterator
//crbegin和crend会返回const版本
//反向迭代器需要--运算符，所以forward_list和流迭代器不支持反向迭代器
//end和rbegin不指向同一个元素，rbegin指向最后一个元素，end指向尾后元素
//begin和rend都指向第一个元素
void test48(){
	vector<int> iVec = {2,3,4,5,6};
	//逆序打印
	for(auto it = iVec.crbegin();it != iVec.crend();it++){
		cout<<*it<<"\t";
	}
	cout<<endl;
	//sort默认是升序，按照反向迭代器可以实现降序排序
	sort(iVec.rbegin(),iVec.rend());
	//正序打印
	ostream_iterator<int> osIt(cout,"\t");
	copy(iVec.cbegin(),iVec.cend(),osIt);
	cout<<endl;
}

//反向迭代器和其它迭代器存在不同
//反向迭代器转为正向迭代器，函数base可以返回其对应的正向迭代器，位置位于反向迭代器的后一个
void test49(){
	string line = "happy,newbee,alphabet";
	//打印第一个单词
	auto comma = find(line.cbegin(),line.cend(),',');
	cout<<string(line.cbegin(),comma)<<endl;
	//打印最后一个单词
	auto rcomma = find(line.crbegin(),line.crend(),',');
	cout<<string(line.crbegin(),rcomma)<<endl;
	//tebahpla
	//如果我们想要正序的单词，就要将反向迭代器转为正向迭代器
	cout<<string(rcomma.base(),line.cend())<<endl;
	//alphabet
}
//当我们从一个普通的迭代器初始化一个反向迭代器，或是给一个反向迭代器赋值时，结果迭代器和原迭代器指向的并不是同样的元素





