#include <stdio.h>

unsigned long long fib(unsigned int n) {
  unsigned long long a = 0, b = 1;

  unsigned long long tmp;

  for (; n; n--) {
    tmp = b;
    b += a;
    a = tmp;
  }

  return b;
}

int main() {
  unsigned int n;

  scanf("%d", &n);
  printf("%lld\n", fib(n));
}
