#include <stdio.h>

char check(long long n) {
  char s1[1000];
  char s2[1000];
  long long n2 = n * n;
  int len1 = sprintf(s1, "%lld", n);
  int len2 = sprintf(s2, "%lld", n2);
  for (int i = 1; i <= len1; i++) {
    if (s1[len1 - i] != s2[len2 - i]) {
      return 0;
    }
  }
  return 1;
}

int main() {
  long long n;
  scanf("%lld", &n);
  char is_first = 1;
  for (long long x = 1; x <= n; x++) {
    if (check(x)) {
      if (!is_first) {
        printf(" ");
      }
      printf("%lld", x);
      is_first = 0;
    }
  }
}