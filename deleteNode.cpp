//Delete Node in a Linked List

#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

void pushNode(struct node **head, int d)
{
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->data = d;
	newNode->next = NULL;
	if (*head == NULL)
	{
		*head = newNode;
		return;
	}
	
	struct node *curr = *head;
	while(curr->next != NULL)
		curr = curr->next;
	curr->next = newNode;
	return;
}

void del(struct node **head, int d)
{
	struct node *temp = *head, *prev;

	if (temp != NULL && temp->data == d)
	{
		*head = temp->next;
		free(temp);
		return;
	}

	while (temp != NULL && temp->data != d)
	{
		prev = temp;
		temp = temp->next;
	}

	if (temp == NULL) return;

	prev->next = temp->next;
	free(temp);
	return;
}

void pr(struct node *head)
{
	if (head == NULL)
		return;
	else
	{
		cout << head->data << endl;
		pr(head->next);
	}
}

int main()
{
	struct node *start = NULL;
	pushNode(&start, 1);
	pushNode(&start, 2);
	pushNode(&start, 3);
	pushNode(&start, 4);
	pushNode(&start, 5);
	pr(start);
	del(&start, 3);
	cout << endl;
	pr(start);
	return 0;
}