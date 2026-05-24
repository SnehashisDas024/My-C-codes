#include <math.h>
#include <stdio.h>
float x;

float f(float a) {
  return ((a * a * a) - (3 * a) - 5);
}

int main() {
  float e, a, b;
  printf("Enter the lower and upper limit: ");
  scanf("%f%f", &a, &b);
  if (f(a) * f(b) < 0) {
    printf("Enter the desired accuracy: ");
    scanf("%f", &e);
    do {
      x = (a + b) / 2;
      if (f(x) * f(a) < 0)
        b = x;
      else
       a = x;
    } while(fabs(f(x)) > e);
    printf("%f", x);
  }
  else {
    printf("Invalid Interval");
  }
}