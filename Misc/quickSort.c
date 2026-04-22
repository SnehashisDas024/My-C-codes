#include <stdio.h>
#define size 50

void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int arr[], int start, int end) {
  int idx = start - 1, pivot = arr[end], j;
  for (j = start; j < end; j++) {
    if (arr[j] <= pivot) {
      idx++;
      swap(&arr[j], &arr[idx]);
    }
  }
  idx++;
  swap(&arr[end], &arr[idx]);
  return idx;
}

void quicksort(int arr[], int start, int end) {
  if (start < end) {
    int pivotIdx = partition(arr, start, end);
    quicksort(arr, start, pivotIdx - 1); // left
    quicksort(arr, pivotIdx + 1, end);   // right
  }
}

int main() {
  int arr[size], n, i;
  printf("Enter the number of elements: ");
  scanf("%d", &n);
  printf("Enter the elements:\n");
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  printf("Original array: ");
  for (i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  quicksort(arr, 0, n - 1);

  printf("Sorted array: ");
  for (i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  return -1;
}
