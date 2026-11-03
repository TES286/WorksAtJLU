#include <stdio.h>

int strlen(char* str) {
  int p = 0;
  while (str[p] != '\0') p++;
  return p;
}

int main() {
  char str[1000] = {0};
  fread(&str, sizeof(char), 999, stdin);
  printf("%d", strlen(str));
}