#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//������һ��lambdaʱ������������һ����lambda��Ӧ���µ�δ������������
//��һ����������һ��lambdaʱ��ͬʱ������һ�������ͺ͸����͵�һ�����󣬴��ݵĲ������Ǵ˱��������ɵ������͵�δ��������
//��ʱauto����һ����lambda��ʼ���ı���ʱ��������һ����lambda���ɵ����͵Ķ���
//��lambda���ɵ��඼����һ����Ӧ��lambda������ı����ĳ�Ա������lambda�ĳ�Ա����Ҳ��lambda���󱻴���ʱ����ʼ��

//�����ֲ���ʽ��ֵ��������ò���
//ֵ�����ǰ���Ǳ������Կ�����������ı�����ֵ����lambda����ʱ�����������ǵ���ʱ����
//������������޸Ĳ���Ӱ�쵽lambda�ڶ�Ӧ��ֵ
void test23() {
	int i = 32;
	auto lambda = [i] {return i;};
	i = 0;
	cout << lambda() << endl;
}
//���ò�����[]�ı�����֮ǰ����&
//������lambda��������ʹ�øñ���ʱ��ʵ����ʹ�õ����������󶨵Ķ���
//lambda����Ķ��Ǿֲ���������Щ�����ں���������Ͳ��ٴ����ˡ����lambda�����ں���������ִ�У����������ָ��ľֲ������Ѿ���ʧ�ˡ�
//һ�����ó����ǽ�һ����������lambda�������ɸ��ƣ�ֻ�ܴ�����
void test24(ostream & os) {
	vector<string> sVec = { "the", "quick", "red", "fox", "jumps", "over",
			"the", "slow", "red", "turtle" };
	auto lambda = [&os](const string & s) {os<<s<<"\t";};
	for_each(sVec.begin(), sVec.end(), lambda);
	cout << endl;
}
//���Դ�һ����������һ��lambda ��Ҫ�����lambda���ܰ������ò���
//����Ӧ�þ������ٲ������������������Ǳ�ڵĲ����µ����⣬����Ӧ�ñ��Ⲷ��ָ�������

//��ʽ����
//�����ñ���������lambda�������еĴ������ƶ�����Ҫʹ����Щ������Ϊ��ָʾ�������ƶϲ����б�Ӧ�ò����б���дһ��&��=
//&���߱��������ò������÷�ʽ��=���߱���������ֵ����ʽ
//��ϲ���
//�������ϣ����һ���ֱ�������ֵ���񣬶����������������ò��񣬿��Ի��ʹ����ʽ�������ʽ����
//������ʹ�û��ʹ����ʽ�������ʽ����ʱ�������б��еĵ�һ��Ԫ�ر�����һ��&��=���˷���ָ����Ĭ�ϲ���ʽΪ���û�ֵ
//��ʾ����ı�������ʹ�ú���ʽ����ͬ�ķ�ʽ
void test25(ostream & os) {
	vector<string> sVec = { "the", "quick", "red", "fox", "jumps", "over",
			"the", "slow", "red", "turtle" };
	string::size_type sz = 4;
	sort(sVec.begin(), sVec.end(),
			[](const string & s1,const string & s2) {return s1.size()<s2.size();});
	auto biggerStart = find_if(sVec.begin(), sVec.end(),
			[=](const string & s) {return s.size() > sz;});
	for_each(biggerStart, sVec.end(), [&](const string & s) {os<<s<<"\t";});
	cout << endl;
}

void test26(ostream & os) {
	vector<string> sVec = { "the", "quick", "red", "fox", "jumps", "over",
			"the", "slow", "red", "turtle" };
	string::size_type sz = 4;
	sort(sVec.begin(), sVec.end(),
			[](const string & s1,const string & s2) {return s1.size()<s2.size();});
	auto biggerStart = find_if(sVec.begin(), sVec.end(),
			[=](const string & s) {return s.size() > sz;});
	char c = ' ';
	for_each(biggerStart, sVec.end(), [&,c](const string & s) {os<<s<<c;});
	cout << endl;
	for_each(biggerStart, sVec.end(), [=,&os](const string & s) {os<<s<<c;});
	cout << endl;
}

//�ɱ�lambda
//����ֵ����ķ�ʽ��������lambda�Ĳ����б�֮�����mutable�ؼ��ֱ�ʾ�����޸�һ��������ı�����ֵ��Ĭ�ϲ����Ըı��
//��˿ɱ�lambda����ʡ�Բ����б�
//���ò����ܷ�ı�ȡ���ڴ�����ָ����Ƿ���const
void test27() {
	int i = 32;
	auto lambda = [i]()mutable {return ++i;};
	cout << lambda() << endl; //33
	int j = 12;
	auto lambda2 = [&j] {return ++j;};
	cout << lambda2() << endl; //13
}
//ָ��lambda�ķ�������
//ֻ������һreturn����lambda���ʽ����ʡ�Է�������
//�����ֻ��һ��return��䣬��ô�������ٶ���lambda����void
//transform�㷨
//����4��������ǰ�����Ƿ�Χ���������Ǳ�ʾĿ��λ�õĵ��������������һ��������ͬ�����ĸ�������һ���ɵ��ö���
//�㷨��ÿ��Ԫ�ص��ÿɵ��ö��󣬲������д��Ŀ��λ��

//��������Ԫ�ض��滻Ϊ�����ֵ
void test28() {
	vector<int> iVec = { 2, -12, 2, -99, 12, 0, -21 };
	transform(iVec.begin(), iVec.end(), iVec.begin(),
			[](int i) {return i < 0 ? -i:i;});
	for_each(iVec.begin(), iVec.end(), [](int i) {cout<<i<<"\t";});
	cout << endl;
}
//������������ʽд��if,�ƺ�Ҳ����?!
void test29() {
	vector<int> iVec = { 2, -12, 2, -99, 12, 0, -21 };
	transform(iVec.begin(), iVec.end(), iVec.begin(), [](int i) {if(i < 0) {return -i;} else {return i;}});
	for_each(iVec.begin(), iVec.end(), [](int i) {cout<<i<<"\t";});
	cout << endl;
}

//prac 10.20
//count_if�㷨����������������ǰ������ʾ��Χ��������������һ��һԪν��
//����ν��Ϊ��ĸ���
void test30(){
	vector<string> sVec = { "the", "quick", "red", "fox", "jumps", "over",
				"the", "slow", "red", "turtle" };
	auto res = count_if(sVec.cbegin(),sVec.cend(),[](const string & str){return str.size()>4;});
	cout<<res<<endl;
}
//10.21
void test31(){
	int i = 3;
	auto lambda = [i]() mutable{
		if(i == 0){
			return true;
		}else{
			i--;
			return false;
		}
	};
	while(!lambda()){
		cout<<"Not zero"<<endl;
	}
}

