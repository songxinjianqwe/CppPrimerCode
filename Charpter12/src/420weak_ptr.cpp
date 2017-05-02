/*
 * 420weak_ptr.cpp
 *
 *  Created on: 2016年9月10日
 *      Author: songx
 */

#include <initializer_list>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;
//weak_ptr 不控制所指向对象的生存期的智能指针
//指向由一个shared_ptr管理的对象
//将一个weak_ptr绑定到一个shared_ptr不会改变shared_ptr的引用计数
//一旦最后一个指向对象的shared_ptr被释放，对象就会被释放。
//即使有weak_ptr指向对象，对象也还是会被释放。因此weak_ptr的名字抓住了这种智能指针弱共享对象的特点

//weak_ptr<T> w
//weak_ptr<T> w(sp) sp是一个shared_ptr，w会指向相同对象
//w = p; p可以是一个shared_ptr或weak_ptr，赋值后w与p共享对象
//w.reset() 将w置为空
//w.use_count() 与w共享对象的shared_ptr的数量
//w.expired() expired失效  如果w.use_count() 为0，返回true；反之，返回false
//w.lock() 如果expired为true，返回一个空的shared_ptr；否则返回一个指向w的对象的shared_ptr
void test13() {
	auto p = make_shared<int>(42);
	weak_ptr<int> wp(p);
	if (shared_ptr<int> np = wp.lock()) { //赋值的同时判断
		cout << *np << endl;
	}
}
//我们将为StrBlob定义一个伴随指针类（迭代器？）
//StrBlobPtr保存一个weak_ptr，指向StrBlob的data成员

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
	//类似迭代器的begin和end
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
	string & deref() const { //代替运算符*，解引用
		auto sp = check(currIndex, "dereference past end");
		return (*sp)[currIndex]; //对指向vector的指针进行下标运算，先解引用，括号外面加下标
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
	ConstStrBlobPtr(const StrBlob &sb, sizeType sz = 0) ://这里加了const
			wptr(sb.data), currIndex(sz) {
	}
	const string & deref() const { //这里加了const
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
ConstStrBlobPtr StrBlob::cbegin() const{//这里加了const
	return ConstStrBlobPtr(*this);
}
ConstStrBlobPtr StrBlob::cend() const{//这里加了const
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


