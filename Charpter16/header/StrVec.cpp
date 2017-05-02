/*
 * StrVec.cpp
 *
 *  Created on: 2016年9月14日
 *      Author: songx
 */

#include "StrVec.h"

void StrVec::push_back(const string & e) {
	check_n_copy();
	alloc.construct(firstFree++, e);
	//第一个参数是指针，指向微构造的内存空间，剩余参数确定用哪个构造函数来构造对象(这里调用的是string的拷贝构造)
}
//重载的接受一个右值引用的函数
void StrVec::push_back(string &&e) {
	check_n_copy();
	alloc.construct(firstFree++, move(e));
}

//用于分配原始内存，拷贝数据，返回一对指针，分别指向分配的内存的开始和结束
pair<string*, string*> StrVec::alloc_n_copy(const string *begin,
		const string *end) {
	auto start = alloc.allocate(end - begin);
	return {start,uninitialized_copy(begin,end,start)}; //拷贝函数返回尾后指针
}

//free函数首先是destroy元素，然后释放内存
void StrVec::free() {
	//如果需要调用类中的非静态的属性或方法，需要在捕获列表上写this
	//for_each是对每个元素调用指定方法，而非每个元素的指针调用指定方法，所以参数是引用（不能拷贝），不是指针
	if (elements) {
		for_each(elements, firstFree,
				[this]( string & ptr) {alloc.destroy(&ptr);});
		/*for (auto ptr = firstFree; ptr != elements;) {
		 alloc.destroy(--ptr);
		 }*/
		alloc.deallocate(elements, cap - elements); //第一个参数是当时创建返回的指针，第二个参数是分配的元素个数
	}
}

//分配内存并拷贝，然后更新指针
StrVec::StrVec(const StrVec & vec) {
	auto newData = alloc_n_copy(vec.begin(), vec.end());
	elements = newData.first;
	firstFree = cap = newData.second;
}

StrVec::~StrVec() {
	free();
}

//只要可以先拷贝再修改，就可以避免自赋值的问题
StrVec & StrVec::operator =(const StrVec & vec) {
	auto newData = alloc_n_copy(vec.begin(), vec.end());
	free();
	elements = newData.first;
	firstFree = cap = newData.second;
	return *this;
}

//重新分配内存时应该考虑移动而不是拷贝元素
//为了一个新的、更大的数组分配内存
//在内存的前一部分构造对象，保存现有元素
//销毁原内存空间的元素并释放内存

//一些标准库，包括string，定义了移动构造函数
//移动构造函数通常是将资源从给定对象移动而不是拷贝到正在创建的对象
//比如string，持有一个指向char数组的指针，移动时只需移动指针而不必拷贝字符
//使用的是move标准库函数，参数是希望被移动的元素，返回的是该元素的右值引用（后面解释）
//调用的时候应该调用std::move()而不是move()，目的是避免名字冲突

void StrVec::resize(size_t newSize, const string & s = "") {
	reallocate(newSize);
	if (newSize > size()) {
		auto addedSize = newSize - size();
		for (size_t i = 0; i != addedSize; i++) {
			alloc.construct(firstFree++, s);
		}
	} else if (newSize < size()) {
		while (firstFree != elements + newSize) {
			alloc.destroy(--firstFree);
		}
	}
}
void StrVec::reserve(size_t newSize) {
	if (newSize > capacity()) {
		reallocate(newSize);
	}
}

StrVec::StrVec(StrVec && vec) noexcept :elements(vec.elements),firstFree(vec.firstFree),cap(vec.cap) {
	vec.elements = vec.cap = vec.firstFree = nullptr;
	cout<<"call StrVec(StrVec && vec)"<<endl;
}
StrVec&StrVec::operator=(StrVec && vec) noexcept {
	if (&vec != this) {
		free();
		elements = vec.elements;
		firstFree = vec.firstFree;
		cap = vec.cap;
		vec.elements = vec.firstFree = vec.cap = nullptr;
	}
	return *this;
}
//合并的赋值运算符
/*
 StrVec & StrVec::operator=(StrVec vec){
 swap(*this,vec);
 return *this;
 }
 */

//移动迭代器适配器：将一个普通迭代器转为移动迭代器，改变了给定迭代器的解引用运算符的行为，从得到一个左值修改为得到一个右值引用（相当于*-->move(*)）
//标准库函数make_move_iterator
//用在reallocate上，将用for循环进行的construct操作改为使用uninitialized_copy,这个函数对输入序列的每个元素调用construct来将元素“拷贝“到目的位置
//此算法使用迭代器的解引用运算符从输入序列中提取元素，因为返回的是右值引用，因此construct将使用移动构造函数来构造元素
void StrVec::reallocate(size_t newCapacity) {
	auto newData = alloc.allocate(newCapacity);
	/*for (size_t i = 0; i != size() && i != newCapacity; i++) {
	 alloc.construct(newStart++, std::move(*oldStart++));
	 }*/
	auto newEnd = uninitialized_copy(make_move_iterator(begin()),
			make_move_iterator(end()), newData);
	free();
	elements = newData;
	firstFree = newEnd;
	cap = elements + newCapacity;
}

bool operator==(const StrVec & lhs, const StrVec & rhs) {
	if (lhs.size() == rhs.size()) {
		for (auto beginL = lhs.begin(), beginR = rhs.begin();
				beginL != lhs.end(); beginL++, beginR++) {
			if (*beginL != *beginR) {
				return false;
			}
		}
		return true;
	} else {
		return false;
	}
}
bool operator!=(const StrVec & lhs, const StrVec & rhs) {
	return !(lhs == rhs);
}

bool operator<(const StrVec & lhs, const StrVec & rhs) {
	size_t i = 0;
	for (auto beginL = lhs.begin(), beginR = rhs.begin();
			i != lhs.size() && i != rhs.size(); beginL++, beginR++, i++) {
		if (*beginL < *beginR) {
			return true;
		}
	}
	if (i == lhs.size()) {
		return true;
	} else {
		return false;
	}
}

StrVec & StrVec::operator=(initializer_list<string> list){
	auto pair = alloc_n_copy(list.begin(),list.end());
	free();
	elements = pair.first;
	cap = firstFree = pair.second;
	return *this;
}

string & StrVec::operator[](size_t n){
	return elements[n];
}

const string & StrVec::operator[](size_t n)const{
	return elements[n];
}






