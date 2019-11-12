#include "BST.h"



BST::BST()
{
}


BST::~BST()
{
}

Node* BST::createNode(int key)
{
	Node* p = new Node;
	p->key = key;
	p->left = NULL;
	p->right = NULL;
	return p;
}

void BST::insert(Node*&root, int key)
{
	if (root == NULL)
	{
		root = createNode(key);
		return;
	}
	if (key < root->key)
		insert(root->left, key);
	else
		insert(root->right, key);
}

void BST::duyetCay(Node*& root)
{
	if (root != NULL)
	{
		duyetCay(root->left);
		cout << root->key << " ";
		duyetCay(root->right);
	}
}

Node* BST::findMin(Node* root)
{
	if (root == NULL) return NULL;
	if (root->left == NULL)
		return root;
	findMin(root->left);
}

Node* BST::lienSau(Node* root, Node* p)
{
	if (p->right != NULL)
		return findMin(p->right);
	Node * succ = NULL;
	while (root != NULL)
	{
		if (p->key < root->key)
		{
			succ = root;
			root = root->left;
		}
		else if (p->key > root->key)
		{
			root = root->right;
		}
		else
		{
			break;
		}
	}
	return succ;
}

Node* BST::search(Node* root, int key)
{
	if (root == NULL) return NULL;
	if (root->key == key) return root;
	if (key < root->key)
		search(root->left, key);
	else
		search(root->right, key);
}

void BST::searchAll(Node* root, int key)
{
	if (root == NULL) return;
	if (root->key == key)
	{
		cout << root->key << ", " << root << endl;
	}
	if (key < root->key)
		searchAll(root->left, key);
	else
		searchAll(root->right, key);
}

Node* BST::xoaNode(Node* root, int key)
{
	if (root == NULL) return root;
	if (key < root->key)
		root->left = xoaNode(root->left, key);
	else if (key > root->key)
		root->right = xoaNode(root->right, key);
	else
	{
		if (root->left == NULL)
		{
			Node* tmp = root->right;
			delete root;
			return tmp;
		}
		else if (root->right == NULL)
		{
			Node* tmp = root->left;
			delete root;
			return tmp;
		}
		else
		{
			Node* tmp = findMin(root->right);
			root->key = tmp->key;
			root->right = xoaNode(root->right, tmp->key);
		}
	}
	return root;
}

void BST::menu()
{
	cout << endl;
	cout << "1. In cay" << endl;
	cout << "2. Xoa node" << endl;
	cout << "3. Tim vi tri node" << endl;
	cout << "4. Tim tat ca node x" << endl;
	cout << "0. Thoat" << endl;
}

void BST::run(Node* &root)
{
	int cmd;
	int tmp;
	while (isRunning)
	{
		menu();
		cin >> cmd;
		switch (cmd)
		{
		case 1:
			duyetCay(root);
			break;
		case 2:
			cout << "Nhap gia tri can xoa: ";
			cin >> tmp;
			xoaNode(root, tmp);
			break;
		case 3:
			cout << "Nhap gia tri can tim: ";
			cin >> tmp;
			cout << search(root, tmp);
			break;
		case 4:
			cout << "Nhap gia tri can tim: ";
			cin >> tmp;
			searchAll(root, tmp);
			break;
		default:
			isRunning = false;
			break;
		}
	}
}
