#include <stdio.h>
int x[10], y[10];

int main() {
  int n, i, a, b;
  printf("Enter the number of terms: ");
  scanf("%d", &n);
  printf("Enter the upper and lower for x and then the value of y: ");
  for (i = 0; i < n; i++) {
    scanf("%d%d%d", &a, &b, &y[i]);
    x[i] = (b - a) / 2;
  }
}