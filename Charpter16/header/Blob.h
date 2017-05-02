/*
 * Blob.h
 *
 *  Created on: 2016年9月27日
 *      Author: songx
 */

#ifndef BLOB_H_
#define BLOB_H_

#include <initializer_list>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;
template<typename>class BlobPtr;
template<typename>class Blob;
template<typename T>
bool operator==(const Blob<T>&,const Blob<T>&);



template<typename T> class Blob {
	friend class BlobPtr<T>;
	friend bool operator==<T>(const Blob<T> &,const Blob<T>&);
public:
	using sizeType = typename vector<T>::size_type;
	//加一个typename表示这是一个类型而非一个变量
	Blob();
	template<typename It>
	Blob(It begin,It end):data(make_shared<vector<T>>(begin,end)){}
	Blob(initializer_list<T> il);
	sizeType size() const {
		return data->size();
	}
	bool empty() const {
		return data->empty();
	}
	void push_back(const T & t) {
		data->push_back(t);
	}
	void push_back(T && t) {
		data->push_back(move(t));
	}
	void pop_back();
	T & back();
	T & operator[](sizeType i);
	BlobPtr<T> begin(){
		return BlobPtr<T>(*this,0);
	}
	BlobPtr<T> end(){
		return BlobPtr<T>(*this,data->size());
	}
private:
	shared_ptr<vector<T>> data;
	void check(sizeType i, const string &msg) const;
};

template<typename T>
void Blob<T>::check(sizeType i, const string &msg) const {
	if (i >= data->size()) {
		throw out_of_range(msg);
	}
}
template<typename T>
T & Blob<T>::back() {
	check(0, "back on empty Blob");
	return data->back();
}
template<typename T>
T & Blob<T>::operator [](sizeType i) {
	check(i, "subscript out pf range");
	return (*data)[i];
}
template<typename T>
void Blob<T>::pop_back() {
	check(0, "pop_back on empty Blob");
	data->pop_back();
}
template<typename T>
Blob<T>::Blob() :
		data(make_shared<vector<T>>()) {
}

template<typename T>
Blob<T>::Blob(initializer_list<T> il) :
		data(make_shared<vector<T>>(il)) {
}

#endif /* BLOB_H_ */
