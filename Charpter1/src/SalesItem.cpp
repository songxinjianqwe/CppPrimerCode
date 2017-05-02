#include <iostream>
#include "SalesItem.h"
using namespace std;

//�Ӽ��̶�ȡ���ݸ�ֵ��item�ϣ�Ȼ�����
//�����ʽ������0-201-70353-X 4 24.99
void readSalesItem() {
	SalesItem item;
	while (cin >> item) {
		cout << item << endl;
	}
}
//sumOfItems ��������SalesItem������ͺ����
void sumOfItems() {
	SalesItem it1, it2;
	cin >> it1 >> it2;
	cout << it1 + it2 << endl;
}

//��ȡ�������ۼ�¼����ͳ��ÿ���飨ISBN��ͬ���м������ۼ�¼
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
//��ȡ�������ۼ�¼������ÿ��������۱���
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
