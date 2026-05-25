#include <stdio.h>
#define size 10
float a[size][size];
float x[size];
int main() {
  int n, i, j, k;
  float m, sum;
  printf("Enter the no. of equations: ");
  scanf("%d", &n);
  printf("Enter the augmented matrix: ");

  for(i = 0; i < n; i++) {
    for (j = 0; j <= n; j++) {
      scanf("%f", &a[i][j]);
    }
  }

  // Rank matrix
  for (k = 0; k < n - 1; k++) {
    for (i = k + 1; i < n; i++) {
      m = a[i][k] / a[k][k];
      for (j = k; j <= n; j++) {
        a[i][j] = a[i][j] - (m * a[k][j]);
      }
    }
  }

  for (i = 0; i < n; i++) {
    printf("\n");
    for (j = 0; j <= n; j++) {
      printf("%.3f\t", a[i][j]);
    }
  }

  for (i = n - 1; i >= 0; i--) {
    sum = 0;
    for (j = i + 1; j < n; j++) {
      sum = sum + (a[i][j] * x[j]);
    }
    x[i] = (a[i][n] - sum) / a[i][i];
  }
  printf("\n");
  for(i = 0; i < n; i++) { printf("%.3f\t", x[i]); }
  return 0;
}