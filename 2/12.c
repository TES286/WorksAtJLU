/*
题目编号 ：Exp02-Enhance01，GJBook3-04-02

题目名称：计算 e^x

题目描述：请计算上述序列的前101项的和(截止到n取100)

GJBook3-04-02.jpg

输入：一个浮点数，对应x值。

输出：一个浮点数，即e^x的近似值，小数点后保留到第2位。

注：本题不允许使用math.h头文件和相关的pow和exp等函数。

e^x = \frac{x^0}{0!} + \frac{x^1}{1!} + \frac{x^2}{2!} + \frac{x^3}{3!} + \cdots + \frac{x^n}{n!}

样例1：

输入：0
输出：1.00
样例2：

输入：4.3
输出：73.70
*/

#include <stdio.h>

int main() {
  double x;
  scanf("%lf", &x);

  double sum = 1.0;
  double term = 1.0;
  for (int n = 1; n <= 100; n++) {
    term = term * x / n;
    sum += term;
  }

  printf("%.2f\n", sum);
}