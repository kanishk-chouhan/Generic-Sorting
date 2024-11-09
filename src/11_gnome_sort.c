#include <utils.h>
#include <sort.h>

int gnomeSort(void *collection, size_t size_of_collection, size_t element_size, int (*pointer_to_function)(void *, void *))
{
    if (!collection || size_of_collection <= 0 || element_size <= 0 || !pointer_to_function)
        return FAILURE;
    int f;
    for (f = 1; f < size_of_collection;)
    {
        if (f == 0)
            f++;
        if (pointer_to_function(collection + f * element_size, collection + (f - 1) * element_size) < 0)
        {
            int check = _swap(collection + f * element_size, collection + (f - 1) * element_size, element_size);
            if (!check)
                return FAILURE;
        }
        else
            f++;
    }
    return SUCCESS;
}
