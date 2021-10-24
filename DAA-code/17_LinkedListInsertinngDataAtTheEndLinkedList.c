#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *link;
};

void add_at_end(struct node *head, int data){
	struct node *ptr, *temp;
	ptr = head;
	temp = (struct node*)malloc(sizeof(struct node));
	
	temp -> data = data;
	temp -> link = NULL;
	
	while(ptr -> link != NULL) {
		ptr = ptr -> link;
	}
	ptr -> link = temp;
}

void print_data(struct node *head) {
	if(head == NULL) {
		printf("Linked list is empty");
	}
	struct node *ptr = NULL;
	ptr = head;
	while(ptr != NULL) {
		printf("%d ",ptr->data);
		ptr = ptr -> link;
	}
}

int main() {
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
	current = malloc(sizeof(struct node));
	
	current -> data = 3;
	current -> link = NULL;
	
//	current -> link = current2;
//	by head link link this will connect the 2nd node to the 3rd node 
	head->link->link = current;
	
//	printf("%d", head->data);

	print_data(head);
	add_at_end(head,67);
	printf("\n");
	print_data(head);
	return 0;
}
