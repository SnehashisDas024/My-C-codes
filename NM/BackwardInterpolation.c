#include <stdio.h>
#define size 10
float x[size], y[size][size];

int main()
{
  int n, i, j;
  float h, u, pi, sum = 0, p = 1;
  printf("Enter the number of terms: ");
  scanf("%d", &n);
  printf("Enter the values of x and y: ");
  for (i = 0; i < n; i++)
  {
    scanf("%f%f", &x[i], &y[i][0]);
  }
  // Constructing the difference table
  for (j = 1; j < n; j++)
  {
    for (i = j; i < n; i++)
    {
      y[i][j] = y[i][j - 1] - y[i - 1][j - 1];
    }
  }
  for (i = 0; i < n; i++)
  {
    printf("%f\t", x[i]);
    for (j = 0; j <= i; j++)
    {
      printf("%f\t", y[i][j]);
    }
    printf("\n");
  }

  printf("Enter the point of interpolation: ");
  scanf("%f", &pi);
  h = x[1] - x[0];
  u = (pi - x[n - 1]) / h;
  sum = y[n - 1][0];
  for (i = 1; i < n; i++)
  {
    p = p * ((u + i - 1) / i);
    sum = sum + p * y[n - 1][i];
  }
  printf("y(%f) = %f", pi, sum);
  return 0;
}