#include <math.h>
#include <stdio.h>

float f(float x) { return ((x * sin(x)) + (x * x * x)); }

int main() {
  int n, i;
  float a, b, sum, h, res;
  printf("Enter the upper and lower limits: ");
  scanf("%f%f", &b, &a);
  printf("Enter the number of sub-problems: ");
  scanf("%d", &n);
  h = ((b - a) / n);
  sum = f(a) + f(b);
  for (i = 1; i < n; i++) {
    if (i % 2 == 0)
      sum += 2 * f(a + i * h);
    else
      sum += 4 * f(a + i * h);
  }
  res = (h * sum) / 3;
  printf("Value of the definite integral is: %f", res);
}