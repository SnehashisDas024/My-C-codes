#include <stdio.h>
#define size 10
float x[size], y[size];

int main() {
  int i, j;
  int a, n;
  float prod, sum = 0.0;
  printf("Enter the point of interpolation and the number of elements: ");
  scanf("%d%d", &a, &n);
  printf("Enter the values of x and y: ");
  for (i = 0; i < n; i++)
  {
    scanf("%f%f", &x[i], &y[i]);
  }
  for (i = 0; i < n; i++) {
    prod = 1.0;
    for (j = 0; j < n; j++) {
      if (i == j) continue;
      prod = prod * ((a - x[j]) / (x[i] - x[j]));
    }
    prod = prod * y[i];
    sum += prod;
  }
  printf("f(%d) = %f", a, sum);
}