#include <stdio.h>

int main() {
  double result = 2.0;
  unsigned int n;
  double tmp1, tmp2;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    tmp1 = 2 * i;
    tmp2 = (tmp1 / (tmp1 - 1)) * (tmp1 / (tmp1 + 1));
    result *= tmp2;
  }
  printf("%.10f", result);
}