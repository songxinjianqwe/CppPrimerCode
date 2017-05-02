/*
 * 595MemberTemplate.cpp
 *
 *  Created on: 2016��9��29��
 *      Author: songx
 */

#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

//��Աģ��
//һ���ࣨ�����Ƿ�����ģ�壩���԰���������ģ��ĳ�Ա���������ֳ�Ա����Ϊ��Աģ�塣��Աģ�岻�����麯��
//���Ƕ��� һ���࣬������unique_ptr��ʹ�õ�Ĭ��ɾ�������͡�
//������һ�����صĺ������������������һ��ָ�벢�Դ�ָ��ִ��delete������
//����ϣ��ɾ�����������κ����ͣ���˽��õ������������Ϊһ��ģ��

class DebugDelete{
public:
	DebugDelete(ostream & s = cerr):os(s){}
	template<typename T> 
	void operator()(T * p)const{
		os<<"deleteing unique_ptr"<<endl;
		delete p;
	}
	
private:
	ostream & os;
};
//��Աģ��ʱ��ģ������б�ʼ��
void test30(){
	double * p = new double;
	DebugDelete d;
	d(p);
	int * ip = new int;
	DebugDelete()(ip);//����һ����ʱ��DebugDelete����
}
//���ǿ��Խ�DebugDelete����unique_ptr��ɾ����
void test31(){
	unique_ptr<int,DebugDelete> p(new int,DebugDelete());
	unique_ptr<string,DebugDelete> sp(new string,DebugDelete());
	//���ۺ�ʱunique_ptr����������ʵ����ʱ��DebugDelete�ĵ������������ʵ����
}

//������ģ�壬����Ҳ����Ϊ�䶨���Աģ�壻�ڴ�����£���ͳ�Ա�������Լ��ġ�������ģ�������
//Blob�ࣺΪ�䶨��һ�����캯����������������������Ϊϣ�����ܲ�ͬ���͵ĵ����ޣ���˽����캯������Ϊģ��

template<typename T>class Blob{
public:
	template<typename It> Blob(It begin,It end);
	Blob() = default;
private:
	shared_ptr<vector<T>> data;
};
//����������ģ���ⶨ��һ����Աģ��ʱ������ͬʱΪ��ģ��ͳ�Աģ���ṩģ������б���ģ��Ĳ����б���ǰ�������Ա�Լ���ģ������б�
template<typename T>
template<typename It>
Blob<T>::Blob(It begin,It end):data(make_shared<vector<T>>(begin,end)){}


//Ϊ��ʵ����һ����ģ��ĳ�Աģ�壬���Ǳ���ͬʱ�ṩ��ͺ���ģ���ʵ��
void test32(){
	vector<int> iVec = {0,1,2,3};
	Blob<int> b(iVec.begin(),iVec.end());
	int arr[] = {1,2,3,4};
	Blob<int> b2(begin(arr),end(arr));
}

//***********************************************************************************************************

//����ʵ����
//��ģ�屻ʹ��ʱ�Ż����ʵ������
//��һ������ζ����ͬ��ʵ�����ܳ����ڶ�������ļ��С��������������������Դ�ļ�ʹ������ͬ��ģ�壬���ṩ����ͬ��ģ�����ʱ��ÿ���ļ��оͶ����и�ģ���һ��ʵ��
//�ڴ�ϵͳ�У��ڶ���ļ���ʵ������ͬģ��Ķ��⿪�����ܷǳ����ء����±�׼�У����ǿ���ͨ����ʽʵ�������������ֿ�����
//һ����ʽʵ���������¸�ʽ��
//template declaration
//extern template declaration

//��һ���ļ��У�����һ�Σ�
template class Blob<string>;//ʵ��������
//�ڶ���ļ��У����Գ��ֶ�Σ�
extern template class Blob<string>;//ʵ��������

//������������externʵ��������ʱ���������ڱ��ļ�������ʵ�������롣��һ��ʵ��������Ϊextern�ͳ�ŵ�ڳ�������λ���и�ʵ�������壨������extern�ģ�
//����һ��������ʵ�����汾�������ж��extern��������ֻ��һ��ʵ�������塣

//���ڱ�������ʹ��һ��ģ��ʱ�Զ�����ʵ����������extern��������������κ�ʹ�ô�ʵ�����汾�Ĵ���֮ǰ��

/////////////////////////////////////////////////
//pplication.cpp 
extern template class Blob<string>;//���ں�����
void test35(){
	//����Ϊʵ��������
	Blob<string> s1,s2;
	Blob<int> a1;
}

//templateBulid.cpp
//template class Blob<string>;

//////////////////////////////////////////////////

//������������һ��ʵ��������ʱ������Ϊ�����ɴ��롣
//�����Ǳ����Ӧ�ó���ʱ�����뽫Application.o��templateBuild.o���ӵ�һ��
//��ĳ��ʵ����������������ĳ��λ�ñ���������ʽ�Ե�ʵ��������


//һ����ģ���ʵ���������ʵ������ģ������г�Ա�����������ĳ�Ա������������������һ��ʵ�������壬�����˽�����ʹ����Щ��Ա������
//��ˣ��봦����ģ�����ͨʵ������ͬ����������ʵ������������г�Ա����ʹ���ǲ�ʹ��ĳ����Ա����Ҳ�ᱻʵ������
//��ˣ�����������ʽʵ����һ����ģ������ͣ�����������ģ������г�Ա��

//��һ����ģ���ʵ���������У��������ͱ���������ģ������г�Ա������









