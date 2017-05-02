/*
 * StrBlob.h
 *
 *  Created on: 2016年9月16日
 *      Author: songx
 */

#ifndef STRBLOB_H_
#define STRBLOB_H_

#include <algorithm>
#include <initializer_list>
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
	friend bool operator==(const StrBlob & lhs,const StrBlob & rhs);
	friend bool operator!=(const StrBlob & lhs,const StrBlob & rhs);
	friend bool operator<(const StrBlob & lhs, const StrBlob & rhs);
public:
	using sizeType = vector<string>::size_type;
	StrBlob(){
		data = make_shared<vector<string>>();
	}
	StrBlob(initializer_list<string> list) :
			data(make_shared<vector<string>>(list)) {
	}
	
	StrBlob(const StrBlob & s):data(make_shared<vector<string>>(*s.data)){} 
	StrBlob & operator=(const StrBlob & s){
		data = make_shared<vector<string>>(*s.data);
		return *this;
	}
	

	string & operator[](size_t n);
	const string & operator[](size_t n) const;
	
	
	sizeType size() const {
		return data->size();
	}
	bool empty() const {
		return data->empty();
	}
	void push_back(string str) {
		data->push_back(str);
	}
	void push_back(string && str){
		data->push_back(move(str));
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





#endif /* STRBLOB_H_ */
