#include <stddef.h>
#include <sort.h>
#include <stdlib.h>

int countingSort(int *collection, size_t size_of_collection)
{
    if (!collection || size_of_collection <= 0)
        return FAILURE;
    int largest, k, e, f;
    int *temp;
    for (e = 1, largest = collection[0]; e < size_of_collection; e++)
    {
        if (collection[e] > largest)
        {
            largest = collection[e];
        }
    }
    largest++;
    temp = (int *)calloc(largest, sizeof(int));
    if (!temp)
        return FAILURE;
    for (e = 0; e < size_of_collection; e++)
    {
        temp[collection[e]]++;
    }
    k = 0;
    for (e = 0; e < largest; e++)
    {
        for (f = 0; f < temp[e]; f++)
        {
            collection[k] = e;
            k++;
        }
    }
    return SUCCESS;
}