# Generic Sorting Algorithms Library
## _A Comprehensive Library of 17+ Sorting Algorithms for C and C++_


[![Build Status](https://travis-ci.org/joemccann/dillinger.svg?branch=master)](https://github.com/iam-harshprajapat/Generic-Sorting-Algorithm-library-in-C-CPP)

This is a generic data structure library built in C that supports sorting a variety of data types using 17+ different sorting algorithms. It is designed to work seamlessly with both C and C++ projects, offering developers flexibility and performance for their sorting needs.

- Written in C with support for C++
- Sort any type of data using custom comparator functions
- Comprehensive set of sorting algorithms

## Features

- Supports both primitive data types and user-defined structures.
- Easy-to-use comparator function for custom data sorting.
- Includes 17+ sorting algorithms:
  - Bubble Sort
  - Quick Sort
  - Merge Sort
  - Heap Sort
  - Radix Sort (for integers only)
  - and many more!

✨ Custom data type sorting with a function! ✨

## Tech

The library is built purely in C and can be linked in both C and C++ projects. It focuses on providing a clean and flexible API for sorting various data types with custom comparator functions.

- **C** and **C++** compatible
- Includes efficient implementations of classic algorithms
- Provides a flexible API with function pointers for custom sorting


## Supported Sorting Algorithms
This library includes the following sorting algorithms:
```c
//Bubble Sort
int bubbleSort(void *arr, size_t n, size_t elemSize, int (*compare)(void *, void *));

//Linear Sort
int linearSort(void *arr, size_t n, size_t elemSize, int (*compare)(void *, void *));

//Insertion Sort
int insertionSort(void *arr, size_t n, size_t elemSize, int (*compare)(void *, void *));

//Selection Sort
int selectionSort(void *arr, size_t n, size_t elemSize, int (*compare)(void *, void *));

//Shell Sort
int shellSort(void *arr, size_t n, size_t elemSize, int (*compare)(void *, void *));

//Quick Sort
void quickSort(void *arr, size_t left, size_t right, size_t elemSize, int (*compare)(void *, void *));

//Merge Sort
void mergeSort(void *arr, size_t left, size_t right, size_t elemSize, int (*compare)(void *, void *));

//Heap Sort
int heapSort(void *arr, size_t n, size_t elemSize, int (*compare)(void *, void *));

//Radix Sort (for integers)
int radixSort(int *arr, size_t n);

//Pancake Sort
int pancakeSort(void *arr, size_t n, size_t elemSize, int (*compare)(void *, void *));

//Gnome Sort
int gnomeSort(void *arr, size_t n, size_t elemSize, int (*compare)(void *, void *));

//Brick Sort
int brickSort(void *arr, size_t n, size_t elemSize, int (*compare)(void *, void *));

//Counting Sort (for positive integers)
int countingSort(int *arr, size_t n);

//Pigeonhole Sort (for integers)
int pigeonHoleSort(int *arr, size_t n);

//Stooge Sort
void stoogeSort(void *arr, size_t l, size_t r, size_t elemSize, int (*compare)(void *, void *));

//Tim Sort
int timSort(void *arr, size_t n, size_t elemSize, int (*compare)(void *, void *));

//Cocktail Shaker Sort
int cocktailShakerSort(void *arr, size_t n, size_t elemSize, int (*compare)(void *, void *));

//Binary Insertion Sort
int binaryInsertionSort(void *arr, size_t n, size_t elemSize, int (*compare)(void *, void *));

//Address Calculation Sort
int addressCalculationSort(void *arr, size_t n, size_t elemSize, int (*compare)(void *, void *));
```

## Installation

To use the library, simply clone the repository and include the header and source files in your project.

```sh
git clone https://github.com/iam-harshprajapat/Generic-Sorting-Algorithm-library-in-C-CPP.git'
```

Add the `.c` and `.h` files to your project and compile them along with your application.

## Usage

1. Define your custom comparator function.
2. Call any of the provided sorting functions, passing in the data, size, and your comparator.

Example:

```c
int comparator(void *a, void *b) {
    int x = *(int *)a;
    int y = *(int *)b;
    return x - y;
}

int main() {
    int arr[] = {5, 2, 9, 1, 5, 6};
    size_t n = sizeof(arr) / sizeof(arr[0]);

    bubbleSort(arr, n, sizeof(int), comparator);
    return 0;
}
```

## Development
Want to contribute? Feel free to fork the repository and submit a pull request with your improvements. All contributions are welcome!

# Contact
##### Gmail: s.harshprajapat@gmail.com
##### LinkedIn: https://www.linkedin.com/in/harsh-prajapat-510187241/

