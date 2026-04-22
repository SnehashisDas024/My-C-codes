#include <stdio.h>
#define size 10
int arr[size];

int bsearchiter(int n, int key) {
  int low = 0, high = n - 1, mid;
  while (low <= high) {
    mid = (low + high) / 2;
    if (arr[mid] == key)
      return mid;
    else if (arr[mid] < key)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return -1;
}

int main() {
  int n, i, key;
  printf("Enter the number of elements: ");
  scanf("%d", &n);
  printf("Enter the elements: ");
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  printf("Enter the target element: ");
  scanf("%d", &key);
  if (bsearchiter(n, key) == -1) {
    printf("Not found");
  } else {
    printf("Found");
  }
}
