// Diameter of a binary tree
#include<iostream>
using namespace std;

struct node
{
	struct node *l;
	int data;
	struct node *r;
};

struct node *newNode(int k)
{
	struct node *t = new node();
	t->data = k;
	t->l = t->r = NULL;
	return t;
}

int height(struct node *root)
{
	if (root == NULL)
		return 0;

	return 1 + max(height(root->l), height(root->r));
}

int diameter(struct node *root)
{
	if (root == NULL)
		return 0;

	int lh = height(root->l);
	int rh = height(root->r);

	int ld = diameter(root->l);
	int rd = diameter(root->r);

	return max(lh + rh + 1, max(ld, rd));
}

int main()
{
	struct node *root = newNode(1);
	root->l = newNode(2);
	root->r = newNode(3);
	root->l->l = newNode(4);
	root->l->r = newNode(5);
	root->l->r->r = newNode(6);
	root->l->r->l = newNode(7);
	root->l->r->r->r = newNode(8);
	root->l->r->r->r->r = newNode(9);
	cout << diameter(root) << endl;
	return 0;
}