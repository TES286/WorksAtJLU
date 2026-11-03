#include <stdio.h>

int main() {
  int _, count0 = 0;
  int n;
  scanf("%d", &_);
  int is_first = 1;
  while (scanf("%d", &n) != -1) {
    if (n != 0) {
      if (!is_first) {
        printf(" ");
      }
      is_first = 0;
      printf("%d", n);
    } else
      count0++;
  }
  for (int _ = 0; _ < count0; _++) {
    if (!is_first) {
      printf(" ");
    }
    is_first = 0;
    printf("0");
  }
}