#include <utils.h>
#include <sort.h>
#include <stddef.h>

int radixSort(int *collection, size_t size_of_collection)
{
    if (size_of_collection <= 0)
        return FAILURE;
    int digit1, digit2, digit, smallest, largest, place, y, i, e, f, k;
    Queue p_queue[10], n_queue[10];
    for (y = 0; y < 10; y++) // initializing both queues
    {
        initQueue(&p_queue[y]);
        initQueue(&n_queue[y]);
    }

    // calculating the largest digit
    for (y = 1, smallest = largest = collection[0]; y < size_of_collection; y++)
    {
        if (collection[y] < smallest)
            smallest = collection[y];
        if (collection[y] > largest)
            largest = collection[y];
    }

    digit1 = 0;
    while (largest != 0)
    {
        largest /= 10;
        digit1++;
    }
    digit2 = 0;
    while (smallest != 0)
    {
        smallest /= 10;
        digit2++;
    }
    if (digit1 > digit2)
        digit = digit1;
    else
        digit = digit2;

    // Radix Sort

    for (y = 0, f = 1, e = 10; y < digit; y++, e *= 10, f *= 10)
    {
        for (i = 0; i < size_of_collection; i++)
        {
            place = (collection[i] % e) / f;
            if (place <= 0 && collection[i] < 0)
            {
                addToQueue(&n_queue[place * (-1)], collection[i]);
            }
            else
            {
                addToQueue(&p_queue[place], collection[i]);
            }
        }
        // for negetive values
        i = 0;
        for (k = 9; k > -1; k--)
        {
            while (!isQueueEmpty(&n_queue[k]))
            {
                collection[i] = removeFromQueue(&n_queue[k]);
                i++;
            }
        }
        // for positive values
        for (k = 0; k < 10; k++)
        {
            while (!isQueueEmpty(&p_queue[k]))
            {
                collection[i] = removeFromQueue(&p_queue[k]);
                i++;
            }
        }
    }
    return SUCCESS;
}
