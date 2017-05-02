#include <iostream>
#include <vector>
#include <string>
using namespace std;
//4.36
void prog() {
	int i = 21;
	double d = 21.451;
	i *= static_cast<int>(d);
	cout << i << endl;
}
void prog2() {
	int i = 2;
	double  d = 3.14;
	const string * pStr;
	char * pc;
	void * pv;

	pv = static_cast<void*>(const_cast<string*>(pStr));//const string* --> string* --> void *
	i = static_cast<int>(*pc);
	pv = static_cast<void*>(&d);
	pc = static_cast<char*>(pv);
}
int main(void) {
	prog();
	return 0;
}