#include <stdio.h>
#include <stdlib.h>

struct Node *f = NULL;
struct Node *r = NULL;
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

struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *temp = createNode(data);
    if (head == NULL)
    {
        temp = head;
        temp->next = head;
    }
    else
    {
        struct Node *ptr = head;
        while (ptr->next != head)
        {
            ptr = ptr->next;
        }

        ptr->next = temp;
        temp->next = head;
        head = temp;
    }

    return head;
}

struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *temp = createNode(data);
    if (head == NULL)
    {
        temp = head;
        temp->next = head;
    }
    else
    {
        struct Node *ptr = head;
        while (ptr->next != head)
        {
            ptr = ptr->next;
        }

        ptr->next = temp;
        temp->next = head;
    }

    return head;
}
void traverseCCLinkedList(struct Node *head)
{
//    printf("printing the elements of LL");
    // if there is no node
    if (head == NULL)
    {
        return;
    }

    struct Node *ptr = head;
    do
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

void enqueue(int val)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL)
    {
        printf("Queue is full");
    }
    else
    {
        n->data = val;
        n->next = NULL;
        if (f == NULL)
        {
            f = r = n;
        }
        else
        {
            r->next = n;
            r = n;
        }
    }
}
int dequeue()
{
    int val = -1;
    struct Node *ptr = f;
    if (f == NULL)
    {
        printf("Queue is empty");
    }
    else
    {
        f = f->next;
        val = ptr->data;
        free(ptr);
    }
    return val;
}
int main()
{
    printf("dequeue %d\n", dequeue());
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);
    printf("\ndequeue %d\n", dequeue());

    traverseCCLinkedList(f);
    return 0;
}
