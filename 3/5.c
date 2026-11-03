#include <stdio.h>

char is_prime(unsigned long long x) {
  for (unsigned long long i = 2; i < x / 2 + 1; i++) {
    if (x % i == 0) {
      return 0;
    }
  }
  return 1;
}

int main() {
  unsigned long long n;
  scanf("%lld", &n);
  if (is_prime(n)) {
    printf("Y");
  } else {
    printf("N");
  }
}
