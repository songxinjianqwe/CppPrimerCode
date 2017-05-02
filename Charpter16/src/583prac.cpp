/*
 * 583prac.cpp
 *
 *  Created on: 2016Äê9ÔÂ27ÈÕ
 *      Author: songx
 */

#include <stddef.h>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

template<typename iteratorT,typename valueT>
iteratorT find(const iteratorT & begin,const iteratorT & end,valueT element){
	for(auto start = begin;start != end; start++){
		if(*start == element){
			return start;
		}
	}
	return end;
}
void test3(){
	vector<int> iVec = {2,3,4,5};
	cout<<*find(iVec.begin(),iVec.end(),2)<<endl;
}
template<typename T,unsigned size>
void print(const T (&pArr)[size]){
	for(size_t i = 0; i != size;i++){
		cout<<pArr[i]<<"\t";
	}
	cout<<endl;
}
void test4(){
	int arr[] = {23,4,5,23,23,2,4,5};
	print(arr);
}
//************************************************************************//

template<typename T,unsigned size>
T * myBegin(T (&pArr)[size]){
	return pArr;
}

template<typename T,unsigned size>
T * myEnd(T (&pArr)[size]){
	return pArr+size;
}

void test5(){
	int arr[] = {2,3,4,5,6};
	for(auto it = myBegin(arr);it != myEnd(arr);it++){
		cout<<*it<<"\t";
	}
	cout<<endl;
}
//****************************************************************//
template <typename T,unsigned size>
constexpr unsigned length(const T (&pArr)[size]){
	return size;
}
void test6(){
	string sArr[] = {"aaa","bbb"};
	cout<<length(sArr)<<endl;
}
//**************************************************************//


