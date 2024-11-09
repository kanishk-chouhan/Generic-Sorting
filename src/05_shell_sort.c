#include <stdlib.h>
#include <string.h>
#include <sort.h>

int shellSort(void *collection, size_t size_of_collection, size_t element_size, int (*pointer_to_function)(void *, void *))
{
    if (!collection || size_of_collection <= 0 || element_size <= 0 || !pointer_to_function)
        return FAILURE;
    int e, f, difference;
    void *temp;
    temp = (void *)malloc(element_size);
    if (!temp)
        return FAILURE;
    difference = size_of_collection / 2;
    while (difference > 0)
    {
        e = difference;
        while (e < size_of_collection)
        {
            f = e - difference;
            memcpy(temp, collection + e * element_size, element_size);
            while (f > -1 && pointer_to_function(collection + f * element_size, temp) > 0)
            {
                memcpy(collection + (f + difference) * element_size, collection + f * element_size, element_size);
                f -= difference;
            }
            memcpy(collection + (f + difference) * element_size, temp, element_size);
            e += difference;
        }
        difference /= 2;
    }

    return SUCCESS;
}
