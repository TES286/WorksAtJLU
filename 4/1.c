#include <stdio.h>

char stack[1000];
int p = 0;

int main() {
  char ch;
  while ((ch = getchar()) != '@') {
    switch (ch) {
      case '(':
        stack[p++] = ch;
        break;
      case ')':
        if (p > 0 && stack[p - 1] == '(') {
          p--;
        } else {
          printf("NO");
          return 0;
        }
        break;

      case '[':
        stack[p++] = ch;
        break;
      case ']':
        if (p > 0 && stack[p - 1] == '[') {
          p--;
        } else {
          printf("NO");
          return 0;
        }
        break;
      case '{':
        stack[p++] = ch;
        break;
      case '}':
        if (p > 0 && stack[p - 1] == '{') {
          p--;
        } else {
          printf("NO");
          return 0;
        }
        break;
    }
  }
  if (p == 0) {
    printf("YES");
  }
}