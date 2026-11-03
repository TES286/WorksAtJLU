#include <stdio.h>

int within(int x[1000], int n, int len) {
  for (int i = 0; i < len; i++) {
    if (x[i] == n) {
      return 1;
    }
  }
  return 0;
}

int main() {
  int x[1000];
  int n, k, j = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &k);
    if (within(x, k, j)) {
      continue;
    }
    x[j++] = k;
  }
  int is_first = 1;
  for (int m = 0; m < j; m++) {
    if (!is_first) {
      printf(" ");
    }
    printf("%d", x[m]);
    is_first = 0;
  }
}