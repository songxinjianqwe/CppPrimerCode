/*
 * 542accessibleAndExterializable.cpp
 *
 *  Created on: 2016��9��23��
 *      Author: songx
 */

#include <stddef.h>

using namespace std;
//���ʿ�����̳�
//�ܱ�����Ա
//һ����ʹ��protected�ؼ�����������Щϣ��������������ǲ��뱻������������ʹ�õĳ�Ա��
//protected������Ϊpublic��private�кͺ�Ĳ���
//protected��Ա��������û��ǲ��ɷ��ʵ�
//protected��Ա���ڵ�ǰ�������������������Ԫ��˵�ǿɷ��ʵ�
//������ĳ�Ա����Ԫֻ��ͨ����������������ʻ����protected��Ա�����������һ����������е�protected��Աû���κη�����Ȩ
//������ĳ�Ա����Ԫֻ�ܷ�������������еĻ��ಿ�ֵ��ܱ�����Ա��������ͨ�Ļ�������еĳ�Ա����������ķ���Ȩ��
//Ҳ����˵���������Ԫ��ͨ��������ʸ����protected��Ա�����ǲ���ֱ�ӷ��ʸ����protected��Ա
class Base {
	friend class Pal;
protected:
	int protMem = 2;
};
class Sneaky: public Base {
	friend void clobber(Sneaky &);
	friend void clobber(Base &);
private:
	int j = 0;
};
void clobber(Sneaky & s) {
	s.protMem = 0;
}
void clobber(Base & b) {
//	b.protMem = 0;//error
	//������Ԫ����ֱ�ӷ��ʸ����protected��Ա
}

//ĳ�������̳ж����ĳ�Ա�ķ���Ȩ���ܵ���������Ӱ�죺һ���ڻ����иó�Ա�ķ���˵������������������������б��еķ���˵����
class Base2 {
public:
	void pubMem();
protected:
	int protMem;
private:
	char privMem;
};
class Pub: public Base2 {
	int f() {
		return protMem;	//ok
	}
	char g() {
//		return privMem;//error
		return 'c';
	}
};
class Priv: private Base2 {
	int f1() {
		return protMem;	//ok
	}
};
//��������˵��������������ĳ�Ա����Ԫ�ܷ������ֱ�ӻ���ĳ�Աû��Ӱ�죬�Ի���ĳ�Ա�ķ���Ȩ��ֻ������еķ���˵�����й�
//��������˵������Ŀ���ǿ�����������û�������ʹ������˺�������������ࣩ���ڻ���¹ڵķ���Ȩ��
void test8() {
	Pub d1;
	Priv d2;
//	d1.pubMem();//ok
//	d2.pubMem();//error
}
//����̳��ǹ��еģ���ô��Ա����ѭ��ԭ�еķ���˵����������̳���˽�еģ���ô�ӻ����м̳е����г�Ա���ⲿ���������ࣩ���Զ���˽�е�
//����̳���protected�ģ���ô�ӻ����м̳е����г�Ա���ⲿ���������ࣩ���Զ���protected��

class DerivedFromPub: public Pub {
	int useBase() {
		return protMem;
	}
};
class DerivedFromPrivate: public Priv {
	int useBase() {
//		return protMem;//error
		return 0;
	}
};

//�����������ת���Ŀɷ�����(�����ָ������ÿ���ָ��������Ķ���)��
//������������ת���Ƿ�ɷ�����ʹ�ø�ת���Ĵ��������ͬʱ���������������˵����Ҳ����Ӱ��
//class D:public B
//D���м̳�Bʱ���û��������ʹ������������������ת����protected��private�����У�
//����ʲô��ʽ�̳У�D�ĳ�Ա��������Ԫ����ʹ��������������ת��������������ֱ�ӻ��������ת������������ĳ�Ա����Ԫ��˵����Զ�ɷ��ʵ�
//���D�̳�B�ķ�ʽ��public����protected����ôD��������  �ĳ�Ա����Ԫ(ע�ⲻ���û�)����ʹ��D��B������ת����private���ɣ�

//һ�����������û�����ͨ�û������ʵ���ߣ�������
//��ͨ�û�ֻ�ܷ������public��Ա
//���ʵ���߸����д��ĳ�Ա����Ԫ�����Է���������в���
//�����༰����Ԫ���Է��ʻ����public��protected��Ա

//����Ӧ�ý���ӿڳ�Ա����Ϊpublic
//��������ʵ�ֵĲ���Ϊ���飺һ�鹩��������ʣ�����Ϊprotected����һ��ֻ���ɻ���ͻ������Ԫ���ʣ�����Ϊprivate

//��Ԫ��̳�
//��Ԫ���ܴ��ݣ�Ҳ���ܼ̳�
//ֻҪ��ס��ÿ���ฺ����Ƹ��Գ�Ա�ķ���Ȩ��

//��Ԫ��ϵ
class Pal {
public:
	int f(Base b) {
		return b.protMem;
	}
	int f2(Sneaky s) {
		return s.protMem;
	}
	int f3(Sneaky s) {
//		return s.j;//error
		return 0;
	}
};
//һ���ཫ��һ��������Ϊ��Ԫ��ʱ��������Ԫ��ϵֻ����������������Ч������ԭ�����Ǹ�����˵������Ԫ�Ļ�����������಻��������ķ�������

//�ı�����Ա�Ŀɷ����ԣ�
//����������Ҫ�ı�������̳е�ĳ�����ֵķ��ʼ���ͨ��ʹ��using������ʵ��
class Base3 {
public:
	size_t size() const {
		return n;
	}
protected:
	size_t n;
};

class Derived :private Base3{
public:
	using Base3::size;
protected:
	using Base3::n;
};
//��������˽�м̳У�����Base3�ĳ�Ա����private�ģ�using���ı�����Щ��Ա�Ŀɷ����ԡ�
//�ı�֮��Derived�û�����ʹ��size��Ա����Derived�������ཫ����ʹ��n
//ͨ��������ڲ�ʹ��using������䣬���ǿ��Խ������ֱ�ӻ��ӻ����е��κοɷ��ʳ�Ա����˽�г�Ա����ǳ���
//using������������ֵķ���Ȩ���ɸ�using�������֮ǰ�ķ���˵����������
//���using���������������private���֣���ô������ֻ�ܱ���ĳ�Ա����Ԫ����
//���using���������������public���֣���ô��������û����ܷ�����
//���using������������protected���֣���ô�����ֶ��ڳ�Ա����Ԫ�������඼�ǿɷ��ʵġ�

//Ĭ�ϵļ̳б�������
//ð��֮�󲻼ӷ������η���ֱ�ӼӸ������Ļ�ʹ�õ���Ĭ�ϵļ̳б�������
//������������struct�ģ�Ĭ�ϼ̳б���������public�ģ���������class�ģ�Ĭ�ϼ̳б���������private
//������ò�Ҫʹ��Ĭ�ϵģ���Ӧ��ֱ������������
//!     Base *p = &d1;  //  d1 has type Pub_Derv    --  legal   --right
//!     p = &d2;        //  d2 has type Priv_Derv   --  illegal --right
//!     p = &d3;        //  d3 has type Prot_Derv   --  illegal --right
//!
//!     p = &dd1;       //  dd1 has type Derived_from_Public    --  legal   --right
//!     p = &dd2;       //  dd2 has type Derived_from_Private   --  illegal --right
//!     p = &dd3;       //  dd3 has type Derived_from_Protected --  illegal --right
//!
//      User code may use the derived-to-base conversion only if D inherits
//      publicly from B. User code may not use the conversion if D inherits
//      from B using either protected or private.
//�����˵����ֻ��public��ʽ�̳еģ�����ָ������ò���ָ���������

//  Member functions and friends of D can use the conversion to B regardless
//  of how D inherits from B. The derived-to-base conversion to a direct base
//  class is always accessible to members and friends of a derived class.
//  Hence, the 3 below are all legal:
//
//          Pub_Derv    --  legal   --right
//          Priv_Derv   --  legal   --right
//          Prot_Derv   --  legal   --right
//
//  Member functions and friends of classes derived from D may use the
//  derived-to-base conversion if D inherits from B using either public or
//  protected. Such code may not use the conversion if D inherits privately
//  from B.Hence:
//          Derived_from_Public    --  legal    --right
//          Derived_from_Private   --  illegal  --right
//          Derived_from_Protected --  legal    --right
//�����˵�������㣺����̳и��࣬����ʲô��ʽ�̳У�����ĳ�Ա��������Ԫ����ʵ�ָ���ָ�������ָ���������
//����̳и��ֻ࣬��public��private��ʽ�̳У����������ĳ�Ա��������Ԫ����ʵ�ָ���ָ�������ָ���������

void test10(){
	Pub d1;
	Priv d2;
	DerivedFromPub dd1;
	DerivedFromPrivate dd2;
	Base2 * p =  &d1;
//	p = &d2;//error
	p = &dd1;
//	p = &dd2;//error
}

