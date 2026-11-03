#include <stdio.h>

int is_valid(char* str) {
  int is_first = 1;
  while (*str != '\0' && *str != '\n' && *str != '\r') {
    if (is_first) {
      is_first = 0;
      if (*str == '_' || (*str >= 'a' && *str <= 'z') ||
          (*str >= 'A' && *str <= 'Z')) {
        str++;
        continue;
      } else {
        return 0;
      }
    } else {
      if (*str == '_' || (*str >= 'a' && *str <= 'z') ||
          (*str >= 'A' && *str <= 'Z') || (*str >= '0' && *str <= '9')) {
        str++;
        continue;
      } else {
        return 0;
      }
    }
  }
  return !is_first;
}

int main() {
  int n;
  scanf("%d", &n);
  int valid = 0, invalid = 0;
  int ch;
  while ((ch = getchar()) != '\n' && ch != EOF);
  char str[1000] = {0};
  while (n--) {
    fgets(str, 1000, stdin);
    if (is_valid(str)) {
      valid++;
    } else {
      invalid++;
    }
  }
  printf("Valid:%d\n", valid);
  printf("Invalid:%d", invalid);
}
