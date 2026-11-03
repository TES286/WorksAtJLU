#include <stdio.h>

typedef signed long long ull;

int main() {
  char* str;
  ull c1 = 0, c2 = 0, c3 = 0;
  int c;

  while ((c = getchar()) != '@' && c != EOF) {
    switch (c) {
      case '{':
        c1++;
        break;

      case '}':
        c1--;
        break;

      case '[':
        c2++;
        break;

      case ']':
        c2--;
        break;

      case '(':
        c3++;
        break;

      case ')':
        c3--;
        break;

      default:
        break;
    }
  }

  if (c1) {
    printf("{}");
  }

  if (c2) {
    printf("[]");
  }

  if (c3) {
    printf("()");
  }

  if (!(c1 || c2 || c3)) {
    printf("NULL");
  }

  printf("\n");
}