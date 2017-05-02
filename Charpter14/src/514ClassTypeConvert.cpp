/*
 * 514ClassTypeConvert.cpp
 *
 *  Created on: 2016��9��17��
 *      Author: songx
 */

#include <iostream>
using namespace std;

//�������ת��
//��һ������תΪ��һ����Ķ�����ͨ����Ĺ��캯��ʵ�ֵģ�������ʽ�ؽ�һ������תΪ��Ķ���
//������캯����Ϊ��ʽ���캯��
//�����Խ���Ķ���תΪ��һ������ʹ�õ�������ת�������

//����ת������������һ�������Ա����������һ����Ķ���תΪ�������͡�
//��ʽ���£�operator type() const;
//type ��Ŀ������
//����ת����������������������ͽ��ж��壨��void����ֻҪ����������Ϊ�����ķ�������
//���ǲ�����תΪ���������������תΪָ�루����ָ�롢����ָ�룩����������

//����ת�������û����ʽ�ķ������ͣ�û���βΣ����ұ���Ϊ��Ա������ͨ������²�Ӧ���޸Ķ������Զ���Ϊconst
//ʵ����
class SmallInt {
public:
	SmallInt(int i = 0) :
			val(i) {
		if (i < 0 || i > 255) {
			throw out_of_range("Bad SmallInt Value");
		}
	}
	operator int() const {
		return val;
	}
private:
	size_t val;
};

//SmallInt�������������͵�ת������intתΪSmallInt,��SmallIntתΪint
//Ĭ������¶�����ʽ��ת��
void test70() {
	SmallInt si;
	si = 4; //���Ƚ�4��ʽתΪSmallInt��Ȼ�����SmallInt::operator=
	si + 3; //���Ƚ�si��ʽתΪint��Ȼ��ִ�������ӷ�
}
//������һ��ִ��ִ��һ���û����������ת��
//������ʽ���������ת�����Է���һ����ʽ���õ�����ת��֮ǰ��֮�󣨱����������͵�ֵ֮���ת����
//��ˣ����ǿ��Խ��κ��������ʹ��ݸ�SmallInt�Ĺ��캯����Ҳ��ʹ������ת���������һ��SmallInt����תΪint��Ȼ��intתΪ������������
void test71() {
	SmallInt si = 3.14;
	si + 3.14; //ok
}
//ʹ������ת�������ʱҪע�⣺������߲������ϸ��һ��һ�Ĺ�ϵ����ô��ò�Ҫ���塣
//������������ת���Ĵ��ڣ����Ե�������תΪbool������ת���������Ҳ�п�����Ϊint��ʹ��

//Ϊ�˱��������������������ʽ������ת�������
class SmallInt2 {
public:
	SmallInt2(int i = 0):val(i) {
		if(i<0 || i >255) {
			throw out_of_range("Bad SmallInt Value");
		}
	}
	explicit operator int() const {
		return val;
	}
	explicit operator bool() const{
		return val;
	}
private:
	size_t val;
};
//����explicit֮�󣬾��޷�ʵ����ʽ������ת���ˣ�����ʹ��static_cast<T>��ʵ����ʽ����ת��
//һ�������ǣ��������������������ô��Ȼ����ʽ��ִ������ת��
//if while do...while for(;;) ! && || ?:
//תΪbool:��bool��ת��ͨ�������������֣����operator bool()һ�㶨��Ϊexplicit
void test72() {
	SmallInt2 si2 = 3;
//	si + 3;//error
	static_cast<int>(si2) + 3; //ok
	if(si2){
		cout<<"True"<<endl;
	}
}


