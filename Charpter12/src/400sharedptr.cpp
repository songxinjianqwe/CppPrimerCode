/*
 * 400sharedptr.cpp
 *
 *  Created on: 2016��9��8��
 *      Author: songx
 */

#include <initializer_list>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;
//���ǵĳ���ʹ�ù���̬�ڴ棬���ڱ���ֲ���̬�������ྲ̬��Ա������ȫ�ֱ���
//ʹ�ù�ջ�ڴ棬���涨���ں����еķǾ�̬������
//�����ھ�̬�ڴ��ջ�ڴ��еĶ����ɱ������Զ������������١�ջ��������䶨��ĳ��������ʱ�Ŵ��ڣ���̬��Ա��ʹ��֮ǰ���䣬�ڳ�����������١�
//ÿ������ӵ��һ���ڴ�أ� ��Ϊ�ѣ������洢��̬����Ķ���
//c++�ж�̬�ڴ������ͨ��new��delete���������ɵġ�
//Ϊ�˸���ȫ��ʹ�ö�̬�ڴ棬��������������ָ������������̬����
//����ָ�����Ϊ�����ڳ���ָ�룬��Ҫ�������Ǹ����Զ��ͷ���ָ��Ķ���
//����������ָ����������ڹ���ײ�ָ��ķ�ʽ��shared_ptr������ָ��ָ��ͬһ������unique_ptr��ռ��ָ��Ķ���
//weak_ptr��һ�������࣬��һ�������ã�ָ��shared_ptr������Ķ������Ƕ�������memoryͷ�ļ��С�
//����ָ��Ҳ��ģ�壬��Ҫ����ָ��ָ�������
//Ĭ�ϳ�ʼ��������ָ���б�����һ����ָ��
//����ָ���ʹ�÷�ʽ����ָͨ�����ƣ�������һ������ָ�뷵����ָ��Ķ���

//shared_ptr��unique_ptr��֧�ֵĲ�����
//shared_ptr<T> sp  unique_ptr<T> up
//p *p  p->mem  
//p.get() ����p�б����ָ�룬�������ָ���ͷ�������󣬷��ص�ָ����ָ��Ķ���Ҳ����ʧ�ˡ�
//swap(p,q) p.swap(q)

//shared_ptr���еĲ�����
//make_shared(args) ����һ��shared_ptr��ָ��һ����̬���������ΪT�ĳ�Ա��ʹ��args��ʼ���˶���������new+emplace
//shared_ptr p(q) p��q�Ŀ����������q�����ü�����
//p = q pָ��qָ��Ķ���ʹ��q�����ü�����+1��p�����ü�����-1����p�����ü���Ϊ0ʱ����������ԭ�ڴ��ͷ�
//p.use_count() ������p������������ָ���������ٶȽ���
//p.unique()���p��use_count Ϊ1������true�����򷵻�false

//ÿ��shared_ptr������һ�����ü����������ۺ�ʱ���ǿ���һ��shared_ptr�����������������
//�����Ǹ�shared_ptr����һ����ֵ����shared_ptr�����٣��뿪�����򣩣�����������ݼ�
//��ָ��һ����������һ��shared_ptr������ʱ��shared_ptr���������ٴ˶���
//����ͨ����������������ٹ����ġ�ÿ���඼��һ���������������ƴ����͵Ķ�������ʱ��ʲô������
//��������һ�������ͷŶ������������Դ��
//����һ���ڴ棬shared_ptr�ౣֻ֤Ҫ���κ�shared_ptr���������������Ͳ��ᱻ�ͷŵ���
//�����shared_ptr�����һ�������У���������Ҫȫ��Ԫ�أ���ֻ��������һ���֣�Ҫ�ǵ���eraseɾ��������Ҫ����ЩԪ�ء�

//����ʹ�ö�̬�ڴ洦������ԭ��
//1.����֪���Լ���Ҫʹ�ö����ڴ�
//2.����֪���Լ���������ʵ������
//3.�����ڶ������乲������

//����һ��StBlob�࣬����һ������ָ�룬ָ��һ��string��vector

void test1() {
	shared_ptr<int> p = make_shared<int>(42);
	shared_ptr<string> q = make_shared<string>("Interesting");
	auto ptr = make_shared<double>(3.14);
	auto ptr2(ptr);
//	p = q;
}


class StrBlob {
public:
	using sizeType = vector<string>::size_type;
	StrBlob() = default;
	StrBlob(initializer_list<string> list) :
			data(make_shared<vector<string>>(list)) {
	}
	sizeType size() const {
		return data->size();
	}
	bool empty() const {
		return data->empty();
	}
	void push_back(string str) {
		data->push_back(str);
	}
	void pop_back() {
		check(0, "Pop_bakc on empty StrBlob");
		data->pop_back();
	}
	string & front() {
		check(0, "Front on empty StrBlob");
		return data->front();
	}
	string & back() {
		check(0, "Back on empty StrBlob");
		return data->back();
	}
	//const ���ذ汾
	const string & front()const {
		check(0, "Front on empty StrBlob");
		return data->front();
	}
	const string & back() const{
		check(0, "Back on empty StrBlob");
		return data->back();
	}
	//�����Ƽ���һ�����صİ汾
	//��Ϊconst�Ķ��󱾲�Ӧ���ܹ��޸���ֵ�����û�б�Ҫȥ���const�汾�ĺ���
	//���Ҽ�ʹconst��������˷�const�ĺ������������ᱨ��Ҳ�޷������޸ġ�
private:
	shared_ptr<vector<string>> data;
	void check(sizeType i, const string & msg) const {
		if (data->size() <= i) {
			throw out_of_range(msg);
		}
	}
};
//initializer_list�������һ��StrBlob�����������explicit�Ļ�


