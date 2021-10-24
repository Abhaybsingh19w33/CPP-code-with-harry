#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

int pop(struct Node **top)
{
    if ((*top) == NULL)
    {
        printf("stck underflow");
        // return top;
    }
    else
    {
        struct Node *ptr = (*top);
        (*top) = (*top)->next;
        int x = ptr->data;
        free(ptr);
        return x;
    }
    // return top;
}

struct Node *push(struct Node *top, int data)
{
    struct Node *temp = createNode(data);
    if (top == NULL)
    {
        top = temp;
    }
    else
    {
        struct Node *ptr = top;
        temp->next = ptr;
        top = temp;
    }

    return top;
}

struct Node *insertAtEnd(struct Node *top, int data)
{
    struct Node *temp = createNode(data);
    if (top == NULL)
    {
        temp = top;
        // temp->next = top;
    }
    else
    {
        struct Node *ptr = top;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }

        ptr->next = temp;
    }

    return top;
}

int isEmpty(struct Node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    return 0;
}

int isFull()
{
    struct Node *temp = createNode(0);
    if (temp == NULL)
    {
        return 1;
    }
    return 0;
}
void traverseCCLinkedList(struct Node *top)
{
    // if there is no node
    if (top == NULL)
    {
        return;
    }

    struct Node *ptr = top;
    do
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != NULL);
}

int peek(struct Node *top, int index)
{
    if (isEmpty(top))
    {
        printf("stack underflow");
        return -1;
    }

    struct Node *ptr = top;
    int i = 0;
    for (i = 0; i < index - 1 && ptr != NULL; i++)
    {
        ptr = ptr->next;
    }
    if (ptr != NULL)
    {
        return ptr->data;
    }
    else
    {
        return -1;
    }
}

int stackTop(struct Node *top)
{
    return top->data;
}

int stackBottom(struct Node *top)
{
    if (isEmpty(top))
    {
        printf("stack underflow");
        // return;
    }

    while (top->next != NULL)
    {
        top = top->next;
    }
    return top->data;
}
int main()
{
    struct Node *top = createNode(45);

    top = push(top, 44);
    top = push(top, 43);
    top = push(top, 42);
    top = push(top, 41);
    top = push(top, 40);
    traverseCCLinkedList(top);
    // printf("\n");
    // printf("%d ", pop(&top));
    // printf("\n");
    // traverseCCLinkedList(top);
    // printf("\n%d ",peek(top,0));
    printf("\n%d ", peek(top, 1));
    printf("\n%d ", peek(top, 2));
    printf("\n%d ", peek(top, 3));
    printf("\n%d ", peek(top, 4));
    printf("\n%d ", peek(top, 5));
    printf("\n%d ", peek(top, 6));
    printf("\n%d ", peek(top, 7));
    printf("\n%d ", stackTop(top));
    printf("\n%d ", stackBottom(top));
    return 0;
}
