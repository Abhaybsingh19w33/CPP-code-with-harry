#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *link;
};

void add_beg(struct node** head, int d) {
	struct node *ptr = malloc(sizeof(struct node));
	ptr->data = d;
	ptr->link = NULL;
	
	ptr->link = head;
	head = ptr;
	return head;
}

void print_data(struct node *head) {
	if(head == NULL) {
		printf("Linked list is empty");
	}
	struct node *ptr = NULL;
	ptr = head;
	while(ptr != NULL) {
		printf("%d ",ptr->data);
		ptr = ptr->link;
	}
}

int main() {
	struct node *head = malloc(sizeof(struct node));
	
	head -> data = 45;
	head -> link = NULL;
	
	struct node *ptr = malloc(sizeof(struct node));
	
	ptr -> data = 98;
	ptr -> link = NULL;
	
	head -> link = ptr;
	
	int data = 3;
	
//	here we are passing the address of head pointer

	add_beg(&head, data);
	ptr = head;
	
	while(ptr != NULL) {
		printf("%d ", ptr->data);
		ptr = ptr->link;
	}
	return 0;
}
