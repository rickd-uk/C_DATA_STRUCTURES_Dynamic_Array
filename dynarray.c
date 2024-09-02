#include "dynarray.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Array {
  void **data; // array of void pointers
  int size;
  int capacity;
  size_t elementSize; // size of each element in bytes
};

Array *createArray(int initialCapacity, size_t elementSize) {
  Array *arr = malloc(sizeof(Array));
  if (arr == NULL)
    return NULL; // memory allocation failed

  arr->data = malloc(initialCapacity * sizeof(void *));
  if (arr->data == NULL) {
    free(arr);
    return NULL; // memory allocation failed
  }
  arr->size = 0;
  arr->capacity = initialCapacity;
  arr->elementSize = elementSize;
  return arr;
}

int addElement(Array *arr, void *element) {
  if (arr->size >= arr->capacity) {
    // array is full
    int newCapacity = arr->capacity * 2;
    void **newData = realloc(arr->data, newCapacity * sizeof(void *));
    if (newData == NULL)
      return 0;
    arr->data = newData;
    arr->capacity = newCapacity;
  }
  arr->data[arr->size] = malloc(arr->elementSize);
  if (arr->data[arr->size] == NULL)
    return 0;

  memcpy(arr->data[arr->size], element, arr->elementSize);
  arr->size++;
  return 1;
}

int insertElement(Array *arr, int index, void *element) {
  if (index < 0 || index > arr->size) {
    printf("Index out of bounds");
    return 0;
  }
  if (arr->size >= arr->capacity) {
    int newCapacity = arr->capacity * 2;
    void **newData = realloc(arr->data, newCapacity * sizeof(void *));
    if (newData == NULL) {
      return 0;
    }
    arr->data = newData;
    arr->capacity = newCapacity;
  }
  for (int i = arr->size; i > index; i--) {
    arr->data[i] = arr->data[i - 1];
  }
  arr->data[index] = malloc(arr->elementSize);
  if (arr->data[index] == NULL)
    return 0;

  memcpy(arr->data[index], element, arr->elementSize);
  arr->size++;
  return 1;
}

int removeElement(Array *arr, int index) {
  if (index < 0 || index >= arr->size) {
    printf("Index out of bounds");
    return 0;
  }
  free(arr->data[index]);

  for (int i = index; i < arr->size - 1; i++) {
    arr->data[i] = arr->data[i + 1];
  }
  arr->size--;
  return 1;
}

void *getElement(Array *arr, int index) {
  if (index < 0 || index >= arr->size) {
    printf("Index out of bounds");
    return NULL;
  }
  return arr->data[index];
}

void printArray(Array *arr, PrintFunc print) {
  printf("Array: ");
  for (int i = 0; i < arr->size; i++) {
    print(arr->data[i]);
    if (i < arr->size - 1) {
      printf(", ");
    }
  }
  printf("\n");
}

void clearArray(Array *arr) {
  for (int i = 0; i < arr->size; i++) {
    free(arr->data[i]);
  }
  arr->size = 0;
}

int findElement(Array *arr, void *element, CompareFunc compare) {
  for (int i = 0; i < arr->size; i++) {
    if (compare(arr->data[i], element) == 0) {
      return i;
    }
  }
  return -1;
}

void freeArray(Array *arr) {
  clearArray(arr);
  free(arr->data);
  free(arr);
}

void reverseArray(Array *arr) {
  for (int i = 0; i < arr->size / 2; i++) {
    void *temp = arr->data[i];
    arr->data[i] = arr->data[arr->size - 1 - i];
    arr->data[arr->size - 1 - i] = temp;
  }
}


int getSize(Array *arr) { return arr->size; }

int getCapacity(Array *arr) { return arr->capacity; }
