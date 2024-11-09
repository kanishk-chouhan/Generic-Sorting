#include <stddef.h>
#include <sort.h>
#include <utils.h>

int pancakeSort(void *collection, size_t size_of_collection, size_t element_size, int (*pointer_to_function)(void *, void *))
{
    if (!collection || size_of_collection <= 0 || element_size <= 0 || !pointer_to_function)
        return FAILURE;
    int e, j, endPoint;
    endPoint = size_of_collection - 1;
    while (endPoint > 0)
    {
        for (j = 1, e = 0; j <= endPoint; j++)
        {
            if (pointer_to_function(collection + j * element_size, collection + e * element_size) > 0)
                e = j;
        }
        if (e == endPoint)
        {
            endPoint--;
            continue;
        }
        j = 0;
        while (j < e)
        {
            int check = _swap(collection + j * element_size, collection + e * element_size, element_size);
            if (!check)
                return FAILURE;
            j++;
            e--;
        }
        j = 0;
        e = endPoint;
        while (j < e)
        {
            int check = _swap(collection + j * element_size, collection + e * element_size, element_size);
            if (!check)
                return FAILURE;
            j++;
            e--;
        }
        endPoint--;
    }
    return SUCCESS;
}