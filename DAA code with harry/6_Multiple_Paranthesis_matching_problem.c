#include <stdio.h>
#include <stdlib.h>

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

void push(struct stack *ptr, char data)
{
    if (isFull(ptr))
    {
        printf("Stack is full can not push");
        return;
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = data;
    }
}

char pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack is Empty");
        return -1;
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
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

int match(char a, char b)
{
    if (a == '{' && b == '}')
    {
        return 1;
    }
    if (a == '(' && b == ')')
    {
        return 1;
    }
    if (a == '[' && b == ']')
    {
        return 1;
    }
    return 0;
}

int parenthesisMatch(char *exp)
{
    // Create and initialize the stack
    struct stack *sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char popped_ch;

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(sp, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (isEmpty(sp))
            {
                return 0;
            }
            popped_ch = pop(sp);
            if (!match(popped_ch, exp[i]))
            {
                return 0;
            }
        }
    }
    if (isEmpty(sp))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    char *exp = "[4-6]((8){(9-8)})";
    if (parenthesisMatch(exp))
    {
        printf("the parenthesis is Match\n");
    }
    else
    {
        printf("the parenthesis is not Match\n");
    }
    return 0;
}

// int main()
// {
//     char * exp = "[4-6]((8){(9-8)})";
//     if(parenthesisMatch(exp)){
//         printf("The parenthesis is balanced");
//     }
//     else{
//         printf("The parenthesis is not balanced");
//     }
//     return 0;
// }