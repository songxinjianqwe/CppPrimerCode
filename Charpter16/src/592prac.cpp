/*
 * 592prac.cpp
 *
 *  Created on: 2016Äê9ÔÂ28ÈÕ
 *      Author: songx
 */

#include <iostream>
#include <string>

#include "../header/Blob.h"
#include "../header/BlobPtr.h"
#include "../header/Screen.h"
#include "../header/Vec.h"

using namespace std;

void test20(){
	Blob<int> iBlob;
	iBlob.push_back(2);
	iBlob.push_back(23);
	for(auto it = iBlob.begin();it != iBlob.end();++it){
		cout<<*it<<"\t";
	}
	cout<<endl;
}

void test21(){
	Screen<20,40> s('a');
	cout<<s.get()<<endl;
	s.move(10,20);
	cout<<s.get()<<endl;
	cout<<s;
	
	cout<<endl;
	Screen<20,10> s2;
	cin>>s2;
	cout<<s2;
}
void test22(){
	Vec<string> sVec = {"aaa","bbb","ccc"};
	sVec.push_back("HelloWorld");
	for(auto it = sVec.begin();it != sVec.end();it++){
		cout<<*it<<"\t";
	}
	cout<<endl;
}



