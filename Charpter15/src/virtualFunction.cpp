/*
 * virtualFunction.cpp
 *
 *  Created on: 2016��9��20��
 *      Author: songx
 */


#include <iostream>
using namespace std;

//���麯���ĵ���������ʱ�ű�����
//��ĳ���麯��ͨ��ָ������õ���ʱ�������������Ĵ���ֱ������ʱ����ȷ��Ӧ�õ����ĸ��汾�ĺ����������õĺ�������󶨵�
//ָ��������ϵĶ���Ķ�̬������ƥ����Ǹ���
//��̬��ֻ�е�����ͨ��ָ������õ����麯��ʱ�Żᷢ����
//������ͨ��һ��������ͨ���ͣ���ָ�롢���ã��ı���ʽ�����麯��ʱ���ڱ���ʱ�ͻὫ���õİ汾ȷ��������

//���û�ָ��ľ�̬�����붯̬���Ͳ�ͬ��һ��ʵ����C++����֧�ֶ�̬�Եĸ������ڡ�

//�Է��麯���ĵ����ڱ���ʱ���а󶨡�ͨ��������еĺ�������Ҳ�ڱ���ʱ�󶨡�

//�������������า����ĳ���麯��ʱ��������һ��ʹ��virtual�ؼ���ָ���ú���������
//���ⲻ�Ǳ���ġ���Ϊһ��ĳ���������������麯���������������������������麯��
//һ��������ĺ������������ĳ���̳ж������麯�����������β����ͱ����뱻�����ǵĻ��ຯ����ȫһ�¡�
//ͬ�������������麯���ķ�������Ҳ��������ຯ��ƥ�䡣����������һ�����⣬���ǵ�����麯�����������Ǳ�����ָ�������ʱ
//����������Ч


//���������������һ��������������麯����������ͬ�����β��б���ͬ������Ȼ�ǺϷ��ġ�
//���Ⲣû�и��ǵ������еİ汾��
//ʹ��override�ؼ�����˵���������е��麯�����ô���ʹ�ó���Ա����ͼ����������ͬʱ�ñ���������Ϊ���Ƿ���һЩ����
//�����ڱ��ʵ�����Եø�����Ҫ��
//�������ʹ��override�����ĳ�����������ú�����û�и����Ѵ��ڵ��麯������ô��������������

//���ǿ��Ի��ܽ�ĳ������ָ��Ϊfinal����������Ѿ��Ѻ�������Ϊfinal�ˣ���֮���κγ��Ը��Ǹú����Ĳ���������������
//final��override˵�����������β��б��������κ�const���������η����Լ�β�÷�������֮��

//�麯��Ҳ����ӵ��Ĭ��ʵ�Σ����ĳ�κ�������ʹ����Ĭ��ʵ�Σ���ô��ʵ��ֵ�ɱ��ε��õľ�̬���;�����
//�������ͨ�������ָ������õ��ú�������ʹ�û����ж����Ĭ��ʵ�Σ���ʹʵ�����е����������еĺ����汾Ҳ��������

//�ر��麯������
//ĳЩ����£�����ϣ�����麯���ĵ��ò�Ҫ���ж�̬�󶨣�����ǿ����ִ���麯����ĳ�����ð汾��ʹ�����������������ʵ����һĿ�ġ�
//double d = baseP->Quote::netPrice(42);
//ǿ�Ƶ���Quote��netPrice������������basePʵ��ָ��Ķ������͵�����ʲô���õ��ý��ڱ���ʱ��ɽ�����
//ͨ������£�ֻ�г�Ա��������Ԫ�еĴ������Ҫʹ����������������ر��麯������
//ͨ���ǵ�һ����������麯�����������ǵĻ�����麯���汾ʱ

//���һ���������麯����Ҫ�������Ļ���汾������û��ʹ�����������������������ʱ�õ��ý�������Ϊ��������汾���������ã��Ӷ���������ѭ��


