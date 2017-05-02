#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <iostream>
struct SalesData {
	std::string bookNo;
	int unitsSold = 0;
	double price = 0;
	double revenue = 0;
};
#endif

