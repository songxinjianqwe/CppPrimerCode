/*
 * SalesData.cpp
 *
 *  Created on: 2016年9月15日
 *      Author: songx
 */


#include "SalesData.h"

#include <iostream>

SalesData::SalesData(const SalesData &rhs):bookNo(rhs.bookNo),unitsSold(rhs.unitsSold),revenue(rhs.revenue){}
SalesData & SalesData::operator=(const SalesData &rhs){
	bookNo = rhs.bookNo;
	unitsSold = rhs.unitsSold;
	revenue  = rhs.revenue;
	return *this;
}
istream & operator>>(istream & is,SalesData & sd){
	double price;
	is>>sd.bookNo>>sd.unitsSold>>price;
	//必须要有错误检测
	if(is){
		sd.revenue = sd.unitsSold*price;
	}else{
		sd = SalesData();
	}
	return is;
}
ostream & operator<<(ostream & os,const SalesData & sd){
	os<<sd.bookNo<<"   "<<sd.unitsSold<<"    "<<sd.revenue;
	return os;
}
//使用+= 来实现+
SalesData  operator+(const SalesData & lhs,const SalesData & rhs){
	SalesData sd;
	if(lhs.bookNo == rhs.bookNo){
		sd = lhs;
		sd += rhs;
	}
	return sd;
}

SalesData & SalesData::operator+=(const SalesData & rhs){
	if(bookNo == rhs.bookNo){
		unitsSold += rhs.unitsSold;
		revenue += rhs.revenue;
	}
	return *this;
}
bool operator==(const SalesData & lhs,const SalesData &rhs){
	return lhs.bookNo == rhs.bookNo && lhs.unitsSold == rhs.unitsSold && lhs.revenue == rhs.revenue;
}

bool operator!=(const SalesData & lhs,const SalesData &rhs){
	return !(lhs == rhs);
}
SalesData & SalesData::operator=(const string & bookno){
	bookNo = bookno;
	unitsSold = 0;
	revenue = 0;
	//*this = SalesData(bookno);
	return *this;
}
