#include <stdio.h>
#include <stdlib.h>

/*
   By @AyushmanTripathy

   HEAP SORT
   ---------
   Complexity: O(nlogn)

   External Resources:
   1. MIT OCW 6.006: https://youtu.be/B7hVxCmfPtM
   2. Wiki:          https://en.wikipedia.org/wiki/Heapsort
*/

// function for showing the output NOT part of the Algo.
void printArr(int * arr, int length) {
  printf("[");
  for (int i = 0; i < length; i++) printf(" %d ", arr[i]);
  printf("]\n");
}

// corrects one violation in heap, 
// assuming the left and right nodes are max heaps
void maxHeapify(int * arr, int length, int i) {
  int left = i * 2;
  int right = (i * 2) + 1;
  int largest = i;

  if (length > left && arr[left] < arr[largest])
    largest = left;
  if (length > right && arr[right] < arr[largest])
    largest = right;

  if (largest != i) {
    int tmp = arr[i];
    arr[i] = arr[largest];
    arr[largest] = tmp;
    maxHeapify(arr, length, largest);
  }
}

void heapSort(int * arr, int length) {
  // heap is created, heap created is indexed from 1.
  int * heap = (int *) malloc((length + 1) * sizeof(int));
  // copies over the integers from input arr
  for (int i = 0; i < length; i++) heap[i + 1] = arr[i];
  // maxHeapify called for all non leaf nodes
  for (int i = length / 2; i > 0; i--)
    maxHeapify(heap, length + 1, i);

  // elements are remove one by one
  // element to be removed is swapped with head and maxHeapify is called
  for(int i = 1; i < length; i++) {
    int tmp = heap[1];
    heap[1] = heap[length - i];
    arr[i - 1] = tmp;
    maxHeapify(heap, length - i, 1);
  }
}


int main() {
  // input array
  int arr[] = { 3, 2, 0 , 2, 4};
  int length = sizeof(arr) / sizeof(int);
  heapSort(arr, length);
  printArr(arr, length);
}
