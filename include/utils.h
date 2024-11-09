#ifndef __UTILS__
#define __UTILS__
#include <stddef.h>
int _swap(void *, void *, size_t);
#define swap(e, f) _swap(&e, &f, sizeof(e))
typedef struct __queueNode
{
    int data;
    struct __queueNode *next;
} QueueNode;

typedef struct __queue
{
    QueueNode *start, *end;
    size_t size;
} Queue;
void initQueue(Queue *queue);
void addToQueue(Queue *, int);
int removeFromQueue(Queue *);
int isQueueEmpty(Queue *);
#endif