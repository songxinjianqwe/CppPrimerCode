#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

using namespace std;

//��������
//��Ȼiostream��������������׼�ⶨ���˿���������ЩIO���Ͷ���ĵ����� 
//istream_iterator ��ȡ��������ostream_iterator �������д����
//������ǿ���ʹ�÷����㷨���������ж�ȡ�����Լ�����д������

//��������ʱ��Ҫ�������Ͳ���

//һ��istream_iterator ʹ��>>����ȡ�������istream_iterator Ҫ��ȡ�����ͱ��붨�������������
//������һ��istream_iterator �����ǿ��Խ����󶨵�һ�����������Զ������Ĭ�ϳ�ʼ�����൱��β�������
//ʹ��++���ƶ�����һ��λ�ã�ʹ��*��ȡ��ֵ
//val = *it ��ʾ�����ж�������

//�������Ѿ�����һ�����������������õ���������һ������
void test39(){
	istream_iterator<int> isIter(cin),eof;
	vector<int> iVec;
	while(isIter != eof){
		iVec.push_back(*isIter++);
	}
	
	//ʹ�������+copy����+����������ʵ�ֽ������е�ֵ�������������Ҳ���Ǵ�ӡ����
	ostream_iterator<int> osIter(cout,"\t");
	copy(iVec.cbegin(),iVec.cend(),osIter);
	cout<<endl;
}

//�򻯺�Ĵ������£�
void test40(){
	istream_iterator<int> it(cin),eof;
	vector<int> iVec(it,eof);//��������������������һ����������������ĵ���������������������������������������	

	ostream_iterator<int> osIter(cout,"\t");
	copy(iVec.cbegin(),iVec.cend(),osIter);
	cout<<endl;
}

//ʹ���㷨������������������������֧��ĳЩ����������
//accumulate����
void test41(){
	istream_iterator<int> isIter(cin),eof;
	cout<<accumulate(isIter,eof,0)<<endl;
}
//������ֵ
//�����ǽ�һ��istream_iterator�󶨵�һ������֮�󣬱�׼�Ⲣ����֤���������������ж�ȡ���ݣ�����ʵ�ֿ����Ƴٵ�����ʹ�õ�����ʱ��������ȡ��
//��׼���ʵ������֤���ǣ������ǵ�һ�ν����õ�����֮ǰ�������ж�ȡ���ݵĲ����Ѿ�����ˡ�


//ostream_iterator�Ĳ���
//���ǿ��Զ��κξ����������������Ͷ���ostream_iterator�������������ʱ������ṩ��ѡ�ĵڶ�����������һ���������������һ���ַ����������ÿ��Ԫ��֮�󶼻��ӡ����ַ���
//����ַ���������һ��C����ַ����������������ַ������ָ�룩
//���뽫ostream_iterator�󶨵�һ����������������
//*it = val;д�뵽����
//����������������ͬ��*it,++it,it++ ��Щ���㶼û��Ч��������it
//д�뵽�����û�б�Ҫ����
void test42(){
	ostream_iterator<int> osIter(cout,"  ");
	vector<int> iVec = {2,3,4,5,6,7};
	//��һ������������д������
	for(auto i:iVec){
		*osIter++ = i;//�����û�б�Ҫ������Ϊ�˱���һ���ԣ�Ҳ���Լ���
	}
	cout<<endl;
	//����ͨ������copy����ӡ������Ԫ��
	copy(iVec.cbegin(),iVec.cend(),osIter);
	cout<<endl;
}
//*iter = val; ����д�뵽����
//val = *iter; ���Ǵ����ж�����

class SalesItem;
void test43(){
	istream_iterator<SalesItem> isIter(cin),eof;
	ostream_iterator<SalesItem> osIter(cout,"\t");
	SalesItem sum = *isIter++//*��ʾ����һ����¼�����뵽sum��Ȼ���ƶ�����һ����¼
	while(isIter != eof){
		if(isIter->isbn() == sum.isbn()){
			sum += *isIter++;
		}else{
			//�����Ҳ����д�뵽�����
			*osIter++ = sum;
			sum = *isIter++;
		}
	}
	*osIter = sum;
}



