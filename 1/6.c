#include <stdio.h>

int main() {
  int t;
  scanf("%d", &t);
  t %= 24 * 60 * 60;
  printf("%02d:%02d:%02d\n", t / 3600, t % 3600 / 60, t % 60);
}