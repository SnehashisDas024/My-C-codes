#include <stdio.h>
#define size 10
int arr[size];

int bsearch_itr(int n, int key) {
  int low = 0, high = n - 1, mid;
  while (low <= high) {
    mid = (high + low) / 2;
    if (arr[mid] == key)  return mid;
    else if (arr[mid] < key)  low = mid + 1;
    else
     high = mid - 1;
  }
  return -1;
}

int bsearch_rec(int low, int high, int key) {
  if (low > high) {
    return -1;
  }
  int mid = low + (high - low) / 2;
  if (arr[mid] == key)
    return mid;
  else if (arr[mid] < key)
    return bsearch_rec(mid + 1, high, key);
  else
    return bsearch_rec(low, mid - 1, key);
}

int main() {
  int n, i, result, key;
  printf("Enter the number of elements: ");
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  printf("Enter the element to find: ");
  scanf("%d", &key);
  // result = bsearch_itr(n, key);
  result = bsearch_rec(0, n - 1, key);
  result = (result == -1)? printf("Not found") : printf("Found at index: %d", result);
}