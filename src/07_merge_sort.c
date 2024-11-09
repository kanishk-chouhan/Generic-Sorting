#include <utils.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
void merge(void *collection, size_t lower_bound, size_t mid, size_t upper_bound, size_t element_size, int (*pointer_to_function)(void *, void *))
{
    int i1, i2, i3;
    size_t tempSize, lb1, lb2, ub1, ub2, lb3, ub3;
    void *temp;
    tempSize = (upper_bound - lower_bound) + 1;
    temp = (void *)malloc(element_size * tempSize);
    lb1 = lower_bound;
    ub1 = mid;
    lb2 = mid + 1;
    ub2 = upper_bound;
    lb3 = 0;
    ub3 = tempSize - 1;
    i1 = lb1;
    i2 = lb2;
    i3 = lb3;
    while (i1 <= ub1 && i2 <= ub2)
    {
        if (pointer_to_function(collection + i1 * element_size, collection + i2 * element_size) < 0)
        {
            memcpy(temp + i3 * element_size, collection + i1 * element_size, element_size);
            i1++;
        }
        else
        {
            memcpy(temp + i3 * element_size, collection + i2 * element_size, element_size);
            i2++;
        }
        i3++;
    }
    while (i1 <= ub1)
    {
        memcpy(temp + i3 * element_size, collection + i1 * element_size, element_size);
        i1++;
        i3++;
    }
    while (i2 <= ub2)
    {
        memcpy(temp + i3 * element_size, collection + i2 * element_size, element_size);
        i2++;
        i3++;
    }
    i1 = lb1;
    i3 = 0;
    while (i1 <= ub2)
    {
        memcpy(collection + i1 * element_size, temp + i3 * element_size, element_size);
        i3++;
        i1++;
    }
    free(temp);
}

void mergeSort(void *collection, size_t lower_bound, size_t upper_bound, size_t element_size, int (*pointer_to_function)(void *, void *))
{
    int mid;
    if (lower_bound < upper_bound)
    {
        mid = (lower_bound + upper_bound) / 2;
        mergeSort(collection, lower_bound, mid, element_size, pointer_to_function);
        mergeSort(collection, mid + 1, upper_bound, element_size, pointer_to_function);
        merge(collection, lower_bound, mid, upper_bound, element_size, pointer_to_function);
    }
}