#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Screen;
//�������������������һ�������ʱ��������������������Ϊǰ�����������������֮����֮ǰ��һ������ȫ����
//����ȫ����ֻ���ڷǳ����޵��龰��ʹ�ã����Զ���ָ���������ָ������ã��������������ܶ��壩�Բ���ȫ����Ϊ�����򷵻����͵ĺ���
//**************************************************************************************************************************************************


//WindowManager ��
//���ڹ����������ڱ�ʾ��ʾ���ϵ�һ��Screen
//��ʼʱ��ӵ��һ��Ĭ�ϳ�ʼ����Screen
class WindowManager {
private:
	vector<Screen> screens;// = { Screen{ 24,80,' ' } };
public:
	using screenIndex = vector<Screen>::size_type;
	void clear(screenIndex index);
	screenIndex addScreen(Screen &screen);//����Ϊ�������Ϳ��Ա��⿽�����ͺ�javaһ����
	Screen & getScreen(screenIndex index);
};
//**************************************************************************************************************************************************



//���ͳ�Ա
//�����п����Զ���ĳ�����������еı��������������ࣩ
//���ͱ���һ����public�ģ��û��б�Ҫ�˽����
//������typedef��Ҳ������using
//�����������͵ĳ�Ա�����ȶ����ʹ�ã�������ͳ�Աһ�㶨������Ŀ�ʼ
//**************************************************************************************************************************************************
//��ʾ����
//����һ��������Ļ���ݵ�string���������pos��Ա������λ�á���Ļ�ĳ�����Ļ�Ŀ�
//**************************************************************************************************************************************************
//�ɱ����ݳ�Ա���е�ʱ��ϣ�����޸����ĳ����Ա��������ʹ����һ��const��Ա������
//mutable�ؼ���ָ����������ǿɱ��
//һ���ɱ����ݳ�Ա��Զ������const����ʹ����const����ĳ�Ա��
//**************************************************************************************************************************************************
//��Ԫ��
//���Զ���һ����Ϊ��ǰ�����Ԫ����ô����ĺ����Ϳ��Է��ʵ�ǰ���˽�г�Ա
//ע����Ԫ���������ⲿ���������붨��������ⲿ����Ԫ����friend������ڲ���Ҳ������Ľӿڵ�һ���֣�
//����Ԫ�����Ԫ�������Զ���������ڲ���Ҳ���Զ���������ⲿ

//��һ����Ԫ����
//���˶������ⲿ�ĺ���Ϊ��Ԫ����֮�⣬�����Զ�����һ�����һ����Ա����Ϊ��Ԫ����(����ֻ������������������Է��ʵ�ǰ���˽�г�Ա�����������������к���)
//�����³���ṹ�����ƣ����밴˳����У�
//1.������ǰ��Screen
//2.������Ԫ��WindowManager��������Ԫ����clear����������
//3.���嵱ǰ��Screen��������Ԫ����������
//4.������Ԫ����clear�����ⶨ�壩
//**************************************************************************************************************************************************
class Screen {
	friend class WindowManager;//������Ԫ�� friend class className
	friend void WindowManager::clear(screenIndex index);//������Ԫ����
public:
	using pos = string::size_type;
	Screen() = default;//Ĭ�Ϲ��캯��
	Screen(pos height, pos weight, char c) :height(height), width(weight), contents(height*weight, c), cursorPos(0) {}
	//contentsĬ��Ϊȫ��Ļ���ַ�c
	Screen(pos height, pos weight) :height(height), width(weight), contents(height*weight, ' '), cursorPos(0) {}

	char get() const {
		return contents[cursorPos];//���ع������λ�õ��ַ�����ʽ����
	}
	inline char get(pos row, pos col) const {
		return contents[row*width + col];//���ظ��������е��ַ�����ʽ����
	}
	Screen & set(char ch) {//���ù�괦���ַ�
		contents[cursorPos] = ch;
		return *this;
	}

	Screen & set(pos row, pos col, char ch) {//����ָ�����е��ַ�
		contents[row*width + col] = ch;
		return *this;
	}
	//����Ƿ��ض�����ô������ֵ�޸�ΪScreen���ɣ������Ļ��Ͳ����޸Ķ����ֵ�ˣ���Ϊ���ص��ǿ���ֵ������ָ��ö���
	//������������c++������������java�����ã�ֻ�з����������Ͳ����޸�ֵ��ֱ�ӷ��ض���ʵ���Ϸ��ص��Ƕ���Ŀ���

	//*************************************************
	Screen & move(pos row, pos col);//������ⲿ���ж��壬�����ǽ�����ƶ���ָ������
	pos size()  const;

	//void someFunc() const {
	//	accessCounter++;
	//	//other code
	//}

	//*************************************************
	//��const��Ա��������*this
	//Screen��������ǳ����ģ�Ҳ�����Ƿǳ����ģ���������ֻ�ܵ��ó������������ܵ��÷ǳ����������ǳ�������û�����ơ�
	//��const��Ա������thisҲ����Ϊ��һ��ָ�����ĳ���ָ�룬*this���Ա���Ϊһ������������
	//����������ص��ǳ������ã��Ͳ��������������޸Ķ����ˡ�
	//���ǿ��Ի���const�������س�Ա������ͬ���ĳ�Ա�������Ը�������const����������
	//���������Ƿ���ֵ���ͣ�const��Ա�������ص��ǳ������ã���const��Ա�������ص�����ͨ����
	//������ʵ��һ��display��������ʾcontents�ַ�������ʱScreen������һ���ǳ�������ʾ֮����Լ����޸ģ���ʱScreen������һ�������������޸ģ����������Ҫ��������
	//���������صĺ�����һ����ͬ�Ĳ��־�����ʾ�ַ�������˽����������������Ϊprivate��doDisplay������
	//��������ĺ���Ҫ����Ϊconst������ԭ���ָ����const�Ĺ�ϵ��ࣺ�ǳ�������ָ��������������ָ��ǳ���
	//���display�ķǳ����汾����doDisplayʱ���ǳ���ָ��this��ʽתΪ����ָ�롣
	Screen & display(ostream & os) {
		doDisplay(os);
		return *this;
	}
	const Screen & display(ostream & os) const {
		doDisplay(os);
		return *this;
	}
private:
	pos cursorPos;//���λ��
	pos height;
	pos width;
	string contents;
	mutable int accessCounter;//���ڼ�¼һ�������ĵ��ô���
	void doDisplay(ostream & os) const {
		os << contents;
	}
};
//�������ⲿ�ķǳ�Ա����Ҳ��������Ϊ������
//ע�����::���ں�����֮ǰ����������֮��
//���ڷǳ�Ա�������ԣ���������inline����ֻд�ڶ��弴�ɣ����ڲ����������ؼ�inline�ˡ�
inline Screen & Screen::move(pos row, pos col) {
	cursorPos = row*width + col;
	return *this;//�������þ����÷���ֵ������Ϊ��ֵ
}
Screen::pos Screen::size() const {
	return height*width;
}
//**************************************************************************************************************************************************
//��Щ����WindowManager�ĺ�������Ϊ���Ƕ�Ҫ�õ�screen�����Զ���������ⲿ��Screen�Ķ���֮��

//���������ÿ���඼���Լ��������򣬾�������ڲ���
//���������ͳ�Աʹ�����������������
//������ⲿ�����Ա������һ�����������������ʣ�ಿ�֣������������壩�������������֮���ˣ�����ֱ��ʹ�����������Ա
//�������ķ�������������֮ǰ������������������������ڶ���ģ���ô����Ҫ�ڷ�������ǰ���������������������::
void WindowManager::clear(screenIndex index) {
	Screen & screen = screens[index];//����Ϊ���þͿ����޸�ֵ��
	screen.contents = string(screen.width*screen.height, ' ');//���¶���string
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
	//screen.move(4, 0).set('#');//������������õ����þ��ǿ��Խ������ķ���ֵ��Ϊ��ֵ���������ã���ʽ���ã�
	//Screen myScreen(5, 3);
	//myScreen.set('#').display(cout);
	//const Screen blank(5, 3);//����ָ��һ���װ壬�����޸������Ļ�ϵ�����
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
