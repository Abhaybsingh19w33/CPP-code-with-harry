#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *link;
};

void count_of_nodes(struct node *head){
	int count = 0 ;
	if (head == NULL) {
		printf("Linked list id empty");
		printf("%d", count);
		return;
	}
	struct node *ptr = NULL;
	ptr = head;
	while(ptr != NULL) {
		count++;
		ptr = ptr -> link;
	}
	printf("%d", count);
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
	count_of_nodes(head);
	return 0;
}
