#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *link;
};

struct node* add_beg(struct node* head, int d) {
	struct node *ptr = malloc(sizeof(struct node));
	ptr->data = d;
	ptr->link = NULL;
	
	ptr->link = head;
	head = ptr;
	return head;
}

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

void add_at_pos(struct node* head, int data, int pos) {
	struct node *ptr = head;
	struct node *ptr2 = malloc(sizeof(struct node));
	ptr2->data = data;
	ptr2->link = NULL;
	
//	pos--;
	while(pos != 1) {
		ptr = ptr->link;
		pos--;
	}
	ptr2->link = ptr->link;
	ptr->link = ptr2;
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
	
	add_at_end(head, 98);
	add_at_end(head,3);
	
	int data = 67, position = 3;

	add_at_pos(head, data, position);
	struct node *ptr = head;
	
	while(ptr != NULL) {
		printf("%d ", ptr->data);
		ptr = ptr->link;
	}
	return 0;
}
