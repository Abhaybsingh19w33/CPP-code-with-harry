#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *link;
};

int main() {
//	traditional method
//	1st node
	struct node *head = malloc(sizeof(struct node));
	
	head -> data = 45;
	head -> link = NULL;
	
//	2nd node
	struct node *current = malloc(sizeof(struct node));
	
	current -> data = 98;
	current -> link = NULL;
	
	head -> link = current;
	
//	3rd node
	struct node *current2 = malloc(sizeof(struct node));
	
	current2 -> data = 3;
	current2 -> link = NULL;
	
	current -> link = current2;
	
	printf("%d", head->data);
	return 0;
}
