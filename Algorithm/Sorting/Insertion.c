#include <stdio.h>

/*
 By @AyushmanTripathy

  INSERTION SORT
  --------------
  Complexity: O(n^2)

  External Resources:
  1. wiki: https://en.wikipedia.org/wiki/Insertion_sort

*/

// function for showing the output NOT part of the Algo.
void printArr(int * arr, int length) {
  printf("[");
  for (int i = 0; i < length; i++) printf(" %d ", arr[i]);
  printf("]\n");
}

// Insertion Sort
void insertion_sort(int * arr, int length) {
  // iterate through all indices
  for (int i = 0; i < length; i++) {
    // swap until we find ith index's place
    // here we use the fact that [0, i - 1] indices are sorted
    for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--) {
      // O(n^2) swaps in worst case
      int tmp = arr[j - 1];
      arr[j - 1] = arr[j];
      arr[j] = tmp;
    }
  }
}

int main() {
  int arr[] = { 3, 0, 2, 5 };
  int length = sizeof(arr) / sizeof(int);
  insertion_sort(arr, length);
  printArr(arr, length);
  return 0;
}
