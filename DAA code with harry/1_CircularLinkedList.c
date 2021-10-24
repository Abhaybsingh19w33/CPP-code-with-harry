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
        head =temp;
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
int main()
{
    struct Node *head = createNode(45);
    head->next = head;

    head = insertAtEnd(head, 46);
    head = insertAtEnd(head, 47);
    head = insertAtEnd(head, 48);
    head = insertAtEnd(head, 49);
    head = insertAtFirst(head, 44);
    head = insertAtFirst(head, 43);

    traverseCCLinkedList(head);
    return 0;
}
