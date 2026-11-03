#include <stdio.h>

char* str_delete(char* s, int v, int w) {
  v--;
  int i = 0;
  while (s[v + w + i] != '\0') {
    s[v + i] = s[v + w + i];
    i++;
  }
  s[v + i] = '\0';
  return s;
}

int main() {
  char str[1024] = {0};
  int v, w;
  scanf("%d %d", &v, &w);
  int ch;
  while ((ch = getchar()) != '\n' && ch != EOF);
  fgets(str, sizeof(str), stdin);
  puts(str_delete(str, v, w));
}