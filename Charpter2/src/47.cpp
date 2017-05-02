#include <cstdlib>
#include <iostream>

using namespace std;
void test(){
	//指针不同于引用，可以不进行初始化，可以指向多个变量，可以初始化为一个字面量（直接给出变量地址，前提是include cstdlib）
	//但是指针最好进行初始化，否则会引发灾难；如果不知道应该指向谁，就先初始化为空指针nullptr
	//指针和它所指向类型和引用一样，必须相同
	int val = 32;
	//指针指向一个对象需要使用&取地址符来取得变量的地址
	int * valPtr = &val;
	//指针不可指向一个引用（因为引用不是对象，没有实际地址）
	//允许指针之间相互赋值，相当于多个指针指向同一个变量
	//将变量的地址赋给指针的话，前提是它们的类型相同
	//不能将变量的值赋给一个指针
	double d = 23;
	double * dPtr = &d;
	//通过指针访问变量的值，使用运算符 解引用符*
	cout << *dPtr << endl;
	cout << dPtr << endl;//也可以直接访问指针，它的值是所指向变量的内存地址
	*dPtr = 2121;//可以通过指针来修改指向变量的值
	cout << d << endl << endl;

	//指针没有初始化的时候它的属于无效指针，访问无效指针一定会出错
	//可以将指针的值赋给空指针nullptr
	dPtr = nullptr;//这里的nullptr相当于java的null
				   //也可以将指针的值赋为NULL，也是空指针的意思，另外一个等价的做法是将指针的值赋为字面量0（都需要include）
	dPtr = NULL;
	dPtr = 0;
	//	cout << *dPtr << endl;//空指针不可以进行访问，会出错
	//推荐使用nullptr的方式来赋值空指针，其他方式不推荐

	//指针和引用之间的一种赋值方式
	int i = 2;
	int * ptrI = &i;
	int & refI = *ptrI;//先是解引用，得到i，然后赋给引用
	cout << refI << endl;
	//只要指针拥有一个合法值，就可以放在条件语句中，如果非空，那么true；如果为空，那么false

	//void类型指针
	//可以存放任意类型对象的地址
	//只能:和其他指针比较；作为函数的输入输出；赋给另外一个void*指针
	//不能直接操作void*类型指针
	void * ptr = &i;

	//一次定义多个变量
	int *ptrI2, i2;//定义了一个int*的ptrI2指针变量，一个int类型的i2变量

				   //多级指针
	int i3 = 21;
	int * ptrI3, **ppI3;
	ptrI3 = &i3;
	ppI3 = &ptrI3;
	cout << *ptrI3 << "   " << **ppI3 << endl << endl;
	//指向指针的引用，相当于指针的别名
	int i4 = 12;
	int *ptrI4;
	int * & refPtrI4 = ptrI4;//refPtrI4 是一个指向ptrI4的引用，不可修改
	refPtrI4 = &i4;//将i4的地址赋给ptrI4,ptrI4指向i4
	cout << *ptrI4 << endl;
	*refPtrI4 = 0;//*ptrI4的值为0，也就是i4 = 0
	cout << i4 << endl;
	//如何查看一个变量的类型？从右向左看，离变量名最近的符号对变量的类型有最直接的影响，比如int * & refPtrI4就是一个引用类型,引用的是一个int*指针
}
