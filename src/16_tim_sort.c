#include <stddef.h>
#include <string.h>
#include <stdlib.h>
void insertionSort(void *collection, int lower_bound, int upper_bound, size_t element_size, int (*pointer_to_function)(void *, void *))
{
    int e, f;
    void *element;
    element = (void *)malloc(element_size);
    e = lower_bound + 1;
    while (e <= upper_bound)
    {
        f = e - 1;
        memcpy(element, collection + e * element_size, element_size);
        while (f >= lower_bound && pointer_to_function(collection + f * element_size, element) > 0)
        {
            memcpy(collection + (f + 1) * element_size, collection + f * element_size, element_size);
            f--;
        }
        memcpy(collection + (f + 1) * element_size, element, element_size);
        e++;
    }
}
void merge(void *collection, int lower_bound1, int upper_bound1, int lower_bound2, int upper_bound2, size_t element_size, int (*pointer_to_function)(void *, void *))
{
    int i1, i2, i3;
    size_t tempSize;
    void *temp;
    tempSize = (upper_bound2 - lower_bound1) + 1;
    temp = (void *)malloc(element_size * tempSize);
    i1 = lower_bound1;
    i2 = lower_bound2;
    i3 = 0;
    while (i1 <= upper_bound1 && i2 <= upper_bound2)
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
    while (i1 <= upper_bound1)
    {
        memcpy(temp + i3 * element_size, collection + i1 * element_size, element_size);
        i1++;
        i3++;
    }
    while (i2 <= upper_bound2)
    {
        memcpy(temp + i3 * element_size, collection + i2 * element_size, element_size);
        i2++;
        i3++;
    }
    i1 = lower_bound1;
    i3 = 0;
    while (i1 <= upper_bound2)
    {
        memcpy(collection + i1 * element_size, temp + i3 * element_size, element_size);
        i3++;
        i1++;
    }
    free(temp);
}

void timSort(void *collection, size_t size_of_collection, size_t element_size, int (*pointer_to_function)(void *, void *))
{
    int lower_bound, upper_bound, z, mid;
    z = 32; // partition Number
    lower_bound = 0;
    upper_bound = z - 1;
    while (lower_bound < size_of_collection)
    {
        if (size_of_collection <= upper_bound)
            upper_bound = size_of_collection - 1;
        insertionSort(collection, lower_bound, upper_bound, element_size, pointer_to_function);
        lower_bound = lower_bound + z;
        upper_bound = upper_bound + z;
    }
    while (z < size_of_collection)
    {
        lower_bound = 0;
        upper_bound = (2 * z) - 1;
        while (lower_bound < size_of_collection)
        {
            if (size_of_collection <= upper_bound)
            {
                upper_bound = size_of_collection - 1;
                mid = (lower_bound + z) - 1;
                if (size_of_collection <= mid)
                    break;
            }
            else
            {
                mid = (lower_bound + upper_bound) / 2;
            }
            merge(collection, lower_bound, mid, mid + 1, upper_bound, element_size, pointer_to_function);
            lower_bound = lower_bound + (2 * z);
            upper_bound = upper_bound + (2 * z);
        }
        z = z * 2;
    }
}