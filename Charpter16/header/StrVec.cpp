/*
 * StrVec.cpp
 *
 *  Created on: 2016��9��14��
 *      Author: songx
 */

#include "StrVec.h"

void StrVec::push_back(const string & e) {
	check_n_copy();
	alloc.construct(firstFree++, e);
	//��һ��������ָ�룬ָ��΢������ڴ�ռ䣬ʣ�����ȷ�����ĸ����캯�����������(������õ���string�Ŀ�������)
}
//���صĽ���һ����ֵ���õĺ���
void StrVec::push_back(string &&e) {
	check_n_copy();
	alloc.construct(firstFree++, move(e));
}

//���ڷ���ԭʼ�ڴ棬�������ݣ�����һ��ָ�룬�ֱ�ָ�������ڴ�Ŀ�ʼ�ͽ���
pair<string*, string*> StrVec::alloc_n_copy(const string *begin,
		const string *end) {
	auto start = alloc.allocate(end - begin);
	return {start,uninitialized_copy(begin,end,start)}; //������������β��ָ��
}

//free����������destroyԪ�أ�Ȼ���ͷ��ڴ�
void StrVec::free() {
	//�����Ҫ�������еķǾ�̬�����Ի򷽷�����Ҫ�ڲ����б���дthis
	//for_each�Ƕ�ÿ��Ԫ�ص���ָ������������ÿ��Ԫ�ص�ָ�����ָ�����������Բ��������ã����ܿ�����������ָ��
	if (elements) {
		for_each(elements, firstFree,
				[this]( string & ptr) {alloc.destroy(&ptr);});
		/*for (auto ptr = firstFree; ptr != elements;) {
		 alloc.destroy(--ptr);
		 }*/
		alloc.deallocate(elements, cap - elements); //��һ�������ǵ�ʱ�������ص�ָ�룬�ڶ��������Ƿ����Ԫ�ظ���
	}
}

//�����ڴ沢������Ȼ�����ָ��
StrVec::StrVec(const StrVec & vec) {
	auto newData = alloc_n_copy(vec.begin(), vec.end());
	elements = newData.first;
	firstFree = cap = newData.second;
}

StrVec::~StrVec() {
	free();
}

//ֻҪ�����ȿ������޸ģ��Ϳ��Ա����Ը�ֵ������
StrVec & StrVec::operator =(const StrVec & vec) {
	auto newData = alloc_n_copy(vec.begin(), vec.end());
	free();
	elements = newData.first;
	firstFree = cap = newData.second;
	return *this;
}

//���·����ڴ�ʱӦ�ÿ����ƶ������ǿ���Ԫ��
//Ϊ��һ���µġ��������������ڴ�
//���ڴ��ǰһ���ֹ�����󣬱�������Ԫ��
//����ԭ�ڴ�ռ��Ԫ�ز��ͷ��ڴ�

//һЩ��׼�⣬����string���������ƶ����캯��
//�ƶ����캯��ͨ���ǽ���Դ�Ӹ��������ƶ������ǿ��������ڴ����Ķ���
//����string������һ��ָ��char�����ָ�룬�ƶ�ʱֻ���ƶ�ָ������ؿ����ַ�
//ʹ�õ���move��׼�⺯����������ϣ�����ƶ���Ԫ�أ����ص��Ǹ�Ԫ�ص���ֵ���ã�������ͣ�
//���õ�ʱ��Ӧ�õ���std::move()������move()��Ŀ���Ǳ������ֳ�ͻ

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
//�ϲ��ĸ�ֵ�����
/*
 StrVec & StrVec::operator=(StrVec vec){
 swap(*this,vec);
 return *this;
 }
 */

//�ƶ�����������������һ����ͨ������תΪ�ƶ����������ı��˸����������Ľ��������������Ϊ���ӵõ�һ����ֵ�޸�Ϊ�õ�һ����ֵ���ã��൱��*-->move(*)��
//��׼�⺯��make_move_iterator
//����reallocate�ϣ�����forѭ�����е�construct������Ϊʹ��uninitialized_copy,����������������е�ÿ��Ԫ�ص���construct����Ԫ�ء���������Ŀ��λ��
//���㷨ʹ�õ������Ľ������������������������ȡԪ�أ���Ϊ���ص�����ֵ���ã����construct��ʹ���ƶ����캯��������Ԫ��
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






