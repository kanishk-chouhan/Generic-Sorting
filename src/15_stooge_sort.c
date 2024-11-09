#include <stddef.h>
#include <utils.h>
#include <sort.h>
void stoogeSort(void *collection, size_t lower_bound, size_t upper_bound, size_t element_size, int (*pointer_to_function)(void *, void *))
{
    if (lower_bound >= upper_bound)
        return;

    // If first element is greater than the last, swap them
    if (pointer_to_function(collection + lower_bound * element_size, collection + upper_bound * element_size) > 0)
        _swap(collection + lower_bound * element_size, collection + upper_bound * element_size, element_size);

    // If there are more than two elements in the array
    if (upper_bound - lower_bound + 1 > 2)
    {
        int t = (upper_bound - lower_bound + 1) / 3;

        // Recursively sort the first 2/3 elements
        stoogeSort(collection, lower_bound, upper_bound - t, element_size, pointer_to_function);

        // Recursively sort the last 2/3 elements
        stoogeSort(collection, lower_bound + t, upper_bound, element_size, pointer_to_function);

        // Recursively sort the first 2/3 elements again
        stoogeSort(collection, lower_bound, upper_bound - t, element_size, pointer_to_function);
    }
}