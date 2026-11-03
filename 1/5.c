#include <math.h>
#include <stdio.h>

int main() {
  float x, y, z, a, b, c, d;
  scanf("%f %f %f", &x, &y, &z);
  scanf("%f %f %f %f", &a, &b, &c, &d);
  printf("%.3f\n",
         fabs(a * x + b * y + c * z + d) / sqrt(a * a + b * b + c * c));
}