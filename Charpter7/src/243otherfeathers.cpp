#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Screen;
//类的声明：可以先声明一个类而暂时不定义它；这种声明称为前向声明；在类的声明之后定义之前是一个不完全类型
//不完全类型只能在非常有限的情景下使用：可以定义指向该类对象的指针或引用；可以声明（不能定义）以不完全类型为参数或返回类型的函数
//**************************************************************************************************************************************************


//WindowManager 类
//窗口管理器，用于表示显示器上的一组Screen
//开始时就拥有一个默认初始化的Screen
class WindowManager {
private:
	vector<Screen> screens;// = { Screen{ 24,80,' ' } };
public:
	using screenIndex = vector<Screen>::size_type;
	void clear(screenIndex index);
	screenIndex addScreen(Screen &screen);//定义为引用类型可以避免拷贝，就和java一样了
	Screen & getScreen(screenIndex index);
};
//**************************************************************************************************************************************************



//类型成员
//在类中可以自定义某种类型在类中的别名（作用域是类）
//类型别名一般是public的，用户有必要了解别名
//可以用typedef，也可以用using
//用来定义类型的成员必须先定义后使用，因此类型成员一般定义在类的开始
//**************************************************************************************************************************************************
//显示器类
//包含一个保存屏幕内容的string对象和三个pos成员：光标的位置、屏幕的长、屏幕的宽
//**************************************************************************************************************************************************
//可变数据成员：有的时候希望能修改类的某个成员变量，即使是在一个const成员函数中
//mutable关键字指明这个变量是可变的
//一个可变数据成员永远不会是const，即使它是const对象的成员。
//**************************************************************************************************************************************************
//友元类
//可以定义一个类为当前类的友元，那么该类的函数就可以访问当前类的私有成员
//注意友元函数（类外部函数）必须定义在类的外部，友元声明friend在类的内部（也属于类的接口的一部分）
//而友元类的友元函数可以定义在类的内部，也可以定义在类的外部

//另一种友元函数
//除了定义类外部的函数为友元函数之外，还可以定义另一个类的一个成员函数为友元函数(这样只有这个类的这个函数可以访问当前类的私有成员，而不是这个类的所有函数)
//有以下程序结构的限制，必须按顺序进行：
//1.声明当前类Screen
//2.定义友元类WindowManager，声明友元函数clear，但不定义
//3.定义当前类Screen，包括友元函数的声明
//4.定义友元函数clear（类外定义）
//**************************************************************************************************************************************************
class Screen {
	friend class WindowManager;//声明友元类 friend class className
	friend void WindowManager::clear(screenIndex index);//声明友元函数
public:
	using pos = string::size_type;
	Screen() = default;//默认构造函数
	Screen(pos height, pos weight, char c) :height(height), width(weight), contents(height*weight, c), cursorPos(0) {}
	//contents默认为全屏幕的字符c
	Screen(pos height, pos weight) :height(height), width(weight), contents(height*weight, ' '), cursorPos(0) {}

	char get() const {
		return contents[cursorPos];//返回光标所在位置的字符，隐式内联
	}
	inline char get(pos row, pos col) const {
		return contents[row*width + col];//返回给出的行列的字符，显式内联
	}
	Screen & set(char ch) {//设置光标处的字符
		contents[cursorPos] = ch;
		return *this;
	}

	Screen & set(pos row, pos col, char ch) {//设置指定行列的字符
		contents[row*width + col] = ch;
		return *this;
	}
	//如果是返回对象，那么将返回值修改为Screen即可，这样的话就不能修改对象的值了（因为返回的是拷贝值，而非指向该对象）
	//从这里来看，c++的引用类似于java的引用，只有返回引用类型才能修改值；直接返回对象实际上返回的是对象的拷贝

	//*************************************************
	Screen & move(pos row, pos col);//在类的外部进行定义，作用是将光标移动到指定行列
	pos size()  const;

	//void someFunc() const {
	//	accessCounter++;
	//	//other code
	//}

	//*************************************************
	//从const成员函数返回*this
	//Screen对象可能是常量的，也可能是非常量的：常量对象只能调用常量函数，不能调用非常量函数；非常量对象没有限制。
	//在const成员函数中this也被视为是一个指向常量的常量指针，*this可以被视为一个常量的引用
	//但是如果返回的是常量引用，就不能用它来继续修改对象了。
	//我们可以基于const进行重载成员函数，同样的成员函数可以根据有无const来进行重载
	//它的区别是返回值类型，const成员函数返回的是常量引用，非const成员函数返回的是普通引用
	//我们想实现一个display方法，显示contents字符串，有时Screen对象是一个非常量，显示之后可以继续修改，有时Screen对象是一个常量不进行修改，因此我们需要进行重载
	//这两个重载的函数有一个共同的部分就是显示字符串，因此将它抽象出来，定义为private的doDisplay函数。
	//抽象出来的函数要定义为const函数，原因和指针与const的关系差不多：非常量可以指向常量，常量不能指向非常量
	//因此display的非常量版本调用doDisplay时，非常量指针this隐式转为常量指针。
	Screen & display(ostream & os) {
		doDisplay(os);
		return *this;
	}
	const Screen & display(ostream & os) const {
		doDisplay(os);
		return *this;
	}
private:
	pos cursorPos;//光标位置
	pos height;
	pos width;
	string contents;
	mutable int accessCounter;//用于记录一个函数的调用次数
	void doDisplay(ostream & os) const {
		os << contents;
	}
};
//定义在外部的非成员函数也可以声明为内联的
//注意类和::放在函数名之前，返回类型之后
//对于非成员函数而言，内联函数inline声明只写在定义即可，类内部的声明不必加inline了。
inline Screen & Screen::move(pos row, pos col) {
	cursorPos = row*width + col;
	return *this;//返回引用就是让返回值可以作为左值
}
Screen::pos Screen::size() const {
	return height*width;
}
//**************************************************************************************************************************************************
//这些都是WindowManager的函数，因为它们都要用到screen，所以定义在类的外部，Screen的定义之后

//类的作用域：每个类都有自己的作用域，就是类的内部。
//对于类类型成员使用作用域运算符访问
//在类的外部定义成员函数：一旦遇到类名，定义的剩余部分（参数、函数体）就在类的作用域之内了，可以直接使用类的其他成员
//而函数的返回类型在类名之前，所以如果返回类型是在类内定义的，那么就需要在返回类型前加上类名和作用域运算符::
void WindowManager::clear(screenIndex index) {
	Screen & screen = screens[index];//定义为引用就可以修改值了
	screen.contents = string(screen.width*screen.height, ' ');//重新定义string
}
WindowManager::screenIndex WindowManager::addScreen(Screen &screen) {
	screens.push_back(screen);
	return screens.size() - 1;
}
Screen & WindowManager::getScreen(screenIndex index) {
	return screens[index];
}
//**************************************************************************************************************************************************
void test() {
	//Screen screen(80,24);
	//screen.move(4, 0).set('#');//返回自身的引用的作用就是可以将函数的返回值作为左值，继续调用（链式调用）
	//Screen myScreen(5, 3);
	//myScreen.set('#').display(cout);
	//const Screen blank(5, 3);//仅仅指向一个白板，不再修改这块屏幕上的内容
	//blank.display(cout);
	Screen myScreen(5, 5, 'X');
	myScreen.move(4, 0).set('#').display(cout);
	cout << endl;

	WindowManager mgr;
	WindowManager::screenIndex i = mgr.addScreen(myScreen);
	mgr.clear(i);
	myScreen = mgr.getScreen(i);
	myScreen.display(cout);
	cout << endl;
	cout << myScreen.size() << endl;

}
int main(void) {
	test();
	return 0;
}
