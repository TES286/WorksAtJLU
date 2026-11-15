/*
题目编号：Exp05-Basic01，GJBook3-07-06

题目名称：字符串长度

题目描述：编写程序实现：使用自编函数int strlen(char *str)，求字符串str长度；并在主程序中调用。


输入：从键盘随机输入长度不超过256的字符串，字符串内可能包含若干空白字符。

输出：字符串的长度。


样例1：

输入：123  456
输出：8
说明：123和456中间有2个空格，所以字符串长度为8
样例2：

输入：A
输出：1
*/

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