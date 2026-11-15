/*
题目编号：Exp04-Basic01,GJBook3例-06-13

题目名称：括号匹配

题目描述：编写程序，从终端读入以‘@’为结束符的字符序列（序列总长度不超过1000个字符），检查该字符序列中的 ( 与 )、 [ 与 ] 、{ 与 } 是否匹配（个数相等且位置不相交）。



输入：包含一串以‘@’为结束符的字符串，其间可能包含空白或其它非括号字符。

输出：如果字符串中三类括号匹配，则输出YES；否则输出NO。


样例1:

输入：

{a,a}b{c[cc]c}  {a(bb[cc]dd)a}@
输出：
YES
样例2:

输入：
{a,a}b{c[cc]c] {a(bb[cc]dd)a}@
输出：
NO
*/

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