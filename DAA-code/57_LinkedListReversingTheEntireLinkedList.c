#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *link;
};

struct node *reverseLL(struct node *head)
{
	if (head == NULL)
	{
		return head;
	}

	struct node *current = NULL;
	struct node *next = head->link;
	head->link = NULL;

	while (next != NULL)
	{
		current = next;
		next = next->link;
		current->link = head;
		head = current;
	}
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

struct node *add_beg(struct node *head, int d)
{
	struct node *ptr = malloc(sizeof(struct node));
	ptr->data = d;
	ptr->link = NULL;

	ptr->link = head;
	head = ptr;
	return head;
}

void print(struct node *head)
{
	if (head == NULL)
	{
		printf("No number");
	}
	struct node *temp = head;
	while (temp->link != NULL)
	{
		printf("%d -> ", temp->data);
		temp = temp->link;
	}
	printf("%d ", temp->data);
}

struct node *add_node(struct node *head, int val)
{
	struct node *newNode = malloc(sizeof(struct node));
	newNode->data = val;
	newNode->link = NULL;

	newNode->link = head;
	head = newNode;
	return head;
}

struct node *createLL(struct node *head, int n)
{
	while (n != 0)
	{
		head = add_node(head, n % 10);
		n = n / 10;
	}
	return head;
}

struct node *push(struct node *head, int val)
{
	struct node *newP = malloc(sizeof(struct node));
	newP->data = val;
	newP->link = head;
	head = newP;
	return head;
}

struct node *add(struct node *head1, struct node *head2)
{
	if (head1->data == 0)
		return head2;
	if (head2->data == 0)
		return head1;

	struct node *ptr1 = head1;
	struct node *ptr2 = head2;
	struct node *head3 = NULL;
	int carry = 0, sum;

	while (ptr1 || ptr2)
	{
		sum = 0;
		if (ptr1)
			sum += ptr1->data;

		if (ptr2)
			sum += ptr2->data;

		sum += carry;

		carry = sum / 10;
		sum = sum % 10;

		head3 = push(head3, sum);

		if (ptr1)
			ptr1 = ptr1->link;
		if (ptr2)
			ptr2 = ptr2->link;
	}
	if (carry)
		head3 = push(head3, carry);
	return head3;
}

void back2num(struct node *head)
{
	struct node *temp = head;
	printf("\nResult = ");
	while (temp)
	{
		printf("%d", temp->data);
		temp = temp->link;
	}
	return; 
}

int main()
{
	int a, b;

	// printf("Enter the 2 numbers :");
	// scanf("%d %d",&a,&b);

	a = 1231;
	b = 45875;

	printf("Linked list representation of first number: \n");
	struct node *head1 = NULL;
	head1 = createLL(head1, a);
	print(head1);
	printf("\n");

	printf("Linked list representation of second number: \n");
	struct node *head2 = NULL;
	head2 = createLL(head2, b);
	print(head2);
	printf("\n");

	head1 = reverseLL(head1);
	head2 = reverseLL(head2);

	printf("\nReversed Linked List : \n");
	print(head1);
	printf("\n");
	print(head2);

	struct node *head3 = NULL;
	head3 = add(head1, head2);
	printf("\n");
	printf("Resultant linked list after addition : \n");
	print(head3);

	back2num(head3);
	return 0;
}
