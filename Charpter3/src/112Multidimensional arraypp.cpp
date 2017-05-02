#include <iostream>
#include <string>
#include <vector>
using namespace std;
//多维数组的列表初始化
void initArray() {
	int arr[][3] = { 
		{2,1,3},
		{2,1,3}
	};
	int arr2[][3] = { 2,1,3,2,1,3 };//以上两种方式完全等价
	int arr3[][4] = { {2},{3},{1} };//初始化了每行的第一个元素

//	int(&row)[3] = arr[1];//row是一个一维数组的引用，指向了arr二维数组的第二行
//	cout << row[0] << "  " << row[1] << "  " << row[2] << endl;

	int arrI[2][3];
	//嵌套循环遍历多维数组
	//需要知道每一层的长度
	constexpr size_t row = 2, col = 3;
	for (size_t i = 0; i != row; i++) {
		for (size_t j = 0; j != col; j++) {
			arrI[i][j] = i*row + j;
		}
	}
	/*for (size_t i = 0; i != row; i++) {
		for (size_t j = 0; j != col; j++) {
			cout << arrI[i][j]<<"   ";
		}
		cout << endl;
	}*/
	//使用rangeFor遍历多维数组
	//除了最内层的循环外，其他所有循环控制变量都应该是引用类型
	//因为如果不是引用类型，编译器会将数组转为指向首元素的指针，那就没法继续使用rangeFor了
	for (auto & row : arrI) {
		for (auto col : row) {
			cout << col << "\t";
		}
		cout << endl;
	}
	//如果需要修改值，那么最内层的循环也要使用引用类型
	for (auto & row : arrI) {
		for (auto&  col : row) {
			col = 21;
		}
	}
	for (auto & row : arrI) {
		for (auto col : row) {
			cout << col << "\t";
		}
		cout << endl;
	}
}
