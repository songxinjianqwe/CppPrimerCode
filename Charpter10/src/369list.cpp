/*
 * 369list.cpp
 *
 *  Created on: 2016年9月7日
 *      Author: songx
 */

#include <algorithm>
#include <iterator>
#include <list>
#include <string>
#include <vector>

using namespace std;

//list和forward_list定义了集合成员函数形式的算法
//定义了独有的sort、merge、remove、reserve、unique
//这些链表版本的算法的性能比对应的通用版本好得多
//list1.merge(list2) 将来自list2的元素合并到list1中，要求list1、list2都是有序的，元素将从list2删除
//list1.merge(list2,comp) 第一个版本使用<运算符，第二个版本使用comp谓词
//list.remove(val) 删除所有值为val的元素
//list.remove_if(pred) 删除所有满足条件的元素
//list.reserver() 逆序
//list.sort();
//list.sort(comp)
//list.unique() 删除同一个值得连续拷贝，第一个版本使用==，第二个版本使用给定的二元
//list.unique(pred) 

//剪接splice
//list1.splice(args) 
//forward_list1.splice_after(args)

//args可以有如下版本
//(p,list2) p是指向list1中元素的迭代器，或者是指向forward_list1的首前元素的迭代器
//将list2中的所有元素移动到list1中p之前的位置或者forward_list1中p之后的位置，将元素从list2中删除。list2的类型与list1相同，且不能是同一个链表

//(p,list2,p2) 将p2指向的元素移动到list1中，或者将p2之后的元素移动到forward_list1中
//(p,list2,begin,end) 将list2中的begin~end的元素移动到list1

void deDuplicationForList(list<string> & sList){
	sList.sort();
	sList.unique();
}

