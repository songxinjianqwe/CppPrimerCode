/*
 * 420weak_ptr.cpp
 *
 *  Created on: 2016��9��10��
 *      Author: songx
 */

#include <initializer_list>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;
//weak_ptr ��������ָ�����������ڵ�����ָ��
//ָ����һ��shared_ptr����Ķ���
//��һ��weak_ptr�󶨵�һ��shared_ptr����ı�shared_ptr�����ü���
//һ�����һ��ָ������shared_ptr���ͷţ�����ͻᱻ�ͷš�
//��ʹ��weak_ptrָ����󣬶���Ҳ���ǻᱻ�ͷš����weak_ptr������ץס����������ָ�������������ص�

//weak_ptr<T> w
//weak_ptr<T> w(sp) sp��һ��shared_ptr��w��ָ����ͬ����
//w = p; p������һ��shared_ptr��weak_ptr����ֵ��w��p�������
//w.reset() ��w��Ϊ��
//w.use_count() ��w��������shared_ptr������
//w.expired() expiredʧЧ  ���w.use_count() Ϊ0������true����֮������false
//w.lock() ���expiredΪtrue������һ���յ�shared_ptr�����򷵻�һ��ָ��w�Ķ����shared_ptr
void test13() {
	auto p = make_shared<int>(42);
	weak_ptr<int> wp(p);
	if (shared_ptr<int> np = wp.lock()) { //��ֵ��ͬʱ�ж�
		cout << *np << endl;
	}
}
//���ǽ�ΪStrBlob����һ������ָ���ࣨ����������
//StrBlobPtr����һ��weak_ptr��ָ��StrBlob��data��Ա

class StrBlobPtr;
class ConstStrBlobPtr;

class StrBlob {
	friend class StrBlobPtr;
	friend class ConstStrBlobPtr;
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
	//���Ƶ�������begin��end
	StrBlobPtr begin();
	StrBlobPtr end();
	ConstStrBlobPtr cbegin() const;
	ConstStrBlobPtr cend() const;
private:
	shared_ptr<vector<string>> data;
	void check(sizeType i, const string & msg) const {
		if (data->size() <= i) {
			throw out_of_range(msg);
		}
	}
};


class StrBlobPtr {
public:
	using sizeType = vector<string>::size_type;
	StrBlobPtr() :
			currIndex(0) {
	}
	StrBlobPtr(StrBlob &sb, sizeType sz = 0) :
			wptr(sb.data), currIndex(sz) {
	}
	string & deref() const { //���������*��������
		auto sp = check(currIndex, "dereference past end");
		return (*sp)[currIndex]; //��ָ��vector��ָ������±����㣬�Ƚ����ã�����������±�
	}
	StrBlobPtr & inc() {
		check(currIndex, "increment past end of StrBlobPtr");
		currIndex++;
		return *this;
	}
	bool operator!=(const StrBlobPtr& p) {
		return p.currIndex != currIndex;
	}
private:
	weak_ptr<vector<string>> wptr;
	shared_ptr<vector<string>> check(sizeType i, const string & msg) const {
		auto ret = wptr.lock();
		if (!ret) {
			throw runtime_error("Unbound StrBlobPtr");
		}
		if (ret->size() <= i) {
			throw out_of_range(msg);
		}
		return ret;
	}
	sizeType currIndex;
};

StrBlobPtr StrBlob::begin() {
	return StrBlobPtr(*this);
}
StrBlobPtr StrBlob::end() {
	return StrBlobPtr(*this, data->size());
}

//12.20
void test22() {
	StrBlob sb( { });
	string word;
	while (cin >> word) {
		sb.push_back(word);
	}
	for (auto begin = sb.begin(); begin != sb.end(); begin.inc()) {
		cout << begin.deref() << "\t";
	}
	cout << endl;
}
class ConstStrBlobPtr {

public:
	using sizeType = vector<string>::size_type;
	ConstStrBlobPtr() :
			currIndex(0) {
	}
	ConstStrBlobPtr(const StrBlob &sb, sizeType sz = 0) ://�������const
			wptr(sb.data), currIndex(sz) {
	}
	const string & deref() const { //�������const
		auto sp = check(currIndex, "dereference past end");
		return (*sp)[currIndex]; 
	}
	ConstStrBlobPtr & inc() {
		check(currIndex, "increment past end of StrBlobPtr");
		currIndex++;
		return *this;
	}
	bool operator!=(const ConstStrBlobPtr& p) {
		return p.currIndex != currIndex;
	}
private:
	weak_ptr<vector<string>> wptr;
	shared_ptr<vector<string>> check(sizeType i, const string & msg) const {
		auto ret = wptr.lock();
		if (!ret) {
			throw runtime_error("Unbound StrBlobPtr");
		}
		if (ret->size() <= i) {
			throw out_of_range(msg);
		}
		return ret;
	}
	sizeType currIndex;
};
ConstStrBlobPtr StrBlob::cbegin() const{//�������const
	return ConstStrBlobPtr(*this);
}
ConstStrBlobPtr StrBlob::cend() const{//�������const
	return ConstStrBlobPtr(*this, data->size());
}
//12.22
void test23() {
	StrBlob sb( { });
	string word;
	while (cin >> word) {
		sb.push_back(word);
	}
	for (auto begin = sb.cbegin(); begin != sb.cend(); begin.inc()) {
		cout << begin.deref() << "\t";
	}
	cout << endl;
}


