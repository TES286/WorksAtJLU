/*
题目编号：Exp03-Basic01，GJBook3-05-02

题目名称：组合问题

题目描述：编写程序，输入m，n的值，计算并输出函数f的值。

f(m, n) = \left\{
\begin{array}{ll}
0 \dotfill & m < n \text{ 且 } m > 0 \text{ 且 } n > 0 \\
1 \dotfill & m = n \text{ 且 } m > 0 \text{ 且 } n > 0 \\
\frac{m!}{(m-n)!n!} \dotfill & m > n \text{ 且 } m > 0 \text{ 且 } n > 0 \\
-1 \dotfill & \text{其他}
\end{array}
\right.

输入：一个整数m和一个整数n（m,n≤20）。

输出：函数f的值。


样例1：

输入：-1  2
输出：-1
样例2：

输入：2  2
输出：1
*/

#include <stdio.h>

long long b(long long x) {
  long long rst = x;
  for (long long i = x - 1; i > 0; i--) {
    rst *= i;
  }
  return rst;
}

long long f(long long m, long long n) {
  if (m <= 0 || n <= 0) {
    return -1;
  }
  if (m < n) {
    return 0;
  }
  if (m == n) {
    return 1;
  }
  if (m > n) {
    return b(m) / (b(n) * b(m - n));
  }
  return -1;
}

int main() {
  long long m, n;
  scanf("%lld %lld", &m, &n);
  printf("%lld", f(m, n));
  return 0;
}