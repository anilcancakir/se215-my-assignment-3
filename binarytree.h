
#include<iostream>

struct Node
{
int data;
Node *left;
Node *right;
};


class BinaryTree
{

public: 
	BinaryTree();
	void PreorderTraversal();
	void PostorderTraversal();
	void InorderTraversal();
	void BuildTree();
private:
	Node *root;
	void PRET(Node *node);
	void POSTT(Node *node);
	void INT(Node *node);
	Node *CreateNode(int data);
};

BinaryTree::BinaryTree()
{
	root = NULL;
}

Node *BinaryTree::CreateNode(int data)
{

Node *n = new Node;
n->data=data;
n->left=NULL;
n->right=NULL;

return  n;
}

void BinaryTree::BuildTree()
{

	root = CreateNode(3);
	Node *n1 = CreateNode(8);
	Node *n2 = CreateNode(5);
	root->left = n1;
	root->right = n2;

	Node *n3 = CreateNode(4);
	Node *n4 = CreateNode(2);
	n1->left = n3;
	n1->right = n4;

	Node *n5 = CreateNode(7);
	n3->left = n5;
}

void BinaryTree::PreorderTraversal()
{
	std::cout << "...Preorder Traversal..." << std::endl;
	BinaryTree::PRET(root);
}

void BinaryTree::PostorderTraversal()
{
	std::cout << "...Postorder Traversal..." << std::endl;
	BinaryTree::POSTT(root);
}

void BinaryTree::InorderTraversal()
{
	std::cout << "...Inorder Traversal..." << std::endl;
	BinaryTree::INT(root);
}

void BinaryTree::PRET(Node *node)
{
	if (node != NULL)
	{
		std::cout << node->data << std::endl;
		BinaryTree::PRET(node->left);
		BinaryTree::PRET(node->right);
	}
}

void BinaryTree::POSTT(Node *node)
{
	if (node != NULL)
	{
		BinaryTree::POSTT(node->left);
		BinaryTree::POSTT(node->right);
		std::cout << node->data << std::endl;
	}
}

void BinaryTree::INT(Node *node)
{
	if (node != NULL)
	{
		BinaryTree::INT(node->left);
		std::cout << node->data << std::endl;
		BinaryTree::INT(node->right);
	}
}
