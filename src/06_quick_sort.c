#include <utils.h>
#include <stddef.h>

int findPartitionPoint(void *collection, size_t lower_bound, size_t upper_bound, size_t element_size, int (*pointer_to_function)(void *, void *))
{
    int e, f;
    e = lower_bound;
    f = upper_bound;
    while (e < f)
    {
        while (e < upper_bound && pointer_to_function(collection + e * element_size, collection + lower_bound * element_size) <= 0)
            e++;
        while (pointer_to_function(collection + f * element_size, collection + lower_bound * element_size) > 0)
            f--;
        if (e < f)
            _swap(collection + e * element_size, collection + f * element_size, element_size);
        else
            _swap(collection + lower_bound * element_size, collection + f * element_size, element_size);
    }
    return f;
}
void quickSort(void *collection, size_t lower_bound, size_t upper_bound, size_t element_size, int (*pointer_to_function)(void *, void *))
{
    size_t partition_point;
    if (upper_bound <= lower_bound)
        return;
    partition_point = findPartitionPoint(collection, lower_bound, upper_bound, element_size, pointer_to_function);
    if (partition_point > 0)
        quickSort(collection, lower_bound, partition_point - 1, element_size, pointer_to_function);
    quickSort(collection, partition_point + 1, upper_bound, element_size, pointer_to_function);
}
