#include <stdio.h>

int within(int x[10000], int n, int len) {
  for (int i = 0; i < len; i++) {
    if (x[i] == n) {
      return 1;
    }
  }
  return 0;
}

int main() {
  int n, t;
  scanf("%d", &n);
  int x[10000];
  for (int i = 0; i < n*n; i++) {
    scanf("%d", &t);
    if (within(x, t, i)) {
      printf("YES");
      return 0;
    }
    x[i] = t;
  }
  printf("NO");
}