/*
 * SalesData.h
 *
 *  Created on: 2016Äê9ÔÂ12ÈÕ
 *      Author: songx
 */

#include <string>

using namespace std;
class SalesData {
	friend istream & operator>>(istream & is,SalesData & sd);
	friend ostream & operator<<(ostream & os,const SalesData & sd);
	friend SalesData  operator+(const SalesData & lhs,const SalesData & rhs);
	friend bool operator==(const SalesData & lhs,const SalesData &rhs);
	
public:
	SalesData(){}
	SalesData(const SalesData &);
	SalesData & operator=(const SalesData & );
	SalesData & operator=(const string & bookno);
	SalesData & operator+=(const SalesData & rhs);
private:
	string bookNo;
	unsigned unitsSold = 0;
	double revenue = 0;
};
