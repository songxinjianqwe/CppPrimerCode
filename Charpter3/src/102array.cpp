#include <iostream>
#include <string>
#include <vector>
using namespace std;
//数组int arr[size]
//指针数组 int * arr[size]
//如果是采用列表初始化方式，不一定需要显式加上size
//如果只是数组的声明，那么必须加上长度。并且这个长度必须为字面量如10，或者常量const，或者常量表达式constexpr

//注意数组的初始化：一定要采用某种初始化方式，如果不知道要放入什么元素，那么可以写一个空的花括号，表示全部初始化为0或空；不写的话就需要手动初始化为0
//列表初始化中没有涉及的元素也会被初始化为0或空

//如果数组定义在函数外部，那么元素初始化为0系
//如果数组定义在函数内部，那么元素是未定义的值

//字符数组比较特殊
//如果采用列表初始化，那么最后要介绍\0结束符
//如果采用字符串字面量，那么最好不要显式加上size，如果要加的话size = 字符串长度 + 1 （\0）

//不允许数组之间的赋值
//存在指针数组，但是不存在引用数组
//存在数组指针和数组引用，指向一个数组  要求声明时要加上长度，并且和数组的长度一致

void array() {
	size_t size = 10;
//	int arr5[size];//error
	const size_t sz = 20;
	int arr6[sz];//ok

	constexpr size_t size2 = 10;
	int arr7[size2];//ok

	//	int arr[] = { 0,1,2 };
	int arr2[5] = { 2,3,1 };
	char arr3[] = { 'C','+','+' };
	char arr4[] = "C++";
	//	char arr5[] = arr4;//error
	
	int arr[5];
	int(*pArr)[5] = &arr;//数组指针
	int(&rArr)[5] = arr;//数组引用
	//区分指针数组和数组指针就是类型装饰符
	//类型修饰符从右向左依次绑定，而从内向外可以帮助理解它们的区别
	//比如括号中的 *pArr/&rArr 指的是一个指针或引用，括号外的是它们指向的类型，即int[5]

	int *arrPtr[5];//指针数组
	int *(&rArrPtr) [5] = arrPtr;//这是一个数组引用，指向一个指针数组
	//命名的话arr之前表示了它的类型，如果是指针，那么前缀为p；如果是引用，那么前缀为r 
	//arr之后表示了它元素类型，如果是指针，那么后缀为ptr

}

//数组的访问
//数组可以使用rangeFor语句和下标来访问
//数组的下标类型为size_t
void testVisit() {
	constexpr size_t size = 10;

	int scores[11] = {};//定义11个元素
	int grades[] = { 100,23,12,42,24,66,45,88,56,86,90,96,77,86,77,66 };
	for (auto grade : grades) {
		scores[grade / 10]++;
	}
	for (int i = 0; i < 11; i++) {
		cout << i * 10 << "-" << (i == 10 ? 100 : (i + 1) * 10) << ":" << scores[i] << endl;
	}
}
