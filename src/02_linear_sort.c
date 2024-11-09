#include <sort.h>
#include <utils.h>

int linearSort(void *collection, size_t size_of_collection, size_t element_size, int (*pointer_to_function)(void *, void *))
{
    if (!collection || size_of_collection <= 0 || element_size <= 0 || !pointer_to_function)
        return FAILURE;
    int e, f, check;
    e = 0;
    while (e < size_of_collection - 1)
    {
        f = e + 1;
        while (f < size_of_collection)
        {
            if (pointer_to_function(collection + e * element_size, collection + f * element_size) > 0)
            {
                check = _swap(collection + e * element_size, collection + f * element_size, element_size);
                if (!check)
                    return FAILURE;
            }
            f++;
        }
        e++;
    }
    return SUCCESS;
}
