#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *link;
};

struct node* reverse(struct node *head) {
	struct node *prev = NULL;
	struct node *next = NULL;
	while(head != NULL) {
		next = head -> link;
		head -> link = prev;
		prev = head;
		head = next;
	}
	head = prev;
	return head;
}

struct node* del_list(struct node *head) {
	struct node *temp = head;
	
	while(temp != NULL) {
		temp = temp -> link;
		free(head);
		head = temp;
	}
	return head;
}

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
	
	current = malloc(sizeof(struct node));
	
	current -> data = 2;
	current -> link = NULL;
	
//	current -> link = current2;
//	by head link link this will connect the 2nd node to the 3rd node 
	head->link->link->link = current;
	
	current = head;
	
	while(current != NULL) {
		printf("%d ", current->data);
		current = current->link;
	}
	
	printf("\n");
	
	head = reverse(head);
	current = head;
	
	while(current != NULL) {
		printf("%d ", current->data);
		current = current->link;
	}
//	head = del_list(head);
//	if(head == NULL) {
//		printf("Linked List Deleted Successfully");
//	}
	return 0;
}
