#include <sort.h>
#include <utils.h>
#include <string.h>
#include <stdlib.h>

int insertionSort(void *collection, size_t size_of_collection, size_t element_size, int (*pointer_to_function)(void *, void *))
{
    if (!collection || size_of_collection <= 0 || element_size <= 0 || !pointer_to_function)
        return FAILURE;
    int e, f;
    void *element;
    element = (void *)malloc(element_size);
    if (!element)
        return FAILURE;
    e = 1;
    while (e < size_of_collection)
    {
        f = e - 1;
        memcpy(element, collection + e * element_size, element_size);
        while (f > -1 && pointer_to_function(collection + f * element_size, element) > 0)
        {
            memcpy(collection + (f + 1) * element_size, collection + f * element_size, element_size);
            f--;
        }
        memcpy(collection + (f + 1) * element_size, element, element_size);

        e++;
    }
    free(element);
    return SUCCESS;
}
