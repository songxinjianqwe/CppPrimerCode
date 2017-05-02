/*
 * QueryBase.h
 *
 *  Created on: 2016年9月26日
 *      Author: songx
 */

#ifndef QUERYBASE_H_
#define QUERYBASE_H_

#include "TextQuery.h"

//在原来的文本查询程序基础上进行拓展
//输入一个单词：单词查询
//输入 ~(word1) 得到所有不匹配查询条件的所有行
//输入  (word1|word2) 返回两个条件中任意一个的行
//输入  (word1&word2) 返回匹配两个全部条件的行

//混合使用 word1 & word2 | word3

//在输出内容中首先是查询语句，使用圆括号来表示查询被解释和执行的次序
//((fiery & bird)|wind)

//类结构：
//QueryBase 所有查询类的抽象基类
//WordQuery 查询某个单词
//NotQuery 非
//BinaryQuery 抽象基类，表示有两个运算对象的查询
//AndQuery 与  继承自BinaryQuery
//OrQuery 或     继承自BinaryQuery

//这些类都有两个操作：eval 接受一个TextQuery对象，返回一个QueryResult
//rep 返回基础查询的string表达式

//抽象基类QueryBase将eval和rep定义为纯虚函数
//因为AndQuery和OrQuery与其他抽象基类不同，包含两个运算对象，所以定义一个BinaryQuery座位它们的抽象基类

//将层次关系隐藏于接口中
//Query q = Query("word1") & Query("word2") | Query("word3")
//用户层代码将不会直接使用这些继承的类
//我们将定义一个Query的对外接口的类，用户只接触Query类
//由Query类负责隐藏整个继承体系
//Query类将保存一个QueryBase指针，该指针绑定到QueryBase的派生类对象中。
//Query的对外接口和QueryBase一致，eval用于求查询结果，rep用户生成查询的string表达式
//Query提供一个重载的<<运算符用于显示查询

//用户将通过Query对象的操作间接地创建并处理QueryBase对象
//定义Query对象的三个重载运算符以及一个接受string参数的Query构造函数
//这些函数动态分配一个新的QueryBase派生类对象
//& 生成一个绑定到新的AndQuery对象上的Query对象
//| 生成一个绑定到新的OrQuery对象上的Query对象
//~ 生成一个绑定到新的NotQuery对象上的Query对象

class QueryBase{
	friend class Query;
protected:
	virtual ~QueryBase() = default;
private:
	virtual QueryResult eval(TextQuery &) const = 0;
	virtual string rep() const = 0;
};

//我们不希望用户或派生类直接使用QueryBase，因此没有public成员
//所有对QueryBase的使用都需要通过Query对象
//因为Query对象调用QueryBase的私有成员，所以定义为其友元

#endif /* QUERYBASE_H_ */
