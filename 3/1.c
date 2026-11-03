#include <stdio.h>

long long b(long long x) {
  long long rst = x;
  for (long long i = x - 1; i > 0; i--) {
    rst *= i;
  }
  return rst;
}

long long f(long long m, long long n) {
  if (m <= 0 || n <= 0) {
    return -1;
  }
  if (m < n) {
    return 0;
  }
  if (m == n) {
    return 1;
  }
  if (m > n) {
    return b(m) / (b(n) * b(m - n));
  }
  return -1;
}

int main() {
  long long m, n;
  scanf("%lld %lld", &m, &n);
  printf("%lld", f(m, n));
  return 0;
}