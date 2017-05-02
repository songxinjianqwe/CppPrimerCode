#include <iostream>
#include <initializer_list>
#include <string>
using namespace std;
//6.27
int sum(initializer_list<int> list) {
	int sum = 0;
	for (auto i : list) {
		sum += i;
	}
	return sum;
}
