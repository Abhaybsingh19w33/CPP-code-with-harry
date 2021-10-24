#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *prev;
	struct node *next;
};

struct node * addToEmpty(struct node* head, int data) {
	struct node* temp = malloc(sizeof(struct node));
	temp -> prev = NULL;
	temp -> data = data;
	temp -> next = NULL;
	head = temp;
	return head;
}

struct node * addAtBeg(struct node* head, int data) {
	struct node* temp = malloc(sizeof(struct node));
	temp -> prev = NULL;
	temp -> data = data;
	temp -> next = NULL;
	temp -> next = head;
	head -> prev = temp;
	head = temp;
	return head;
}

struct node* addAfterPos(struct node* head, int data, int position) {
	struct node* newP = NULL;
	struct node* temp = head;
	struct node* temp2 = NULL;
	newP = addToEmpty(newP, data);
	
	while(position != 1) {
		temp = temp -> next;
		position--;
	}
	
//	if block is specially to add the last node
	if(temp -> next == NULL){
		temp -> next = newP;
		newP -> prev = temp;
	}
	else {
		temp2 = temp -> next;
		temp -> next = newP;
		temp2 -> prev = newP;
		newP -> next = temp2;
		newP -> prev = temp;
	}
	return head;
}

struct node* addBeforePos(struct node* head, int data, int position) {
	struct node* newP = NULL;
	struct node* temp = head;
	struct node* temp2 = NULL;
	newP = addToEmpty(newP, data);
	
	while(position > 2) {
		temp = temp -> next;
		position--;
	}
	
//	if block is specially to add node at the beginning
	if(position == 1){
		head = addAtBeg(head, data);
	}
	else {
		temp2 = temp -> next;
		temp -> next = newP;
		temp2 -> prev = newP;
		newP -> next = temp2;
		newP -> prev = temp;
	}
	return head;
}


struct node * addAtEnd(struct node* head, int data) {
	struct node* temp, *tp;
	temp = malloc(sizeof(struct node));
	temp -> prev = NULL;
	temp -> data = data;
	temp -> next = NULL;
	
	tp = head;
	while(tp -> next != NULL) {
		tp = tp -> next;
	}
	tp -> next  = temp;
	temp -> prev = tp;
	return head;
}

struct node* createList(struct node* head){
	int n,data, i;
	printf("Enter the number of nodes: ");
	scanf("%d",&n);
	
	if(n == 0)
		return head;
		
	printf("Enter the element for the node 1: ");
	scanf("%d", &data);
	head = addToEmpty(head, data);
	
	for(i = 1; i<n; i++) {
		printf("Enter the element for the node %d: ", i+1);
		scanf("%d", &data);
		head = addAtEnd(head, data);
	}
	return head;
}

struct node* delFirst(struct node* head) {
	struct node* temp = head;
	head = head -> next;
	free(temp);
	temp = NULL;
	head -> prev = NULL;
	return head;
}

int main(){
	struct node* head = NULL;
	struct node* ptr;
	
//	head = createList(head);
	head = addToEmpty(head,34);
	head = addAtEnd(head, 45);
	head = addAtEnd(head, 3);

	printf("Before deletion\n");
	ptr = head;
	while(ptr != NULL) {
		printf("%d ",ptr -> data);
		ptr = ptr -> next;	
	}
	printf("\nAfter Deletion\n");
	head = delFirst(head);
	ptr = head;
	while(ptr != NULL) {
		printf("%d ",ptr -> data);
		ptr = ptr -> next;	
	}
	return 0;
	
}
