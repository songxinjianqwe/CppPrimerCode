#include <iostream>
#include <vector>
#include <cctype>
using namespace std;
//除非必须，否则不使用递增递减运算符的后置版本
//因为前置版本运算后直接返回，而后置版本需要将原始值存储下来以便于返回这个未修改的内容，如果不需要修改前的内容，那就是一种浪费
//建议养成使用前置版本的习惯

//混用解引用和递增运算符
//后置递增运算符优先级高于解引用运算符

//如果一条子表达式改变了某个运算对象的值，另一条子表达式又要使用该值的话，运算对象的求值顺序就很关键。

//成员访问运算符 p是一个指针，如果p指向一个类的对象或结构体对象，那么(*p).member == p->member
//解引用运算符的优先级低于点运算符，所以必须要加上一个括号

//条件运算符 ?:的优先级非常低，整体要加上括号，否则编译器会报错
void simplify() {
	vector<int> iVec = { 2,2,3,-2,1,2,4 };
	auto begin = iVec.begin();
	while (begin != iVec.end()) {
		cout << *begin++ << endl;
	}
	//*begin++ 就等价于 *(begin++)
	//先将begin+1，然后返回begin的初始值的副本作为求值结果，然后解引用运算符的运算对象是begin未增加之前的值
	//效果是先访问值，后移动
	//begin = iVec.begin();
	//while (begin != iVec.end()) {
	//	*begin = toupper(*begin++);
	//	//这里是有问题的，在两个地方都用到了begin的值，该赋值语句是未定义的，其结果取决于编译器
	//}
	int val = -1;
	cout << (val++ && val) << endl;
	//注意 这个++的赋值在&&之前就生效了，&&和||都属于关节点

	//条件运算符
	int grade = 23;
	cout << (grade < 60 ? "fail" : "pass" )<< endl;
}
