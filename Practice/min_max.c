#include <stdio.h>
#define size 10
int arr[size];
int min, max;

void min_max(int low, int high) {
  int mid, max1, min1;
  if (low == high)
    min = max = arr[low];
  else if (high == low + 1) {
    if (arr[low] > arr[high]) {
      max = arr[low];
      min = arr[high];
    } else {
      max = arr[high];
      min = arr[low];
    }
  } else {
    mid = (low + high) / 2;
    min_max(low, mid);
    max1 = max;
    min1 = min;
    min_max(mid + 1, high);
    if (min > min1)
      min = min1;
    if (max < max1)
      max = max1;
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
  // quicksort(0, n - 1);
  // for (i = 0; i < n; i++) {
  //   printf("%d\t", arr[i]);
  // }
  min_max(0, n - 1);
  printf("max = %d\tmin = %d\n", max, min);
  return 0;
}
