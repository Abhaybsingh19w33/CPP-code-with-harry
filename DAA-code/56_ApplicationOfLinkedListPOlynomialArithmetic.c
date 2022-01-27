#include <stdio.h>
#include <stdlib.h>

struct node
{
	float coefficient;
	int exponent;
	struct node *link;
};

int count(struct node *head)
{
	if (head == NULL)
	{
		return 0;
	}
	int count = 1;
	while (head->link != NULL)
	{
		count++;
		head = head->link;
	}
	return count;
}
struct node *addToEmpty(int coefficient, int exponent)
{
	struct node *temp = malloc(sizeof(struct node));

	temp->coefficient = coefficient;
	temp->exponent = exponent;
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

struct node *insert(struct node *head, int co, int ex)
{
	struct node *temp;
	struct node *newP = malloc(sizeof(struct node));
	newP->coefficient = co;
	newP->exponent = ex;
	newP->link = NULL;

	if (head == NULL || ex > head->exponent)
	{
		newP->link = head;
		head = newP;
	}
	else
	{
		temp = head;
		while (temp->link != NULL && temp->link->exponent > ex)
		{
			temp = temp->link;
		}
		newP->link = temp->link;
		temp->link = newP;
	}
	return head;
}

void print(struct node *head)
{
	if (head == NULL)
	{
		printf("No polynomial.");
	}
	else
	{
		struct node *ptr = head;
		while (ptr != NULL)
		{
			printf("%1.fx^%d ", ptr->coefficient, ptr->exponent);
			ptr = ptr->link;
			if (ptr != NULL)
			{
				printf(" + ");
			}
			else
			{
				printf("\n");
			}
		}
	}
}

struct node *create(struct node *head)
{
	int n;
	int i;
	float coeff;
	int expo;

	printf("Enter the number of terms : ");
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		printf("Enter the coefficient for term %d : ", i + 1);
		scanf("%f", &coeff);

		printf("Enter the exponent for term %d : ", i + 1);
		scanf("%d", &expo);

		head = insert(head, coeff, expo);
	}
}

void polyAdd(struct node *head1, struct node *head2)
{
	struct node *ptr1 = head1;
	struct node *ptr2 = head2;
	struct node *head3 = NULL;
	while (ptr1 != NULL && ptr2 != NULL)
	{
		if (ptr1->exponent == ptr2->exponent)
		{
			head3 = insert(head3, ptr1->coefficient + ptr2->coefficient, ptr1->exponent);
			ptr1 = ptr1->link;
			ptr2 = ptr2->link;
		}
		else if (ptr1->exponent > ptr2->exponent)
		{
			head3 = insert(head3, ptr1->coefficient, ptr1->exponent);
			ptr1 = ptr1->link;
		}
		else if (ptr1->exponent < ptr2->exponent)
		{
			head3 = insert(head3, ptr2->coefficient, ptr2->exponent);
			ptr2 = ptr2->link;
		}
	}

	while (ptr1 != NULL)
	{
		head3 = insert(head3, ptr1->coefficient, ptr1->exponent);
		ptr1 = ptr1->link;
	}

	while (ptr2 != NULL)
	{
		head3 = insert(head3, ptr2->coefficient, ptr2->exponent);
		ptr2 = ptr2->link;
	}

	printf("Added polynomial is : ");
	print(head3);
}

void polyMult(struct node *head1, struct node *head2)
{
	struct node *ptr1 = head1;
	struct node *ptr2 = head2;
	struct node *head3 = NULL;

	if (head1 == NULL || head2 == NULL)
	{
		printf("Zero polynomial\n");
		return;
	}

	while (ptr1 != NULL)
	{
		while (ptr2 != NULL)
		{
			head3 = insert(head3, ptr1->coefficient * ptr2->coefficient, ptr1->exponent * ptr2->exponent);
			ptr2 = ptr2->link;
		}
		ptr1 = ptr1->link;
		ptr2 = head2;
	}

	struct node *ptr3 = head3;
	struct node *temp = NULL;

	while (ptr3->link != NULL)
	{
		if (ptr3->exponent == ptr3->link->exponent)
		{
			ptr3->coefficient = ptr3->coefficient + ptr3->link->coefficient;
			temp = ptr3->link;
			ptr3->link = ptr3->link->link;
			free(temp);
		}
		else
		{
			ptr3 = ptr3->link;
		}
	}

	printf("Multiplication polynomial is : ");
	print(head3);
}

int main()
{
	struct node *head = NULL;

	// head = create(head);

	head = insert(head, 1, 0);
	head = insert(head, 2, 1);
	head = insert(head, 3, 2);
	head = insert(head, 4, 3);
	head = insert(head, 5, 4);

	struct node *head2 = NULL;

	// head = create(head);

	head2 = insert(head2, 1, 0);
	head2 = insert(head2, 2, 1);
	head2 = insert(head2, 3, 2);
	head2 = insert(head2, 4, 3);
	head2 = insert(head2, 5, 4);
	print(head);
	print(head2);

	// struct node *result = addition(head, head2);
	polyAdd(head, head2);
	polyMult(head, head2);

	// printf("Number of element in list is %d\n", count(head));

	// print(result);

	return 0;
}
