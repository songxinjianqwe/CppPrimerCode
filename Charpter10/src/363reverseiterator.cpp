#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;
//���������
//�������д�βԪ�ص���Ԫ�ط����ƶ��ĵ�������++��--�ĺ����ߵ���++���ƶ���ǰһ��Ԫ�أ�--���ƶ�����һ��Ԫ��
//rbegin��rend�����᷵��everse_iterator
//crbegin��crend�᷵��const�汾
//�����������Ҫ--�����������forward_list������������֧�ַ��������
//end��rbegin��ָ��ͬһ��Ԫ�أ�rbeginָ�����һ��Ԫ�أ�endָ��β��Ԫ��
//begin��rend��ָ���һ��Ԫ��
void test48(){
	vector<int> iVec = {2,3,4,5,6};
	//�����ӡ
	for(auto it = iVec.crbegin();it != iVec.crend();it++){
		cout<<*it<<"\t";
	}
	cout<<endl;
	//sortĬ�������򣬰��շ������������ʵ�ֽ�������
	sort(iVec.rbegin(),iVec.rend());
	//�����ӡ
	ostream_iterator<int> osIt(cout,"\t");
	copy(iVec.cbegin(),iVec.cend(),osIt);
	cout<<endl;
}

//������������������������ڲ�ͬ
//���������תΪ���������������base���Է������Ӧ�������������λ��λ�ڷ���������ĺ�һ��
void test49(){
	string line = "happy,newbee,alphabet";
	//��ӡ��һ������
	auto comma = find(line.cbegin(),line.cend(),',');
	cout<<string(line.cbegin(),comma)<<endl;
	//��ӡ���һ������
	auto rcomma = find(line.crbegin(),line.crend(),',');
	cout<<string(line.crbegin(),rcomma)<<endl;
	//tebahpla
	//���������Ҫ����ĵ��ʣ���Ҫ�����������תΪ���������
	cout<<string(rcomma.base(),line.cend())<<endl;
	//alphabet
}
//�����Ǵ�һ����ͨ�ĵ�������ʼ��һ����������������Ǹ�һ�������������ֵʱ�������������ԭ������ָ��Ĳ�����ͬ����Ԫ��





