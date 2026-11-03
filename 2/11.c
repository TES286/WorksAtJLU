#include <stdio.h>

double p(int n, double x) {
  if (n == 0) {
    return 1.0;
  } else if (n == 1) {
    return x;
  } else {
    return (2 * n - 1) * x * p(n - 1, x) / n - (n - 1) * p(n - 2, x) / n;
  }
}

int main() {
  double x;
  int n;
  scanf("%lf %d", &x, &n);
  printf("%.2f\n", p(n, x));
}