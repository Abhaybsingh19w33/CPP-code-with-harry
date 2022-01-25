#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void print(struct node *tail)
{
    struct node *p = tail->next;
    do {
        printf("%d ", p->data);
        p = p->next;
    } while (p != tail->next);
}

struct node *addToEmpty(int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = temp;
    return temp;
}

struct node *addAtBeg(struct node *tail, int data)
{
    struct node *newP = malloc(sizeof(struct node));
    newP->data = data;
    newP->next = tail->next;
    tail->next = newP;
    // in circular linked list tail is returned not head
    return tail;
}

int main()
{
    struct node* tail;
    tail = addToEmpty(45);
    tail = addAtBeg(tail,34);
    tail = addAtBeg(tail,33);

    print(tail);
    printf("\n");
    // printf("%d\n", tail->data);
    return 0;
}