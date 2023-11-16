#include <stdio.h>  
#include <stdlib.h>

/*
 By @AyushmanTripathy

  RADIX SORT
  --------------
  NOTE: only for positive numbers
  Complexity: O(n)

  External Resources:
  1. wiki: https://geeksforgeeks.org/radix-sort/
  2. wiki: https://www.geeksforgeeks.org/counting-sort/
*/

// function for showing the output NOT part of the Algo.
void printArr(int * arr, int length) {
  printf("[");
  for (int i = 0; i < length; i++) printf(" %d ", arr[i]);
  printf("]\n");
}

// plz refer to secount external resources
// Counting sort is linear sort algorithim,
// we use it here to sort a single decimal place.
void counting_sort(int * arr, int len, int place) {
  int frequency[10] = {0};
  int * output = (int *) malloc(sizeof(int) * (len + 1));  
  
  // calculating frequency of digits. 
  for (int i = 0; i < len; i++) frequency[(arr[i] / place) % 10]++;

  // finding cumulative sum of frequency
  for (int i = 1; i < 10; i++) frequency[i] += frequency[i - 1];  
  
  // we use cumulative frequency to get ith
  // element starting from the end.
  // refer to resource for better explanation
  for (int i = len - 1; i >= 0; i--) {  
    output[frequency[(arr[i] / place) % 10] - 1] = arr[i];
    frequency[(arr[i] / place) % 10]--;
  }

  // copying over the output to original array
  for (int i = 0; i < len; i++) arr[i] = output[i];
}

// Radix sort is like superset of Counting sort,
// which is called for each decimal place.
void radix_sort(int * arr, int len) {
  // find the max element
  int max = 0;
  for(int i = 0; i < len; i++) {
     if (arr[i] > max) max = arr[i];
  }

  // calling counting_sort for each place
  for (int place = 1; max / place > 0; place *= 10)
    counting_sort(arr, len, place);
}

int main() {  
  int a[] = { 309, 100, 999, 840 };  
  int n = sizeof(a) / sizeof(int);  
  radix_sort(a, n);  
  printArr(a, n);  
}  
