#include <stdio.h>
float f(float x, float y) {
  return 3 * x + y * y;
}

int main() {
  float x0, y0, h, xn;
  printf("Enter the vslues of x0, y0, h, xn: ");
  scanf("%f%f%f%f", &x0, &y0, &h, &xn);
  do {
    y0 += h * f(x0, y0);
    x0 += h;
  } while(x0 <= xn - h);
  printf("%f", y0);
}