#include <iostream>
#include <vector>
using namespace std;

void traverse(vector<int> iVec,vector<int>::size_type index) {
	if (index > 0) {
		traverse(iVec, index - 1);
	}
	cout << iVec[index] << "\t";
}
int main(void) {
	vector<int> iVec = { 2,3,4,5,6 };
	traverse(iVec, iVec.size() - 1);
	return 0;
}
