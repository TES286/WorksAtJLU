#include <stdio.h>

int main() {
  int j, a;
  scanf("%d %d", &j, &a);
  if (j == 1) {
    if (a <= 65) {
      printf("NULL");
    } else if (a <= 70) {
      printf("50");
    } else {
      printf("70");
    }
  } else if (j == 2) {
    if (a <= 60) {
      printf("NULL");
    } else if (a <= 65) {
      printf("45");
    } else {
      printf("70");
    }
  }
}