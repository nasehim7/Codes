// Sum Tree
#include<iostream>
using namespace std;

struct node
{
	struct node *l;
	int data;
	struct node *r;
};

void dfs(struct node *root)
{
	if (root == NULL)
		return;
	dfs(root->l);
	cout << root->data << endl;
	dfs(root->r);
}

struct node *newNode(int k)
{
	struct node *t = new node();
	t->data = k;
	t->l = t->r = NULL;
	return t;
}

int checkLeaf(struct node *n)
{
	if (n == NULL)
		return 0;

	if (n->l == NULL && n->r == NULL)
		return 1;

	return 0;
}

int checkSumTree(struct node *root)
{
	int ls = 0;
	int rs = 0;

	if (root == NULL || checkLeaf(root))
		return 1;

	if (checkSumTree(root->l) && checkSumTree(root->r))
	{
		if (root->l == NULL)
			ls = 0;
		else if (checkLeaf(root->l))
			ls = root->l->data;
		else
			ls = 2 * (root->l->data);


		if (root->r == NULL)
			rs = 0;
		else if (checkLeaf(root->r))
			rs = root->r->data;
		else
			rs = 2 * (root->r->data);

		return (root->data == ls + rs);
	}

	cout << root->data ;
	return 0;
}

int main()
{
	struct node *root = newNode(32);
	root->l = newNode(10);
	root->r = newNode(6);
	root->l->l = newNode(6);
	root->l->r = newNode(4);
	root->r->l = newNode(3);
	root->r->r = newNode(3);
	dfs(root);

	if (checkSumTree(root))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}