/*
题目编号：Exp02-Basic02

题目名称：括号统计

题目描述：编程序，判断给定以字符‘@’结束的字符序列中‘(’与‘)’、‘[’与‘]’、‘{’与‘}’的个数是否相等。



输入：输入一串以字符‘@’结束的字符序列，其间可能含有若干空白字符。

输出：仅输出个数不相等的括号（按花括号、方括号、圆括号的顺序）；如果三种括号的个数都相等，输出单词NULL。


样例1：

输入：[A+(C+B)]*D@
输出：NULL
样例2：

输入：{a  +  b*c+(d/e-f]}@
输出：[]()
*/

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