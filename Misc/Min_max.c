#include <stdio.h>

int max, min;
void max_min(int arr[], int low, int up) {
  int mid, max1, min1;
  if (low == up) {
    max = min = arr[low];
  } else if (low == up - 1) {
    if (arr[low] > arr[up]) {
      max = arr[low];
      min = arr[up];
    } else {
      max = arr[up];
      min = arr[low];
    }
  } else {
    mid = (low + up) / 2;
    max_min(arr, low, mid);
    max1 = max;
    min1 = min;
    max_min(arr, mid + 1, up);
    if (max1 > max)
      max = max1;
    if (min1 < min)
      min = min1;
  }
}
int main() {
  int n, i;
  printf("Enter number of elements: ");
  scanf("%d", &n);
  int arr[n];
  printf("Enter %d elements: ", n);
  for (i = 0; i < n; i++)
    scanf("%d", &arr[i]);
  max_min(arr, 0, n - 1);
  printf("Maximum = %d\n", max);
  printf("Minimum = %d\n", min);
  return 0;
}
