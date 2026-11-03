#include <stdio.h>

int main() {
  double x;
  scanf("%lf", &x);

  double sum = 1.0;
  double term = 1.0;
  for (int n = 1; n <= 100; n++) {
    term = term * x / n;
    sum += term;
  }

  printf("%.2f\n", sum);
}