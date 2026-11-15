/*
题目编号 ：Exp02-Basic11，GJBook3-04-03

题目名称：勒让德多项式

题目描述：

编一个程序，输入x、n，计算勒让德(Legendre)多项式的第 n 项(此题假定n取0时，为勒让德多项式第0项)。

Exp02-Basic11.jpg

输入：一个double类型浮点数和一个整数，分别对应x和n(0<=n<=20)。

输出：一个double类型浮点数，即勒让德多项式第n项的值，注意小数点后保留到第2位。

p_n(x) = \left\{
\begin{array}{ll}
1 \dotfill & n = 0 \\
x \dotfill & n = 1 \\
\frac{2n-1}{n} * x * p_{n-1}(x) - \frac{n-1}{n} * p_{n-2}(x) \dotfill & n > 1
\end{array}
\right.

样例1：

输入：3.4 2
输出：16.84
样例2：

输入：3.4 10
输出：30143685.82
样例3：

输入：-3.4 2
输出：16.84
*/

#include <stdio.h>

double p(int n, double x) {
  if (n == 0) {
    return 1.0;
  } else if (n == 1) {
    return x;
  } else {
    return (2 * n - 1) * x * p(n - 1, x) / n - (n - 1) * p(n - 2, x) / n;
  }
}

int main() {
  double x;
  int n;
  scanf("%lf %d", &x, &n);
  printf("%.2f\n", p(n, x));
}