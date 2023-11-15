#include <stdio.h>
#include <stdlib.h>

/*
    by @AyushmanTripathy

    MERGE SORT
    ----------
    Complexity: O(nlogn)

    External Resources:
    1. wiki:  https://en.wikipedia.org/wiki/Merge_sort

*/

// function for showing the output NOT part of the Algo.
void printArr(int * arr, int length) {
  printf("[");
  for (int i = 0; i < length; i++) printf(" %d ", arr[i]);
  printf("]\n");
}

// helper function for making the code cleaner
int append(int * arr, int index, int value) {
  arr[index] = value;
  return index + 1;
}

int *mergeSort(int * arr, int length) {
  // base case: array of length one is always sorted
  if (length == 1) return arr;
  
  int divider = length / 2;
  int * left = mergeSort(arr, divider);
  int * right = mergeSort(arr + divider, length - divider);

  int new_arr[length];
  int index = 0, leftIndex = 0, rightIndex = 0;

  // merging left and right
  while(1) {
    if (left[leftIndex] < right[rightIndex]) {
      index = append(new_arr, index, left[leftIndex]);
      leftIndex++;
    } else {
      index = append(new_arr, index, right[rightIndex]);
      rightIndex++;
    }
    if (leftIndex == divider || rightIndex == length - divider) break; 
  }

  // adding the leftover
  if (leftIndex != divider) {
    for (int i = leftIndex; i < divider; i++) 
      index = append(new_arr, index, left[i]);
  }
  else if (rightIndex != length - divider) {
    for (int i = rightIndex; i < length - divider; i++) 
      index = append(new_arr, index, right[i]);
  }

  // copy the data;
  for(int i = 0; i < length; i++) arr[i] = new_arr[i];
  return arr; 
}

int main() {
  int arr[] = { 3, 0, 2, 1, 5 };
  int length = sizeof(arr) / sizeof(int);
  mergeSort(arr, length);
  printArr(arr, length);
  return 0;
}
