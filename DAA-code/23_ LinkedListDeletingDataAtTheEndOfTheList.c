#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *link;
};

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
		struct node *temp2 = head;
		
		while(temp -> link != NULL) {
			temp2 = temp;
			temp = temp->link;
		}
		
		temp2->link = NULL;
		free(temp);
		temp = NULL;
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
	
//	print_data(head);
//	head -> link = ptr;
//	ptr = head->link->link;
	head->link->link = ptr;
	print_data(head);

	del_last(head);
	ptr = head;
	
	printf("\n");
	
	while(ptr != NULL) {
		printf("%d ", ptr->data);
		ptr = ptr->link;
	}
	return 0;
}
