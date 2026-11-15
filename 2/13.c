/*
题目编号 ：Exp02-Enhance02，GJBook3-04-0102

题目名称：公式累乘

题目描述：用如下的展开式计算当n为某给定值时，圆周率π的值。

GJBook3-04-0102.jpg



输入：一个正整数n (n<=100000)

输出：一个浮点数，保留小数点后10位。

\frac{\pi}{2} = \frac{2}{1} \cdot \frac{2}{3} \cdot \frac{4}{3} \cdot \frac{4}{5} \cdot \frac{6}{5} \cdot \frac{6}{7} \cdots \cdot \frac{2n}{2n-1} \cdot \frac{2n}{2n+1}

样例1：

输入：1000
输出：3.1408077460
样例2：

输入：10000
输出：3.1415141187
*/

#include <stdio.h>

int main() {
  double result = 2.0;
  unsigned int n;
  double tmp1, tmp2;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    tmp1 = 2 * i;
    tmp2 = (tmp1 / (tmp1 - 1)) * (tmp1 / (tmp1 + 1));
    result *= tmp2;
  }
  printf("%.10f", result);
}