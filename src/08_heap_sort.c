#include <utils.h>
#include <sort.h>
#include <stddef.h>
int convertToMaxHeap(void *collection, size_t size_of_collection, size_t element_size, int (*pointer_to_function)(void *, void *))
{
    size_t child_index, root_index, left_child_index, right_child_index, swapping_index;
    int check;
    root_index = 0;
    while (root_index < size_of_collection)
    {
        left_child_index = (root_index * 2) + 1;
        if (left_child_index > size_of_collection)
            break;
        right_child_index = left_child_index + 1;
        if (right_child_index > size_of_collection)
            swapping_index = left_child_index;
        else
        {
            if (pointer_to_function(collection + left_child_index * element_size, collection + right_child_index * element_size) > 0)
                swapping_index = left_child_index;
            else
                swapping_index = right_child_index;
        }
        if (pointer_to_function(collection + swapping_index * element_size, collection + root_index * element_size) > 0)
        {
            check = _swap(collection + swapping_index * element_size, collection + root_index * element_size, element_size);
            if (!check)
                return FAILURE;
            root_index = swapping_index;
        }
        else
            break;
    }
    return SUCCESS;
}
int heapSort(void *collection, size_t size_of_collection, size_t element_size, int (*pointer_to_function)(void *, void *))
{
    size_t child_index, root_index, y;
    int check;
    y = 1;
    while (y < size_of_collection)
    {
        child_index = y;
        while (child_index > 0)
        {
            root_index = (child_index - 1) / 2;
            if (pointer_to_function(collection + child_index * element_size, collection + root_index * element_size) > 0)
            {
                check = _swap(collection + child_index * element_size, collection + root_index * element_size, element_size);
                if (!check)
                    return FAILURE;
                child_index = root_index;
            }
            else
                break;
        }
        y++;
    }
    y = size_of_collection - 1;
    while (y > 0)
    {
        check = _swap(collection, collection + y * element_size, element_size);
        if (!check)
            return FAILURE;
        y--;
        convertToMaxHeap(collection, y, element_size, pointer_to_function);
    }
    return SUCCESS;
}
