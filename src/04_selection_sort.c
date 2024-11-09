#include <sort.h>
#include <utils.h>

int selectionSort(void *collection, size_t size_of_collection, size_t element_size, int (*pointer_to_function)(void *, void *))
{
    if (!collection || size_of_collection <= 0 || element_size <= 0 || !pointer_to_function)
        return FAILURE;
    int e, f, smallest_index, check;
    e = 0;
    while (e < size_of_collection - 1)
    {
        f = e + 1;
        smallest_index = e;
        while (f < size_of_collection)
        {
            if (pointer_to_function(collection + f * element_size, collection + smallest_index * element_size) < 0)
                smallest_index = f;
            f++;
        }
        check = _swap(collection + e * element_size, collection + smallest_index * element_size, element_size);
        if (!check)
            return FAILURE;
        e++;
    }

    return SUCCESS;
}
