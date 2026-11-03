#include <stdio.h>

int main() {
  unsigned long long data;
  scanf("%lld", &data);
  for (unsigned long long i = 0; i < data; i++) {
    if (i % 11 == 0) {
      printf("%lld ", i);
    }
  }
  printf("\n");
}