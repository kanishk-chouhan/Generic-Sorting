#ifndef __SORT__
#define __SORT__
#include <stddef.h>
#define SUCCESS 1
#define FAILURE 0
int bubbleSort(void *, size_t, size_t, int (*)(void *, void *));
int linearSort(void *, size_t, size_t, int (*)(void *, void *));
int insertionSort(void *, size_t, size_t, int (*)(void *, void *));
int selectionSort(void *, size_t, size_t, int (*)(void *, void *));
int shellSort(void *, size_t, size_t, int (*)(void *, void *));
void quickSort(void *, size_t, size_t, size_t, int (*)(void *, void *));
void mergeSort(void *, size_t, size_t, size_t, int (*)(void *, void *));
int heapSort(void *, size_t, size_t, int (*)(void *, void *));
int radixSort(int *, size_t); // only integers
int pancakeSort(void *, size_t, size_t, int (*)(void *, void *));
int gnomeSort(void *, size_t, size_t, int (*)(void *, void *));
int brickSort(void *, size_t, size_t, int (*)(void *, void *));
int countingSort(int *, size_t);   // only positive integers
int pigeonHoleSort(int *, size_t); // only integers
void stoogeSort(void *, size_t, size_t, size_t, int (*)(void *, void *));
int timSort(void *, size_t, size_t, int (*)(void *, void *));
int cocktailShakerSort(void *, size_t, size_t, int (*)(void *, void *));
int binaryInsertionSort(void *, size_t, size_t, int (*)(void *, void *));
int addressCalculationSort(void *, size_t, size_t, int (*)(void *, void *));
#endif