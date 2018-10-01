// Level Order
#include<iostream>
using namespace std;

struct node
{
	struct node *l;
	struct node *r;
	int data;
};

struct node *newNode(int k)
{
	struct node *t = (struct node *)malloc(sizeof(struct node));
	t->d = k;
	t->l = NULL;
	r->r = NULL;
	return t;
}

void bfs(struct node *r)
{
	
}


int main()
{
	struct node *root = newNode(1);
	root->l = newNode(2);
	root->r = newNode(3);
	root->l->l = newNode(4);
	root->l->r = newNode(5);
	bfs(root);
	return 0;
}