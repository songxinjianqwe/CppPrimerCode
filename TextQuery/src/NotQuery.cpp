/*
 * NotQuery.cpp
 *
 *  Created on: 2016��9��26��
 *      Author: songx
 */

#include "../header/NotQuery.h"




QueryResult NotQuery::eval(TextQuery & tq)const{
	auto result = query.eval(tq);
	//result �ǲ�ѯ �� �Ľ��
	auto retLines = make_shared<set<int>>();
	auto begin = result.begin(),end = result.end();
	auto size = result.getFile()->size();
	//size��ԭ�ı�������
	for(size_t i = 0; i != size;i++){
		if(begin == end||*begin != i){
			//�������result�У���ô���뵽�������
			retLines->insert(i);
			
		}else if ( begin != end){
			//���i��result�У��Ҳ�ѯ�����δ��������ôbegin++
			begin++;
		}
	}
	return QueryResult(rep(),result.getFile(),retLines);
}
