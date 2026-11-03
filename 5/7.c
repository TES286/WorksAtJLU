#include <stdio.h>
#include <string.h>

int main() {
  char s[5][100];
  char c[100];
  int counter = 0;
  scanf("%s %s %s %s %s %s", s[0], s[1], s[2], s[3], s[4], c);
  for (int i = 0; i < 5; i++) {
    counter += strcmp(c, s[i]) == 0;
  }
  printf("%d", counter);
}