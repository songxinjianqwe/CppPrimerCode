#include <iostream>
#include "SalesItem.h"
using namespace std;

//从键盘读取数据赋值到item上，然后输出
//输入格式类似于0-201-70353-X 4 24.99
void readSalesItem() {
	SalesItem item;
	while (cin >> item) {
		cout << item << endl;
	}
}
//sumOfItems 输入两个SalesItem对象，求和后输出
void sumOfItems() {
	SalesItem it1, it2;
	cin >> it1 >> it2;
	cout << it1 + it2 << endl;
}

//读取多条销售记录，并统计每本书（ISBN相同）有几条销售记录
void countOfSaleItems() {
	SalesItem it1, it2;
	int count = 1;
	if (cin >> it1) {
		while (cin >> it2) {
			if (it1.same_isbn(it2)) {
				count++;
			}
			else {
				cout << it1.isbn << " has " << count << " books"<<endl;
				it1 = it2;
				count = 1;
			}
		}
		cout << it1.isbn << " has " << count << " books" << endl;
	}
}
//读取多条销售记录，生成每本书的销售报告
int sumOfSalesItems() {
	SalesItem total, trans;
	if (cin >> total) {
		while (cin >> trans) {
			if (total.isbn == trans.isbn) {
				total += trans;
			}
			else {
				cout << total << endl;
				total = trans;
			}
		}
		cout << total << endl;
	}
	else {
		cerr << "No Input Error!"<<endl;
		return -1;
	}
	return 0;
}
int main() {
	sumOfItems();
	countOfSaleItems();
	sumOfSalesItems();
	return 0;
}
