#include <stdio.h>

unsigned char alphabet[0xFF + 1];

void init() {
  for (int i = 0; i <= 0xFF; i++) alphabet[i] = i;
  for (int i = 'A'; i <= 'Z'; i++) alphabet[i] = 'Z' - (i - 'A');
}

int main() {
  init();
  int ch;
  while ((ch = getchar()) != '\0' && ch != '\n' && ch != '\r' && ch != EOF) {
    putchar(alphabet[ch]);
  }
}
