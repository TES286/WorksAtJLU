#include <stdio.h>

int main() {
  int rst[1000];
  int cur = 0;
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      for (int k = 0; k < 10; k++) {
        if (100 * i + 10 * j + k < 100) {
          continue;
        }
        if (i * i * i + j * j * j + k * k * k == 100 * i + 10 * j + k) {
          rst[cur++] = i * 100 + 10 * j + k;
        }
      }
    }
  }

  for (int x = 0; x < cur; x++) {
    printf("%d", rst[x]);
    if (x != cur - 1) {
      printf(" ");
    }
  }
  printf("\n");
}