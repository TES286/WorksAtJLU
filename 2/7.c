#include <stdio.h>
#include <string.h>

typedef unsigned char bool;

int main() {
  unsigned long long data;
  scanf("%lld", &data);

  bool is3 = data % 3 == 0;
  bool is5 = data % 5 == 0;
  bool is7 = data % 7 == 0;

  char str[100] = "";
  if (is3) {
    strcat(str, "3,");
  }
  if (is5) {
    strcat(str, "5,");
  }
  if (is7) {
    strcat(str, "7,");
  }
  if (!(is3 || is5 || is7)) {
    strcat(str, "NULL,");
  }

  size_t len = strlen(str);
  if (len > 0) {
    str[len - 1] = '\0';
  }
  printf("%s", str);
}
