/*
 * Main.cpp
 *
 *  Created on: 2016年9月26日
 *      Author: songx
 */


#include <fstream>
#include <iostream>

#include "../header/Query.h"
#include "../header/QueryResult.h"
#include "../header/TextQuery.h"

using namespace std;

//友元函数的声明放在当前类的头文件中，定义放在当前类的cpp文件中
int main(){
	ifstream ifstrm("D:/text.txt");
	TextQuery tq(ifstrm);
	Query q1("I");
	Query q2("his");
	Query q = q1|q2;
	cout<<q<<endl;
	cout<<q.eval(tq);
	return 0;
}

