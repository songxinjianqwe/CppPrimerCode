/*
 * 457prac.cpp
 *
 *  Created on: 2016��9��13��
 *      Author: songx
 */

#include <string>

using namespace std;
//����ָ�����
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
			//ɾ��ǰ���ж��Ƿ�ǿգ�ɾ����Ϊnullptr
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
//����ֵ����
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



