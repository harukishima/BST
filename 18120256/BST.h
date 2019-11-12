#ifndef __BST_H__
#define __BST_H__

#include"Node.h"

class BST
{
public:

	BST();
	~BST();

	Node* createNode(int);
	void insert(Node*& root, int key);
	void duyetCay(Node*& root);
	Node* findMin(Node* root);
	Node* lienSau(Node* root, Node* p);
	Node* search(Node* root, int key);
	Node* xoaNode(Node* root, int key);

};




#endif // !



