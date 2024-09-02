#ifndef DYNARRAY_H
#define DYNARRAY_H

#include <stddef.h>

typedef struct Array Array;

typedef int(*CompareFunc)(const void*, const void*);
typedef void (*PrintFunc)(const void*);

Array *createArray(int initialCapacity, size_t elementSize);
void freeArray(Array *arr);
int addElement(Array *arr, void *element);
void *getElement(Array *arr, int index);
int removeElement(Array *arr, int index);
int findElement(Array *arr, void *element, CompareFunc compare);
int insertElement(Array *arr, int index, void *element);
void clearArray(Array* arr);
void printArray(Array* arr, PrintFunc print);



#endif
