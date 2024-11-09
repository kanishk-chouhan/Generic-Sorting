#include <stdio.h>
#include "../include/sort.h"
#include <stdlib.h>
#include <time.h>
int intComparator(void *left, void *right)
{
    int *a, *b;
    a = (int *)left;
    b = (int *)right;
    return *a - *b;
}

int main()
{
    int *x, req, y;
    printf("Enter your requirement: ");
    scanf("%d", &req);
    if (req < 0)
    {
        printf("Invalid requirement\n");
        return 0;
    }
    x = (int *)malloc(sizeof(int) * req);
    srand(time(NULL));
    for (y = 0; y < req; y++)
    {
        // printf("Enter a number: ");
        // scanf("%d", &x[y]);
        x[y] = rand();
    }
    binaryInsertionSort(x, req, sizeof(int), intComparator);
    for (y = 0; y < req; y++)
    {
        printf("%d\n", x[y]);
    }
    free(x);
    return 0;
}