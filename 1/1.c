#include <math.h>
#include <stdio.h>

int main() {
  float a, x;
  scanf("%f %f", &a, &x);
  float y = sin(x) / (a * x) + fabs(cos(3.1415926 / 2 * x));
  printf("%.3f\n", y);
}