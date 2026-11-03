#include <stdio.h>

int main() {
  int a;
  int c[5];
  scanf("%d %d %d %d %d %d", &a, &c[0], &c[1], &c[2], &c[3], &c[4]);
  int sum = 0;
  for (int i = 0; i < 5; i++) {
    if (c[i] % a == 0) {
      sum += c[i];
    }
  }
  printf("%d\n", sum);
}