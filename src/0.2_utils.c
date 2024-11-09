#include <utils.h>
#include <stdlib.h>
#include <string.h>

int _swap(void *x, void *y, size_t element_size)
{
    if (element_size <= 0)
        return 0;
    if (!x || !y)
        return 0;
    void *temp;
    temp = (void *)malloc(element_size);
    if (!temp)
        return 0;
    memcpy(temp, x, element_size);
    memcpy(x, y, element_size);
    memcpy(y, temp, element_size);
    free(temp);
    return 1;
}