#include <iostream>
#include <vector>
using namespace std;
//5.17
bool isPre(vector<int> vec, vector<int> pre) {
	if (pre.size() > vec.size()) {
		return false;
	}
	for (size_t i = 0; i != pre.size(); i++) {
		if (pre[i] != vec[i]) {
			return false;
		}
	}
	return true;
}
int main(void) {
	vector<int> vec = { 2,3,4,5,6 };
	vector<int> pre = { 2,3,4 ,5,6 };
	cout << isPre(vec, pre) << endl;
	return 0;
}
