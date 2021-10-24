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

int main(){
	struct node *head = NULL;
	head = addToEmpty(head,45);
	printf("%d ",head -> data);
}
