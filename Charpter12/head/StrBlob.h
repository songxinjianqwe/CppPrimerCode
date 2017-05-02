/*
 * StrBlob.h
 *
 *  Created on: 2016��9��11��
 *      Author: songx
 */

#include <initializer_list>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;
class StrBlobPtr;
class ConstStrBlobPtr;

class StrBlob {
	friend class StrBlobPtr;
	friend class ConstStrBlobPtr;
public:
	using sizeType = vector<string>::size_type;
	StrBlob(){
		data = make_shared<vector<string>>();
	}
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


