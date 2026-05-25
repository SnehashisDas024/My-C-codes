#include <stdio.h>
float f(float x, float y) { return 3 * x + y * y; }

int main() {
  float x0, y0, h, xn, k1, k2, k3, k4, k;
  printf("Enter the values of x0, y0, h, xn: ");
  scanf("%f%f%f%f", &x0, &y0, &h, &xn);
  do {
    k1 = h * f(x0, y0);
    k2 = h * f(x0 + h / 2, y0 + k1 / 2);
    k3 = h * f(x0 + h / 2, y0 + k2 / 2);
    k4 = h * f(x0 + h, y0 + k3);
    k = (k1 + 2 * k2 + 2 * k3 + k4) / 6;
    y0 += k;
    x0 += h;
  } while (x0 <= xn - h);
  printf("%f", y0);
}