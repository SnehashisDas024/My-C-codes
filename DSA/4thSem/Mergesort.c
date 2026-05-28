#include <stdio.h>
#define size 10
int arr[size], brr[size];

void merge(int low, int mid, int high) {
  int i = low, j = mid + 1, k = 0;
  while(i <= mid && j <= high) {
    if (arr[i] <= arr[j]) {
      brr[k++] = arr[i++];
    }
    else {
      brr[k++] = arr[j++];
    }
  }
  while (i <= mid) {
    brr[k++] = arr[i++];
  }
  while (j <= high) {
    brr[k++] = arr[j++];
  }
  for (i = 0; i < k; i++) {
    arr[i + low] = brr[i];
  }
}

void mergesort(int low, int high) {
  if (low < high) {
    int mid = (low + high) / 2;
    mergesort(low, mid);
    mergesort(mid + 1, high);
    merge(low, mid, high);
  }
}

int main() {
  int n, i, result;
  printf("Enter the number of elements: ");
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  mergesort(0, n - 1);
  for (i = 0; i < n; i++) {
    printf("%d\t", arr[i]);
  }
}