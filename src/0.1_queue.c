#include <utils.h>
#include <stdlib.h>
void initQueue(Queue *queue)
{
    queue->start = NULL;
    queue->end = NULL;
    queue->size = 0;
}
void addToQueue(Queue *queue, int num)
{
    QueueNode *t;
    t = (QueueNode *)malloc(sizeof(QueueNode));
    t->data = num;
    t->next = NULL;
    if (!queue->start)
    {
        queue->start = t;
        queue->end = t;
    }
    else
    {
        queue->end->next = t;
        queue->end = t;
    }
    queue->size++;
}
int removeFromQueue(Queue *queue)
{
    if (!queue->size)
    {
        return 0;
    }
    int num;
    num = queue->start->data;
    QueueNode *t;
    t = queue->start;
    queue->start = queue->start->next;
    free(t);
    queue->size--;
    if (!queue->size)
    {
        queue->end = NULL;
    }
    return num;
}

int isQueueEmpty(Queue *queue)
{
    return queue->size == 0;
}