#include "dynarray.h"
#include <stdio.h>

void printInt(const void *element) { printf("%d", *(int *)element); }

void printDouble(const void *element) { printf("%.2f", *(double *)element); }

int compareInt(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

int main(void) {
  int size = 5;
  Array *arr = createArray(size, sizeof(int));

  int num[] = {12, 24, 36, 48, 69};

  for (int i = 0; i < size; i++) {
    addElement(arr, &num[i]);
  }

  printf("Array contents: ");
  printArray(arr, printInt);

  return 0;
}
