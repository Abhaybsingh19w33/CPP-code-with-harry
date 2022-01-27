#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *link;
};

struct node *addToEmpty(int data)
{
	struct node *temp = malloc(sizeof(struct node));

	temp->data = data;
	temp->link = NULL;
	return temp;
}

struct node *reverse(struct node *head)
{
	struct node *prev = NULL;
	struct node *next = NULL;
	while (head != NULL)
	{
		next = head->link;
		head->link = prev;
		prev = head;
		head = next;
	}
	head = prev;
	return head;
}

struct node *del_list(struct node *head)
{
	struct node *temp = head;

	while (temp != NULL)
	{
		temp = temp->link;
		free(head);
		head = temp;
	}
	return head;
}

void del_pos(struct node **head, int position)
{
	struct node *current = *head;
	struct node *previous = *head;

	if (*head == NULL)
	{
		printf("List is already empty!");
	}
	else if (position == 1)
	{
		*head = current->link;
		free(current);
		current = NULL;
	}
	else
	{
		while (position != 1)
		{
			previous = current;
			current = current->link;
			position--;
		}
		previous->link = current->link;
		free(current);
		current = NULL;
	}
}

struct node *del_first(struct node *head)
{
	if (head == NULL)
	{
		printf("List is already empty!");
	}
	else
	{
		struct node *temp = head;
		head = head->link;
		free(temp);
	}
	return head;
}

void del_last(struct node *head)
{
	if (head == NULL)
	{
		printf("List is already empty!");
	}
	else if (head->link == NULL)
	{
		free(head);
		head = NULL;
	}
	else
	{
		struct node *temp = head;

		while (temp->link->link != NULL)
		{
			temp = temp->link;
		}

		free(temp->link);
		temp->link = NULL;
	}
}

struct node *insert(struct node *head, int data)
{
	struct node *temp;
	struct node *newP = malloc(sizeof(struct node));
	newP->data = data;
	newP->link = NULL;

	int key = data;
	if (head == NULL || key < head->data)
	{
		newP->link = head;
		head = newP;
	}
	else
	{
		temp = head;
		while (temp->link != NULL && temp->link->data < key)
		{
			temp = temp->link;
		}
		newP->link = temp->link;
		temp->link = newP;
	}
	return head;
}

void print_data(struct node *head)
{
	if (head == NULL)
	{
		printf("Linked list is empty");
	}
	struct node *ptr = head;
	while (ptr != NULL)
	{
		printf("%d ", ptr->data);
		ptr = ptr->link;
	}
}

int main()
{
	struct node *head = addToEmpty(0);

	head = insert(head, 1);
	head = insert(head, 2);
	head = insert(head, 3);
	head = insert(head, 4);
	head = insert(head, 5);

	print_data(head);

	return 0;
}
