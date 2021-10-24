#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(struct stack *ptr)
{
    if (ptr->top == (ptr->size - 1))
    {
        return 1;
    }

    return 0;
}

void push(struct stack *ptr, int data)
{
    if (isFull(ptr))
    {
        printf("Stack is full can not push");
        return;
    }

    ptr->top++;
    ptr->arr[ptr->top] = data;
}

int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack is Empty");
        return;
    }
    ptr->top--;
    return ptr->arr[ptr->top + 1];
}

void traverseStack(struct stack *ptr)
{
    int i = 0;
    if (isEmpty(ptr))
    {
        printf("Stack is Empty");
        return;
    }
    for (i = 0; i <= ptr->top; i++)
    {
        printf("%d ", ptr->arr[i]);
    }
}

int peek(struct stack *ptr, int index)
{
    // if (index >= ptr->size)
    // {
    //     printf("out of bounds\n");
    //     return -1;
    // }
    int arrIndex = ptr->top - index + 1;
    if (arrIndex < 0)
    {
        printf("Not a valid position\n");
        return -1;
    }

    return ptr->arr[arrIndex];
}

int stackTop(struct stack *ptr)
{
    return ptr->arr[ptr->top];
}

int stackBottom(struct stack *ptr)
{
    return ptr->arr[0];
}

int main()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1;

    s->arr = (int *)malloc(s->size * sizeof(int));

    push(s, 4);
    push(s, 5);
    push(s, 6);
    push(s, 7);
    push(s, 8);
    if (isEmpty(s))
    {
        printf("the stack is empty\n");
    }
    else
    {
        printf("the stack is not empty\n");
    }

    // pop(s);
    traverseStack(s);
    printf("\n");
    // printf("%d \n", peek(s, 1));
    // printf("%d \n", peek(s, 2));
    // printf("%d \n", peek(s, 3));
    // printf("%d \n", peek(s, 4));
    // printf("%d \n", peek(s, 5));
    // printf("%d \n", peek(s, 6));
    printf("%d ",stackTop(s));
    printf("\n%d ",stackBottom(s));
    return 0;
}
