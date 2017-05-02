#include <stddef.h>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

//关联容器的类型别名：
//key_type:关键字类型
//mapped_type:值的类型，仅适用于map
//value_type:对于set，和key_type相同；对于map，为pair<const key_type,mapped_type>

//注意关键字都是const的，set的元素不可变，map的key不可变

//迭代器
//解引用一个关联容器迭代器时，我们会得到一个类型为容器的value_type的值的引用
void test9(){
	map<string,size_t> wordCount;
	for(auto it = wordCount.begin();it != wordCount.end();it++){
		cout<<it->first<<endl;
		it->second++;
	}
	
}
//set的迭代器都是只读的，不能用迭代器来修改元素
//当我们用迭代器遍历一个map或set时，迭代器会按关键字升序遍历

//通常我们不对关联容器使用泛型算法，因为关联容器的迭代器是const的（map的key是const，value不是）
//只可以使用只读的算法；泛型的搜索算法效率较低，因为不能按照它们的关键字进行快速查找，而是顺序查找
//使用关联容器定义的find算法比泛型find快得多
//如果我们真要对一个关联容器使用算法，要么将它当做一个原序列，要么当做一个目的位置。比如copy

//
void test10(){
	vector<string> sVec;
	multiset<string> sSet;
	copy(sVec.begin(),sVec.end(),inserter(sSet,sSet.end()));
//	copy(sVec.begin(),sVec.end(),back_inserter(sSet));sSet没有定义push_back函数
	copy(sSet.begin(),sSet.end(),inserter(sVec,sVec.end()));
	copy(sSet.begin(),sSet.end(),back_inserter(sVec));
}
