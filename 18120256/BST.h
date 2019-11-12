#ifndef __BST_H__
#define __BST_H__

#include"Node.h"

class BST
{
	bool isRunning = true;
public:

	BST();
	~BST();

	Node* createNode(int);
	void insert(Node*& root, int key);
	void duyetCay(Node*& root);
	Node* findMin(Node* root);
	Node* lienSau(Node* root, Node* p);
	Node* search(Node* root, int key);
	void searchAll(Node* root, int key);
	Node* xoaNode(Node* root, int key);

	void menu();
	void run(Node* &root);
};




#endif // !



