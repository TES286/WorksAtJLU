#include <stdio.h>

int main() {
  double x;
  int n;
  scanf("%lf %d", &x, &n);
  double hn = x;
  for (int i = 0; i < n; i++) {
    hn /= 2.0;
  }
  double total = x;
  double h = x;
  while (1) {
    h /= 2.0;
    if (h <= 1e-5) {
      break;
    }
    total += 2.0 * h;
  }
  printf("%.6f %.6f\n", hn, total);
}