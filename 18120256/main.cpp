#include<iostream>
#include"Node.h"
#include"BST.h"

int main()
{
	int a[] = { 10, 6, 15, 13, 14, 9, 7, 3, 17, 10, 9, 3, 1, 10, 7, 8 };
	int n = sizeof(a) / sizeof(a[0]);
	BST tree;
	Node* root = NULL;
	for (int i = 0; i < n; i++)
	{
		tree.insert(root, a[i]);
	}
	tree.duyetCay(root);
	root = tree.xoaNode(root, 10);
	cout << endl;
	tree.duyetCay(root);
	return 0;
}