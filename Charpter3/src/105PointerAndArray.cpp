#include <iostream>
#include <string>
#include <vector>
using namespace std;
//指针与数组
//数组名即为数组头元素指针
//注意：不能将一个指针赋给数组

//指针也可以作为迭代器
//当指针指向数组某一元素时，指针++就表示指向数组的下一个元素
//有两个函数begin和end，传入一个数组，返回数组的头元素指针和最后一个元素的下一个元素的指针
//这两个函数与vector的方法不同，不是定义在类中的，是定义在标准库中的
//使用这种方式就可以仿照vector的迭代器方式，使用指针来访问数组

//指针也可以进行加减运算，加一表示前进一个元素的位置，减一表示后退一个元素的位置（也可以对数组名进行加减，因为数组名本身就是指向头元素的指针）
//指针之间也可以相减，前提是指向同一个数组：相减的结果就是它们之间的距离（下标之差），这个结果的类型是ptrdiff_t，使用auto表示即可
//如果是空指针，那么可以加上一个值为0的常量表达式；空指针也可以相减，结果为0

//!!!
//注意 vector模板和string中的下标访问下标必须大于等于0，而数组的下标访问不限制，小于0也可以
void testPtr() {
	int arr[] = { 212,4213,123,123,45 };
//	cout << *arr << endl;//输出212
	int * begin = std::begin(arr);
	int * end = std::end(arr);
	//使用begin、end获取指针来遍历数组
	for (int *begin = std::begin(arr); begin != std::end(arr); begin++) {
		cout << *begin << endl;
	}
//	cout << arr[5] << endl;数组越界时该地址的值为未定义值
	int *pStart = arr;
	int *pEnd = arr + sizeof(arr) / sizeof(arr[0]);//pArr指向数组的最后一个元素的下一个元素，不可解引用
	//使用另一种方式遍历数组
	while (pStart < pEnd) {
		cout << *pStart << endl;
		pStart++;
	}
	cout << endl;
	//解引用与指针运算的区别
	int last = *(arr + 4);//last为最后一个元素的值
	cout << last << endl;
	last = *arr + 4;//last为第一个元素的值+4
	cout << last << endl;

	//下标与指针
	int *p = &arr[3];//p指向数组中的第四个元素
	//指针也可以使用下标运算符，用法和数组名一致
	cout << p[1] << endl;//p[0]指向第四个元素，p[1]就是指向第五个元素
	cout << *(p + 1) << endl;//*(p+n) == p[n]
	cout << p[-2] << endl;//下标未必一定大于0，当小于0时就往后退，-2就是退两个位置，指向第二个元素

}
