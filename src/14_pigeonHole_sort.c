#include <stddef.h>
#include <sort.h>
#include <utils.h>
#include <stdlib.h>

int pigeonHoleSort(int *collection, size_t size_of_collection)
{
    if (!collection || size_of_collection <= 0)
        return FAILURE;

    int min, max, e, range, idx, k;
    Queue *queue;
    for (min = max = collection[0], e = 1; e < size_of_collection; e++) // finding minimum and maximum
    {
        if (collection[e] < min)
            min = collection[e];
        if (collection[e] > max)
            max = collection[e];
    }
    range = (max - min) + 1; // calculating range OR number of linked list required
    queue = (Queue *)malloc(sizeof(Queue) * range);
    if (!queue)
        return FAILURE;

    // initializing queue to NULL and 0
    for (e = 0; e < range; e++)
        initQueue(&queue[e]);

    for (e = 0; e < size_of_collection; e++) // spreading ints into linked lists
    {
        idx = collection[e] - min;
        addToQueue(&queue[idx], collection[e]);
    }

    for (e = 0, k = 0; e < range; e++) // collecting ints from linked list to original collection
    {
        while (!isQueueEmpty(&queue[e]))
        {
            collection[k] = removeFromQueue(&queue[e]);
            k++;
        }
    }
    return SUCCESS;
}