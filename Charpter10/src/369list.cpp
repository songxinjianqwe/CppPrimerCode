/*
 * 369list.cpp
 *
 *  Created on: 2016��9��7��
 *      Author: songx
 */

#include <algorithm>
#include <iterator>
#include <list>
#include <string>
#include <vector>

using namespace std;

//list��forward_list�����˼��ϳ�Ա������ʽ���㷨
//�����˶��е�sort��merge��remove��reserve��unique
//��Щ����汾���㷨�����ܱȶ�Ӧ��ͨ�ð汾�õö�
//list1.merge(list2) ������list2��Ԫ�غϲ���list1�У�Ҫ��list1��list2��������ģ�Ԫ�ؽ���list2ɾ��
//list1.merge(list2,comp) ��һ���汾ʹ��<��������ڶ����汾ʹ��compν��
//list.remove(val) ɾ������ֵΪval��Ԫ��
//list.remove_if(pred) ɾ����������������Ԫ��
//list.reserver() ����
//list.sort();
//list.sort(comp)
//list.unique() ɾ��ͬһ��ֵ��������������һ���汾ʹ��==���ڶ����汾ʹ�ø����Ķ�Ԫ
//list.unique(pred) 

//����splice
//list1.splice(args) 
//forward_list1.splice_after(args)

//args���������°汾
//(p,list2) p��ָ��list1��Ԫ�صĵ�������������ָ��forward_list1����ǰԪ�صĵ�����
//��list2�е�����Ԫ���ƶ���list1��p֮ǰ��λ�û���forward_list1��p֮���λ�ã���Ԫ�ش�list2��ɾ����list2��������list1��ͬ���Ҳ�����ͬһ������

//(p,list2,p2) ��p2ָ���Ԫ���ƶ���list1�У����߽�p2֮���Ԫ���ƶ���forward_list1��
//(p,list2,begin,end) ��list2�е�begin~end��Ԫ���ƶ���list1

void deDuplicationForList(list<string> & sList){
	sList.sort();
	sList.unique();
}

