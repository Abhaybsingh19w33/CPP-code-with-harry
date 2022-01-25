#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *link;
};

void del_pos(struct node **head, int position) {
	struct node *current = *head;
	struct node *previous = *head;
	
	if(*head == NULL) {
		printf("List is already empty!");
	}
	else if(position == 1) {
		*head = current -> link;
		free(current);
		current = NULL;
	}
	else {
		while(position != 1) {
			previous = current;
			current = current -> link;
			position--;
		}
		previous -> link = current -> link;
		free(current);
		current = NULL;
	}
}

struct node* del_first(struct node * head){
	if(head == NULL) {
		printf("List is already empty!");
	}
	else {
		struct node *temp = head;
		head = head->link;
		free(temp);
	}
	return head;
}

void del_last(struct node * head){
	if(head == NULL) {
		printf("List is already empty!");
	}
	else if(head->link == NULL){
		free(head);
		head = NULL;
	}
	else {
		struct node *temp = head;
		
		while(temp -> link -> link != NULL) {
			temp = temp->link;
		}
		
		free(temp -> link);
		temp->link = NULL;
	}
}

struct node* add_beg(struct node* head, int d) {
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

//	print_data(head);
	
	ptr = malloc(sizeof(struct node));
	
	ptr -> data = 3;
	ptr -> link = NULL;
	
	head->link->link = ptr;
	
	print_data(head);

	int position = 2;
	del_pos(&head,position);
	ptr = head;
	
	printf("\n");
	
	while(ptr != NULL) {
		printf("%d ", ptr->data);
		ptr = ptr->link;
	}
	return 0;
}
