#include <stdio.h>

void print_number(int n) { printf(" %d", n % 10); }

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 1; i <= n; i++) {
    for (int k = 0; k < n - i; k++) {
      printf("  ");
    }
    for (int j = 1; j <= i; j++) {
      print_number(j);
    }
    for (int m = i - 1; m >= 1; m--) {
      print_number(m);
    }
    printf("\n");
  }
}