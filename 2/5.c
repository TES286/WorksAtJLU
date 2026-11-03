#include <stdio.h>

int main() {
  float x;
  scanf("%f", &x);
  float y = 1 + 1 / (1 + 1 / (1 + 1 / (1 + 1 / (1 + 1 / x))));
  printf("%.3f", y);
}