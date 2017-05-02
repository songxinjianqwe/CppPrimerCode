/*
 * SalesData.h
 *
 *  Created on: 2016Äê9ÔÂ12ÈÕ
 *      Author: songx
 */

#include <string>

using namespace std;
class SalesData {
public:
	SalesData(const SalesData &);
	SalesData & operator=(const SalesData & );
private:
	string bookNo;
	unsigned unitsSold = 0;
	double revenue = 0;
};
SalesData::SalesData(const SalesData & orig) :
		bookNo(orig.bookNo), unitsSold(orig.unitsSold), revenue(orig.revenue) {
}
SalesData & SalesData::operator =(const SalesData & orig){
	bookNo = orig.bookNo;
	unitsSold = orig.unitsSold;
	revenue = orig.revenue;
	return *this;
}


