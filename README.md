# Generic Sorting Algorithms Library

## _Efficient Sorting Algorithms for Various Data Types in C_

This is a comprehensive sorting library implemented in C, providing a wide range of sorting algorithms for handling both primitive data types and custom structures with custom comparator functions. 

The library includes the following features and folders:

- **Folder Structure:**
  - `include`: Contains header files (`sort.h` and `utils.h`).
  - `lib`: Contains compiled library files.
  - `src`: Contains the source code for the sorting algorithms.
  - `test`: Contains test files and examples.

## Features

- **Multiple Sorting Algorithms**: Includes over 17 sorting algorithms such as Bubble Sort, Quick Sort, Merge Sort, and Heap Sort, suitable for diverse sorting needs.
- **Custom Comparators**: Allows custom comparator functions for sorting complex data structures.
- **Efficient Utility Functions**: Provides additional utility functions like `swap` and queue management for internal use.

## Supported Sorting Algorithms

The library offers the following sorting algorithms:

- `bubbleSort`
- `linearSort`
- `insertionSort`
- `selectionSort`
- `shellSort`
- `quickSort`
- `mergeSort`
- `heapSort`
- `radixSort` (only for integers)
- `pancakeSort`
- `gnomeSort`
- `brickSort`
- `countingSort` (only for positive integers)
- `pigeonHoleSort` (only for integers)
- `stoogeSort`
- `timSort`
- `cocktailShakerSort`
- `binaryInsertionSort`
- `addressCalculationSort`

## Headers Overview

### sort.h

The `sort.h` file includes function declarations for each of the sorting algorithms. Most functions require parameters for the array to be sorted, the element size, the number of elements, and a comparator function pointer to handle custom data structures.

Example function declaration:
```c
int bubbleSort(void *array, size_t n, size_t elemSize, int (*compare)(void *, void *));

```
### utils.h

The utils.h file provides additional utility functions that support the sorting algorithms:

- swap: Swaps two elements in memory.
- Queue Management: Includes a queue data structure with functions to initialize, add, remove, and check if a queue is empty.

Example:

```c
void initQueue(Queue *queue);
void addToQueue(Queue *queue, int value);
int removeFromQueue(Queue *queue);
int isQueueEmpty(Queue *queue);
```

## Installation

Clone the repository to your local machine:

```sh
git clone https://github.com/your-repo-link.git
```

Copy the include and src files into your project directory.
Compilation and Usage
To compile, link the source files with your main program:

```sh
gcc -o main main.c src/*.c -Iinclude
```

## Example Usage

Here's a detailed example demonstrating how to use the bubbleSort function in this library.

Parameters
```sh
array: Pointer to the array to be sorted.
n: Number of elements in the array.
elemSize: Size of each element (use sizeof(type)).
compare: A pointer to a comparator function that takes two void pointers and returns:
0 if the two elements are equal,
a negative value if the first element is smaller,
a positive value if the first element is larger.
```

Example Code

Code:

```#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

// Comparator function for integers
int intComparator(void *a, void *b) {
    int x = *(int *)a;
    int y = *(int *)b;
    return x - y;
}

int main() {
    int arr[] = {5, 2, 9, 1, 5, 6};
    size_t n = sizeof(arr) / sizeof(arr[0]);

    // Sort the array using bubbleSort
    int result = bubbleSort(arr, n, sizeof(int), intComparator);

    // Check if sorting was successful
    if (result == SUCCESS) {
        printf("Sorted array: ");
        for (size_t i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
    } else {
        printf("Sorting failed.");
    }

    return 0;
}
```

Explanation

Define a Comparator: The intComparator function compares two integers, returning the difference between them.
Call bubbleSort: Pass the array, its length, the size of each element, and the comparator to bubbleSort.
Check Result: Verify if sorting was successful by checking if bubbleSort returned SUCCESS.
Print Result: Print the sorted array if successful.


# Contact

#### Email: kanishk.chouhan@example.com

#### LinkedIn: Kanishk Chouhan
