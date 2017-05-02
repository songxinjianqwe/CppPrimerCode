#include <iostream>
typedef char * pstring;
void testPointer() {
	//const与指针
	//分为两类：指向常量的指针和常量指针
	//第一类：指向常量的指针（底层const）
	//和引用一样，指向常量的指针可以指向一个const修饰的变量，也可以指向一个没有用const修饰的变量
	//但都不能通过指针来修改变量的值
	//一个常量只能由一个指向常量的指针来指向，而不能由非const的指针指向
	//示例
	const int i = 21;
	const int * ptrI = &i;
//	*ptrI = 21;//error
	int i2 = 21;
	ptrI = &i2;//ok
//	*ptrI = 123;//error

	const int i3 = 12;
//	int * ptrI3 = i3;//error

	//第二类：常量指针（顶层const）
	//常量指针的意思就是指针本身是一个常量，必须进行初始化指向一个变量，并且不能指向其他变量
	//常量指针也可以通过指针来修改指向的变量的值
	//示例
	int i4 = 21;
	int * const ptrI4 = &i4;
	int i5 = 2112;
//	ptrI4 = &i5;//error
//	int * const ptrI;//error
	//二者兼而有之的就是指向常量的常量指针，既不能指向其他对象，也不能通过该指针修改指向的变量的值
	const int * const ptr = &i4;

//	const int i5;//error const变量必须进行初始化


	//当执行变量的拷贝操作时，两种情况的区别：常量指针不受影响
	int i6 = 21;
	const int ci7 = 12;
	const int * p2 = &i6;
	const int * const p3 = p2; 
	p2 = p3;//ok p3是常量指针，对p2没有影响
	i6 = ci7;

	//普通指针不能赋指向常量的指针的值，因为可能通过普通指针去修改原变量的值
	//总之，非常量可以转换成常量，反之不行
//	int * p4 = p2;//error
	//对引用，非const的引用也不能引用const变量
//	int & ref = ci7;//error

	//const与类型别名
	char ch = 'A';
	const pstring pstr = &ch;
	//注意，这里和常识有所不同
	//const pstring pstr 相当于 char * const pstr，也就是指向字符的常量指针
	//而错误理解是将其视为const char * pstr，也就是指向常量字符的指针
} 
  