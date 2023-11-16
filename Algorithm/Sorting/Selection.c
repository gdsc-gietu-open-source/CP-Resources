#include <stdio.h>

/*
 By @AyushmanTripathy

  SELECTION SORT
  --------------
  Complexity: O(n^2)

  External Resources:
  1. wiki: https://en.wikipedia.org/wiki/Selection_sort

*/

// function for showing the output NOT part of the Algo.
void printArr(int * arr, int length) {
  printf("[");
  for (int i = 0; i < length; i++) printf(" %d ", arr[i]);
  printf("]\n");
}

// Selection Sort
// Array is divided into parts (sorted and unsorted)
void selectionSort(int * arr, int length) {
  int minIndex, minValue;

  // sorting the array one element at a time
  for (int i = 0; i < length; i++) {
    minIndex = i;

    // looking for the minimum value in the unsorted part
    for (int j = i + 1; j < length; j++) {
      if (arr[minIndex] > arr[j]) {
        minIndex = j;
      }
    }

    // adds min value into sorted part
    // swap is done O(n) times
    int tmp = arr[i];
    arr[i] = arr[minIndex];
    arr[minIndex] = tmp;
  }
}

int main() {
  int arr[] = { 3, 0, 2, 5 };
  int length = sizeof(arr) / sizeof(int);
  selectionSort(arr, length);
  printArr(arr, length);
}
