#include <stdio.h>

int main() {
  unsigned long long rst = 0;
  while (1) {
    rst += 7;
    if (rst % 2 == 1 && rst % 3 == 2 && rst % 5 == 4) {
      printf("%lld\n", rst);
      break;
    }
  }
}