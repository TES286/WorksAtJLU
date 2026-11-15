/*
题目编号：Exp03-Extend01，GJBook3-12-04

题目名称：自守数

题目描述：若一个正整数a满足条件 a^2 的尾数等于a，则称a为自守数，例如：

25^2=625 、76^2=5776 、9376^2=87909376 都是自守数。

编写程序，求小于等于n的所有自守数。



输入：从键盘随机输入一个正整数n（不超过10000000）。

输出：输出小于等于n的所有自守数，每个数之间以一个西文空格间隔。


样例1：

输入：10
输出：1 5 6
样例2：

输入：100
输出：1 5 6 25 76
*/

#include <stdio.h>

char check(long long n) {
  char s1[1000];
  char s2[1000];
  long long n2 = n * n;
  int len1 = sprintf(s1, "%lld", n);
  int len2 = sprintf(s2, "%lld", n2);
  for (int i = 1; i <= len1; i++) {
    if (s1[len1 - i] != s2[len2 - i]) {
      return 0;
    }
  }
  return 1;
}

int main() {
  long long n;
  scanf("%lld", &n);
  char is_first = 1;
  for (long long x = 1; x <= n; x++) {
    if (check(x)) {
      if (!is_first) {
        printf(" ");
      }
      printf("%lld", x);
      is_first = 0;
    }
  }
}