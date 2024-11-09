#include <sort.h>
#include <utils.h>

int brickSort(void *collection, size_t size_of_collection, size_t element_size, int (*pointer_to_function)(void *, void *))
{
    if (!collection || size_of_collection <= 0 || element_size <= 0 || !pointer_to_function)
        return FAILURE;
    int e, swap;
    swap = 1;
    while (swap != 0)
    {
        swap = 0;
        e = 1;
        while (e < size_of_collection - 1)
        {
            if (pointer_to_function(collection + e * element_size, collection + (e + 1) * element_size) > 0)
            {
                int check = _swap(collection + e * element_size, collection + (e + 1) * element_size, element_size);
                if (!check)
                    return FAILURE;
                swap = 1;
            }
            e++;
        }
        e = 0;
        while (e < size_of_collection - 1)
        {
            if (pointer_to_function(collection + e * element_size, collection + (e + 1) * element_size) > 0)
            {
                int check = _swap(collection + e * element_size, collection + (e + 1) * element_size, element_size);
                if (!check)
                    return FAILURE;
                swap = 1;
            }
            e++;
        }
    }
    return SUCCESS;
}