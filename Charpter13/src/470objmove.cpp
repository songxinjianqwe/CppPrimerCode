/*
 * 470objmove.cpp
 *
 *  Created on: 2016年9月14日
 *      Author: songx
 */

#include <algorithm>
#include <vector>

using namespace std;


//移动而非拷贝对象会大幅度提高性能
//使用移动而非拷贝的另一个原因是IO类或unique_ptr这样的类。这些类包含不能被共享的资源，因此这些类型的对象不能拷贝但可以移动。
//我们可以用容器保存不可拷贝的类型，只要它们能被移动即可。

//标准库容器、string、shared_ptr既支持移动也支持拷贝。IO类和unique_ptr可以移动但不可拷贝。

//右值引用
//右值引用就是必须绑定到右值的引用。我们通过&&来获得右值引用。
//右值引用只能绑定到一个将要销毁的临时对象，因此我们可以将一个右值引用的资源移动到另一个对象中。

//左值和右值是表达式的属性。一个左值表达式表示的是一个对象的身份，一个右值表达式表示的是对象的值。
//右值引用也是某个对象的别名。以前接触的引用都是左值引用。我们可以将一个右值引用绑定到（表达式、字面常量、返回右值的表达式）这些对象上，但不能将一个右值引用绑定到一个左值上。

//返回左值引用的函数（&），连同赋值、下标、解引用、前置递增递减运算符，返回的都是左值表达式，可以将左值引用绑定到这类表达式的结果上。（变量也是左值表达式）
//返回非引用类的函数（无&），连同算术、关系、位以及后置递增递减运算符，返回的都是右值表达式，可以将一个const的左值引用或右值引用绑定到这类表达式的结果上。（字面量也是右值表达式）

//左值持久；右值短暂：左值有持久的状态，而右值要么是字面常量，要么是在表达式求值过程中创建的临时对象
//右值引用只能绑定到临时对象：所引用的对象将要被销毁；该对象没有其他用户。
//！！！使用右值引用的代码可以自由地接管所引用的对象的资源！！！


//函数返回的右值在表达式语句结束后，其生命也就终结了（通常我们也称其具有表达式生命期），
//而通过右值引用的声明，该右值又“重获新生”，其生命期将与右值引用类型变量a的生命期一样。

//std::move的作用是强制一个左值成为右值引用,定义在utility头文件中
//调用move就意味着承诺：除了对源对象赋值或销毁它之外，我们将不再使用它的值。
//左值是持久的，不会自动销毁，因此只能我们自己保证像使用一个右值一样来使用左值，也就是不知道也不使用它的值，

void test30(){
	int i = 32;
	int && rightRef1 = 42;
//	int && rightRef2 = i;//error
	
	int && rightRef3 = std::move(i);
}
int f(){
	return 1;
}
void test31(){
		vector<int> iVec(10);
	int val = f();
	int rr1 = f();
	int & r1 = iVec[0];
	int & r2 = val;
	int && rr2 = iVec[0]*f();
}
