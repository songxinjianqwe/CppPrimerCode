/*
 * Main.cpp
 *
 *  Created on: 2016��9��26��
 *      Author: songx
 */


#include <fstream>
#include <iostream>

#include "../header/Query.h"
#include "../header/QueryResult.h"
#include "../header/TextQuery.h"

using namespace std;

//��Ԫ�������������ڵ�ǰ���ͷ�ļ��У�������ڵ�ǰ���cpp�ļ���
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

