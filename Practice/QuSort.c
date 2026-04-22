#include <stdio.h>
#define size 10
int arr[size];

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int low, int high) {
  int i = low + 1, j = high;
  int pivot = arr[low];
  while (i <= j) {
    while (arr[i] < pivot)
      i++;
    while (arr[j] > pivot)
      j--;
    if (i < j)
      swap(&arr[i], &arr[j]);
  }
  swap(&arr[j], &arr[low]);
  return j;
}

void quicksort(int low, int high) {
  if (low < high) {
    int pivot = partition(low, high);
    quicksort(low, pivot - 1);
    quicksort(pivot + 1, high);
  }
}
int main() {
  int n, i;
  printf("Enter the number of elements: ");
  scanf("%d", &n);
  printf("Enter the elements: ");
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  quicksort(0, n - 1);
  for (i = 0; i < n; i++) {
    printf("%d\t", arr[i]);
  }
  return 0;
}
