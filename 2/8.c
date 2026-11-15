/*
题目编号 ：Exp02-Basic08，GJBook3-04-12

题目名称：三位Armstrong数

题目描述：编写程序，打印所有3位的Armstrong数，Armstrong数是指其值等于它本身每位数字立方和的数，如153就是一个Armstrong数。153=


输入：无
输出：打印所有3位的Armstrong数，每个Armstrong数间用一个西文空格间隔，最后一个数后无多余字符。



样例：无。详见输入输出说明
*/

#include <stdio.h>

int main() {
  int rst[1000];
  int cur = 0;
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      for (int k = 0; k < 10; k++) {
        if (100 * i + 10 * j + k < 100) {
          continue;
        }
        if (i * i * i + j * j * j + k * k * k == 100 * i + 10 * j + k) {
          rst[cur++] = i * 100 + 10 * j + k;
        }
      }
    }
  }

  for (int x = 0; x < cur; x++) {
    printf("%d", rst[x]);
    if (x != cur - 1) {
      printf(" ");
    }
  }
  printf("\n");
}