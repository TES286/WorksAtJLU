#include <stdio.h>

void count(char* str, int* upper, int* lower, int* space, int* num,
           int* other) {
  unsigned long long i = 0;
  char c;
  while ((c = str[i]) != '\0') {
    if (c >= 'A' && c <= 'Z') {
      (*upper)++;
    } else if (c >= 'a' && c <= 'z') {
      (*lower)++;
    } else if (c == ' ') {
      (*space)++;
    } else if (c >= '0' && c <= '9') {
      (*num)++;
    } else {
      (*other)++;
    }
    i++;
  }
}

int main() {
  char buf[1000] = {0};
  fread(buf, sizeof(char), 1000, stdin);
  int upper=0, lower=0, space=0, num=0, other=0;
  count(buf, &upper, &lower, &space, &num, &other);
  printf("%d %d %d %d %d", upper, lower, space, num, other);
}
