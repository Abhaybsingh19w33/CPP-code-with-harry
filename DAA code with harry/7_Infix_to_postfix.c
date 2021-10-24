#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    char *arr;
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
        // return;
    }
    else
    {

        ptr->top--;
        return ptr->arr[ptr->top + 1];
    }
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

int precedence(char ch)
{
    if (ch == '*' || ch == '/')
    {
        return 3;
    }
    else if (ch == '+' || ch == '-')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

int isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
    {
        return 1;
    }

    return 0;
}
char *infixToPostfix(char *infix)
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char *postfix = (char *)malloc((strlen(infix + 1)) * sizeof(char));
    int i = 0;
    int j = 0;
    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
        {
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else
        {
            if (precedence(infix[i]) > precedence(stackTop(sp)))
            {
                push(sp, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
    while (!isEmpty(sp))
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char *infix = "x-y/z-k*d";
    printf("postfix is %s", infixToPostfix(infix));
    return 0;
}
