#include <iostream>
#include <string>
using namespace std;
struct SalesData {
	string bookNo;
	int unitsSold = 0;
	double price = 0;
	double revenue = 0;
};
void sum() {
	SalesData it1, it2;
	double totalRevn = 0;
	int totalCount = 1;
	if (cin >> it1.bookNo >> it1.unitsSold >> it1.price) {
		totalRevn = it1.revenue;
		it1.revenue = it1.unitsSold*it1.price;
		while (cin >> it2.bookNo >> it2.unitsSold >> it2.price) {
			if (it1.bookNo == it2.bookNo) {
				it2.revenue = it2.unitsSold*it2.price;
				totalRevn += it2.revenue;
				totalCount++;
			}
			else {
				cout << it1.bookNo << "  " << totalRevn << "   " << totalCount << endl;
				totalRevn = it2.revenue;
				it1 = it2;
				totalCount = 1;
			}
		}
		cout << it1.bookNo << "  " << totalRevn << "   " << totalCount << endl;
	}
	else {
		cout << "No data Error!" << endl;
	}
}
int main(void) {
	sum();
	return 0;
}