#ifndef __NODE_H__
#define __NODE_H__

#include <iostream>
using namespace std;

class Node
{
public:
	int key;
	Node* left = NULL;
	Node* right = NULL;

	Node();
	virtual ~Node();


};


#endif // !__NODE_H__