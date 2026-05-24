#include <math.h>
#include <stdio.h>
float x;

float f(float a) { return ((a * a * a) - (3 * a) - 5); }

float df(float a) { return ((3 * a * a) - 3); }

int main() {
  float x, a, e;
  printf("Enter the guessed root: ");
  scanf("%f", &x);
  if (f(x) != 0) {
    printf("Enter the desired accuracy: ");
    scanf("%f", &e);
    do {
      a = x;
      x = x - (f(x) / df(x));
    } while (fabs(x - a) > e);
    printf("%f", x);
  }

}