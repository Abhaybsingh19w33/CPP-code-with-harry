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

//void reverse(struct node *head){
//	struct node *newHead = malloc(sizeof(struct node));
//	newHead -> link = NULL;
////	= malloc(sizeof(struct node));
//    while( head->link != NULL) {
//        if(newHead->link == NULL) {
//            newHead->data = head->data;    
//            printf("%d ",newHead->data);
//        }
//        else {
//        	struct node *temp = malloc(sizeof(struct node));
//        	temp -> data = head -> data;
//        	printf("%d ",temp->data);
//            temp->link = newHead;
////            newHead = temp;
//			temp = newHead;
//        }
//        head = head ->link;
//    }
//    
//    head = newHead;
//    
//    print_data(head);
////    return head;
//}

void reverse(struct node *head){
	struct node *prevNode = malloc(sizeof(struct node));
	struct node *curNode = malloc(sizeof(struct node));
	if(head != NULL) {
		prevNode = head;
        head = head->link;
        curNode = head;
        prevNode->link = NULL;
        while (head != NULL) {
            head = head->link;
            curNode->link = prevNode;
            prevNode = curNode;
            curNode = head;
		}
        head = prevNode;
	}
	
	print_data(head);    
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
	
//	here we are passing the address of first node 
//	so we may think that we should not return any value
//	so we may only write add_beg(head, data);

	head = add_beg(head, data);
	ptr = head;
	
	while(ptr != NULL) {
		printf("%d ", ptr->data);
		ptr = ptr->link;
	}
	printf("\nreverse\n");
	reverse(head);
	return 0;
}
