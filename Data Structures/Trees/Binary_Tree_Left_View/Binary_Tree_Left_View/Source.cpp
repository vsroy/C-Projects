#include<iostream>
using namespace std;

struct Node
{
	Node* left;
	Node* right;
	int value;
};

Node* CreateNode(int val)
{
	Node* newNode = new Node;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->value = val;
	return newNode;
}

Node* InsertNode(Node* root, int value)
{
	if (root == NULL)
		return CreateNode(value);
	
	if (value <= root->value)
		root->left = InsertNode(root->left, value);
	else if (value > root->value)
		root->right = InsertNode(root->right, value);
	return root;	/*We will have to return the root back again*/
}

void PrintInOrder(Node* root)
{

	if (root != NULL)
	{
		PrintInOrder(root->left);
		cout << root->value << " ";
		PrintInOrder(root->right);
	}
}

void PrintLeftViewUtil(Node* node, int* maxLevel, int level)
{
	if (node == NULL)
		return;
	if (level > *maxLevel)
	{
		cout << node->value << " ";
		*maxLevel = level;
	}
	//Recursive for left and right sub trees
	PrintLeftViewUtil(node->left, maxLevel, level + 1);
	PrintLeftViewUtil(node->right, maxLevel, level + 1);
}

void PrintLeftView(Node* node)
{
	int maxLevel = 0;
	PrintLeftViewUtil(node, &maxLevel, 1);
}

int main()
{
	Node* root = NULL;
	root = InsertNode(root, 12);
	InsertNode(root, 10);
	InsertNode(root, 30);
	InsertNode(root, 25);
	InsertNode(root, 40);

	PrintInOrder(root);
	cout << endl;
	PrintLeftView(root);
	return 0;
}