#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

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
    return tail;
}

struct node *addAtEnd(struct node *tail, int data)
{
    struct node *newP = malloc(sizeof(struct node));
    newP->data = data;
    newP->next = NULL;

    newP->next = tail->next;
    tail->next = newP;
    tail = tail->next;
    return tail;
}

struct node *addAfterPos(struct node *tail, int data, int pos)
{
    struct node *p = tail->next;
    struct node *newP = malloc(sizeof(struct node));
    newP->data = data;
    newP->next = NULL;

    while (pos > 1)
    {
        p = p->next;
        pos--;
    }

    newP->next = p->next;
    p->next = newP;
    if (p == tail)
    {
        tail = tail->next;
    }
    return tail;
}
struct node *delLast(struct node *tail)
{
    if (tail == NULL)
        return tail;
    struct node *temp = tail->next;
    if (tail->next == tail)
    {
        free(tail);
        tail = NULL;
        return tail;
    }
    while (temp->next != tail)
    {
        temp = temp->next;
    }
    temp->next = tail->next;
    free(tail);
    tail = temp;
    return tail;
}

void print(struct node *tail)
{
    if (tail == NULL)
    {
        printf("No node in the list");
    }
    else
    {
        struct node *p = tail->next;
        do
        {
            printf("%d ", p->data);
            p = p->next;
        } while (p != tail->next);
    }
}

struct node *createList(struct node *tail)
{
    int i, n, data;
    printf("Enter the number of nodes of the linked list: ");
    scanf("%d", &n);

    if (n == 0)
    {
        return tail;
    }

    printf("Enter the element 1: ");
    scanf("%d", &data);
    tail = addToEmpty(data);

    for (i = 1; i < n; i++)
    {
        printf("Enter the element %d ", i + 1);
        scanf("%d", &data);
        tail = addAtEnd(tail, data);
    }
    return tail;
}

struct node *delFirst(struct node *tail)
{
    if (tail == NULL)
        return tail;
    if (tail->next == tail)
    {
        free(tail);
        tail = NULL;
        return tail;
    }
    struct node *temp = tail->next;
    tail->next = temp->next;
    free(temp);
    temp = NULL;
    return tail;
}

struct node *delInter(struct node *tail, int pos)
{
    if (tail == NULL)
        return tail;
    struct node *temp = tail->next;
    if (tail->next == tail)
    {
        free(tail);
        tail = NULL;
        return tail;
    }
    while (pos > 2)
    {
        temp = temp->next;
        pos--;
    }
    struct node *temp2 = temp->next;
    temp->next = temp2->next;
    // handling the case of deleting last node
    if (temp2 == tail)
        tail = temp;
    free(temp2);
    temp2 = NULL;
    return tail;
}

void countElements(struct node *tail)
{
    struct node *temp = tail->next;
    int count = 0;
    while (temp != tail)
    {
        temp = temp->next;
        count++;
    }
    count++;
    printf("There are %d elements in the list.\n", count);
}

int searchElement(struct node *tail, int element)
{
    struct node *temp;
    int index = 0;
    if (tail == NULL)
        return -2;

    temp = tail->next;
    do
    {
        if (temp->data == element)
            return index;
        temp = temp->next;
        index++;
    } while (temp != tail->next);
    return -1;
}
int main()
{
    struct node *tail = NULL;
    // tail = createList(tail);
    tail = addToEmpty(2);
    tail = addAtEnd(tail, 3);
    tail = addAtEnd(tail, 4);
    tail = addAtEnd(tail, 5);
    tail = addAtEnd(tail, 6);
    tail = addAtEnd(tail, 7);
    print(tail);
    printf("\n");

    printf("%d ", searchElement(tail, 4));
    printf("%d ", searchElement(tail, 5));
    printf("%d ", searchElement(tail, 6));

    int element = 0;
    printf("Enter the elements: ");
    scanf("%d", &element);

    int index = searchElement(tail, element);
    if (index == -1)
    {
        printf("Element not found!");
        printf("Element not found!");
    }
    else if (index == -2)
    {
        printf("Linked list in empty!");
    }
    else
    {
        printf("Element %d is at index %d", element, index);
    }
    return 0;
}