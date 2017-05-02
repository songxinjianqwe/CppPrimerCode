/*
 * 457prac.cpp
 *
 *  Created on: 2016年9月13日
 *      Author: songx
 */

#include <string>

using namespace std;
//类似指针的类
class TreeNode{
public:
	TreeNode():value(string()),count(new int(1)),left(nullptr),right(nullptr){}
	TreeNode(const TreeNode & node):value(node.value),count(node.count),left(node.left),right(node.right){
		++*count;
	}
	TreeNode & operator=(const TreeNode & node){
		++*node.count;
		--*count;
		if(*count == 0){
			//删除前先判断是否非空，删除后赋为nullptr
			if(left){
				delete left;
				left = nullptr;
			}
			if(right){
				delete right;
				right = nullptr;
			}
			delete count;
			count = nullptr;
		}
		value = node.value;
		left = node.left;
		right = node.right;
		count = node.count;
		return *this;
	}
	~TreeNode(){
		--*count;
		if(*count == 0){
			if(left){
				delete left;
				left = nullptr;
			}
			if(right){
				delete right;
				right = nullptr;
			}
			delete count;
			count = nullptr;
		}
	}
private:
	string value;
	int *count;
	TreeNode *left;
	TreeNode *right;
};
//类似值的类
class BinStrTree{
public:
	BinStrTree():root(new TreeNode()){}
	BinStrTree(const BinStrTree & tree):root(new TreeNode(*tree.root)){}
	BinStrTree & operator=(const BinStrTree & tree){
		TreeNode * newNode = new TreeNode(*tree.root);
		delete root;
		root = newNode;
		return *this;
	}
	~BinStrTree(){
		delete root;
	}
private:
	TreeNode *root;
};



