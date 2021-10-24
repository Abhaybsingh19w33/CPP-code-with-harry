#include <stdio.h>
#include <stdlib.h>
struct CircularQueue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct CircularQueue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}

int isFull(struct CircularQueue *q)
{
    if ((q->r+1)%q->size == q->f)
    {
        return 1;
    }
    return 0;
}
void enqueue(struct CircularQueue *q, int val)
{
    if (isFull(q))
    {  
        printf("CircularQueue is full");
    }
    else
    {
        q->r = (q->r +1)%q->size;
        q->arr[q->r] = val;
    }
}
int dequeue(struct CircularQueue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("CircularQueue is empty");
    }
    else
    {
        q->f = (q->f +1)%q->size;
        a = q->arr[q->f];
    }
    return a;
}
int main()
{
    struct CircularQueue q;
    q.size = 4;
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    if (isEmpty(&q))
    {
        printf("CircularQueue is empty");
    }

    // enqueue few elements
    enqueue(&q, 12);
    enqueue(&q, 15);
    enqueue(&q, 12);
    enqueue(&q, 15);
    if (isEmpty(&q))
    {
        printf("\nCircularQueue is empty");
    }
    if (isFull(&q))
    {
        printf("CircularQueue is empty");
    }
    printf("\nDequeing element %d", dequeue(&q));
    printf("\nDequeing element %d", dequeue(&q));
    printf("\nDequeing element %d", dequeue(&q));
    printf("\nDequeing element %d", dequeue(&q));
    if (isEmpty(&q))
    {
        printf("\nCircularQueue is empty");
    }
    if (isFull(&q))
    {
        printf("CircularQueue is empty");
    }
    enqueue(&q, 15);
    if (isEmpty(&q))
    {
        printf("\nCircularQueue is empty");
    }
    if (isFull(&q))
    {
        printf("CircularQueue is empty");
    }
    return 0;
}
