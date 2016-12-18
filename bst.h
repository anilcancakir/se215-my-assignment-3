 
#include <iostream>

struct node
{
int data;
node *left;
node *right;
};

class BST
{

public:
	BST();
	void insert(int data);
	node *search(int data);
	node *min();
	node *max();
	node *getRoot();
private:
	node *createNode(int data);
	node *root;
};

BST::BST()
{
	root = NULL;
}

node *BST::createNode(int data)
{
	node *n = new node;
	n->data = data;
	n->left = NULL;
	n->right = NULL;

	return n;
}

node *BST::getRoot(){return root;}

void BST::insert(int data)
{
	if(root == NULL)
	{
		root = createNode(data);
		return;
	}
	
	node *pre = NULL;
	node *cur = root;
	while(cur != NULL)
	{
		pre = cur;
		if(data > cur->data)
			cur = cur->right;
		else
			cur = cur->left;
	}
	
	if(data > pre->data)
		pre->right = createNode(data);
	else
		pre->left = createNode(data);
}

node *BST::search(int data)
{

	node *cur = root;
	
	while(cur !=NULL && cur->data != data)
	{
		if(data > cur->data)
			cur = cur->right;
		else
			cur = cur->left;
	}

	return cur;
}

node *BST::min()
{

	node *cur = root;
	
	if (cur == NULL)
		return NULL;

	while(cur->left != NULL)
	{
			cur = cur->left;
	}

	return cur;
}

node *BST::max()
{

	node *cur = root;
	
	if (cur == NULL)
		return NULL;

	while(cur->right !=NULL)
	{
			cur = cur->right;
	}

	return cur;
}
