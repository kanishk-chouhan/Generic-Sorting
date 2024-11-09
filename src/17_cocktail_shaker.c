#include <sort.h>
#include <utils.h>
#include <stddef.h>

int cocktailShakerSort(void *collection, size_t size_of_collection, size_t element_size, int (*pointer_to_function)(void *, void *))
{
    if (!collection || size_of_collection <= 0 || element_size <= 0 || !pointer_to_function)
        return FAILURE;

    int start, end, swapped, check, i;
    start = 0;
    end = size_of_collection - 1;
    swapped = 1;
    while (swapped)
    {
        swapped = 0;
        for (i = start; i < end; i++)
        {
            if (pointer_to_function(collection + (i * element_size), collection + ((i + 1) * element_size)) > 0)
            {
                check = _swap(collection + (i * element_size), collection + ((i + 1) * element_size), element_size);
                if (!check)
                    return FAILURE;
                swapped = 1;
            }
        }
        if (!swapped)
            break;
        swapped = 0;
        for (i = end; i > start; i--)
        {
            if (pointer_to_function(collection + (i * element_size), collection + ((i - 1) * element_size)) < 0)
            {
                check = _swap(collection + (i * element_size), collection + ((i - 1) * element_size), element_size);
                if (!check)
                    return FAILURE;
                swapped = 1;
            }
        }
        start++;
        end--;
    }

    return SUCCESS;
}
