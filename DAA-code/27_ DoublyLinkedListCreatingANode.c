#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *prev;
	struct node *next;
};

int main(){
	struct node *head = malloc(sizeof(struct node));
	head -> prev = NULL;
	head -> data = 10;
	head -> next = NULL;
}
