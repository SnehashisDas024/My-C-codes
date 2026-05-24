#include <stdio.h>
#define size 10
float x[size], y[size][size];

int main() {
  int n, i, j, pi;
  float h, u, sum = 0, p = 1;
  printf("Enter the number of terms: ");
  scanf("%d", &n);
  printf("Enter the values of x and y: ");
  for (i = 0; i < n; i++) {
    scanf("%f%f", &x[i], &y[i][0]);
  }
  // Constructing the difference table
  for (j = 1; j < n; j++) {
    for (i = 0; i < n - j; i++) {
      y[i][j] = y[i + 1][j - 1] - y[i][j - 1];
    }
  }
  for (i = 0; i < n; i++) {
    printf("%f\t", x[i]);
    for (j = 0; j < n - i; j++) {
      printf("%f\t", y[i][j]);
    }
    printf("\n");
  }

  printf("Enter the point of interpolation: ");
  scanf("%d", &pi);
  h = x[1] - x[0];
  u = (pi - x[0]) / h;
  sum = y[0][0];
  for (i = 1; i < n; i++) {
    p = p * ((u - i + 1) / i);
    sum = sum + p * y[0][i];
  }
  printf("sin %d = %f", pi, sum);
  return 0;
}