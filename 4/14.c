#include <stdio.h>

int main() {
  int x, n;
  scanf("%d %d", &x, &n);
  if (x == 0) {
    putchar('0');
  }
  char str[1024];
  int i = 0;
  while (x) {
    str[i++] = x % n + '0';
    x /= n;
  }
  for (int j = i - 1; j >= 0; j--) {
    putchar(str[j]);
  }
}