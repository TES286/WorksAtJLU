/*
题目编号：Exp05-Enhanc02，freshman-1031

题目名称：合法标识符

题目描述：

已知C语言中合法标识的定义是，以_或字母开始，并由_、数字、字母构成的连续字符串。编写程序判断给定的字符串是否是合法C语言标识符。


输入：输入第一行给出正整数 N（≤10^2）是输入的字符串个数。随后 N 行，每行给出1个任意长度的字符串（可能含有空白字符，长度不超过256）。

输出：

输出第一行以Valid:X 格式给出合法标识符个数 X，第二行以Invalid:Y 格式给出非法标识符个数 Y，无多余字符，冒号为西文冒号。


样例：

输入：
2
1242345567788990
abcdedffesfsgfef
输出：
Valid:1
Invalid:1
*/

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
