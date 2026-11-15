/*
题目编号 ：Exp02-Basic06，GJBook3-04-09

题目名称：符合条件自然数

题目描述：编写程序，打印所有小于正整数data且可被11整除的自然数。



输入：从键盘输入一个正整数data

输出：输出所有小于data且可被11整除的自然数，数与数之间以一个空格做间隔，最后一个数后无多余字符。


样例1：

输入：50
输出：0 11 22 33 44
样例2：

输入：80
输出：0 11 22 33 44 55 66 77
*/

#include <stdio.h>

int main() {
  unsigned long long data;
  scanf("%lld", &data);
  for (unsigned long long i = 0; i < data; i++) {
    if (i % 11 == 0) {
      printf("%lld ", i);
    }
  }
  printf("\n");
}