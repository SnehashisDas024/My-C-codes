#include <stdio.h>
#define size 10
int arr[size];
void merge(int low, int high, int mid) {
  int i = low, j = mid + 1, k = 0;
  int b[size];
  while (i <= mid && j <= high) {
    if (arr[i] <= arr[j]) {
      b[k++] = arr[i++];
    } else {
      b[k++] = arr[j++];
    }
  }
  while (i <= mid)
    b[k++] = arr[i++];
  while (j <= high)
    b[k++] = arr[j++];
  for (i = 0; i < k; i++) {
    arr[low + i] = b[i];
  }
}

void mergesort(int low, int high) {
  if (low < high) {
    int mid = (low + high) / 2;
    mergesort(low, mid);
    mergesort(mid + 1, high);
    merge(low, high, mid);
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
  mergesort(0, n - 1);
  for (i = 0; i < n; i++) {
    printf("%d\t", arr[i]);
  }
  return 0;
}
