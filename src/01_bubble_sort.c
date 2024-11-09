#include <sort.h>
#include <utils.h>

int bubbleSort(void *collection, size_t size_of_collection, size_t element_size, int (*pointer_to_function)(void *, void *))
{
    if (!collection || size_of_collection <= 0 || element_size <= 0 || !pointer_to_function)
        return FAILURE;
    int e, m, f, check;
    m = size_of_collection - 2;
    while (m >= 0)
    {
        e = 0;
        f = 1;
        while (e <= m)
        {
            if (pointer_to_function(collection + (f * element_size), collection + (e * element_size)) < 0)
            {
                check = _swap(collection + (f * element_size), collection + (e * element_size), element_size);
                if (!check)
                    return FAILURE;
            }
            e++;
            f++;
        }
        m--;
    }
    return SUCCESS;
}
