#include <iostream>
#include <iterator>
#include <cstdlib>
using namespace std;

void ptrAndArray() {
	int arr[3][4];
	int (*pArr)[4] = &arr[2]; //pArr是一个数组指针，指向arr数组的第三行
	pArr = arr; //指向arr数组的第一行(数组名为首元素指针)
	//区别：
//	int *ip[4];
//	int(*ip2)[4];
	//采用从内到外的读法，前者是一个ip数组，数组元素是int*，所以是一个指针数组
	//后者是一个ip指针，指向一个int[4]数组，所以是一个数组指针
	//C++11标准可以使用auto来避开这些复杂的类型

	//使用嵌套循环来遍历二维数组，需要已知数组各层长度
	for (auto pRow = arr; pRow != arr + 3; pRow++) {
		for (auto pCol = *pRow; pCol != *pRow + 4; pCol++) {
			//加一个解引用表示降一层
			*pCol = rand();
			cout << *pCol << "\t";
		}
		cout << endl;
	}
	cout << endl << endl;
	//使用begin、end和嵌套来遍历二维数组，不需要知道各层长度
	//这种方式更加简洁
	for (auto pRow = begin(arr); pRow != end(arr); pRow++) {
		for (auto pCol = begin(*pRow); pCol != end(*pRow); pCol++) {
			cout << *pCol << "\t";
		}
		cout << endl;
	}
	cout << endl << endl;
	//使用类型别名进行简化
	using intArray = int[4];
	for (intArray *pRow = arr; pRow != arr + 3; pRow++) {
		for (int * pCol = *pRow; pCol != *pRow + 4; pCol++) {
			cout << *pCol << "\t";
		}
		cout << endl;
	}
}

