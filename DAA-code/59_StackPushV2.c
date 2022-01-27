#include <stdio.h>
#include <stdlib.h>

#define MAX 4

int stack_Arr[MAX];
int first = -1;

void print();
int isFull()
{
	if (first == MAX - 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int isEmpty()
{
	if (first == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void push(int data)
{
	int i;
	first += 1;
	for (i = first; i > 0; i--)
	{
		stack_Arr[i] = stack_Arr[i - 1];
	}
	stack_Arr[0] = data;
}

int pop()
{
	int i, value;
	value = stack_Arr[0];
	for (i = 0; i < first; i++)
	{
		stack_Arr[i] = stack_Arr[i + 1];
	}
	first = first - 1;
	return value;
}

int peek()
{
	if (isEmpty)
	{
		printf("Stack underflow\n");
		exit(1);
	}
	return stack_Arr[first];
}

void print()
{
	int i;
	if (first == -1)
	{
		printf("Stack underflow\n");
		return;
	}

	for (i = 0; i <= first; i++)
	{
		printf("%d ", stack_Arr[i]);
	}
	printf("\n");
}

int main()
{
	int choice, data;
	while (1)
	{
		printf("\n");
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("3. Print the top elements\n");
		printf("4. Print all the elements of the stack\n");
		printf("5. Quit\n");
		printf("PLease enter your choice\n");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("Enter the element to the pushed: ");
			scanf("%d", &data);
			push(data);
			break;

		case 2:
			data = pop();
			printf("Deleted element is %d\n ", data);
			break;
		case 3:
			printf("the topmost element of the stack is %d\n", peek());
			break;
		case 4:
			print();
			break;
		case 5:
			exit(1);
		}
	}

	return 0;
}