#include <sort.h>
#include <string.h>
#include <stdlib.h>
int binarySearch(void *collection, size_t size_of_collection, size_t element_size, int (*pointer_to_function)(void *, void *))
{
    int starting_idx, ending_idx, middle_idx;
    void *element;
    starting_idx = 0;
    ending_idx = size_of_collection - 1;
    element = (void *)malloc(element_size);
    memcpy(element, collection + size_of_collection * element_size, element_size);
    while (starting_idx <= ending_idx)
    {
        middle_idx = starting_idx + (ending_idx - starting_idx) / 2;
        if (pointer_to_function(element, collection + middle_idx * element_size) == 0)
        {
            free(element);
            return middle_idx;
        }
        else if (pointer_to_function(element, collection + middle_idx * element_size) < 0)
            ending_idx = middle_idx - 1;
        else
            starting_idx = middle_idx + 1;
    }
    free(element);
    return starting_idx;
}
int binaryInsertionSort(void *collection, size_t size_of_collection, size_t element_size, int (*pointer_to_function)(void *, void *))
{
    if (!collection || size_of_collection <= 0 || element_size <= 0 || !pointer_to_function)
        return FAILURE;
    int e, position, j;
    void *element;
    element = (void *)malloc(element_size);
    if (!element)
        return FAILURE;
    for (e = 1; e < size_of_collection; e++)
    {
        memcpy(element, collection + e * element_size, element_size);
        position = binarySearch(collection, e, element_size, pointer_to_function);
        for (j = e - 1; j >= position; j--)
        {
            memcpy(collection + (j + 1) * element_size, collection + j * element_size, element_size);
        }
        memcpy(collection + position * element_size, element, element_size);
    }
    free(element);
    return SUCCESS;
}