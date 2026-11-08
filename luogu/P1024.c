/*
# P1024 [NOIP 2001 提高组] 一元三次方程求解

## 题目描述

有形如：$a x^3 + b x^2 + c x + d = 0$
这样的一个一元三次方程。给出该方程中各项的系数（$a,b,c,d$
均为实数），并约定该方程存在三个不同实根（根的范围在 $-100$ 至 $100$
之间），且根与根之差的绝对值 $\ge
1$。要求由小到大依次在同一行输出这三个实根(根与根之间留有空格)，并精确到小数点后
$2$ 位。

提示：记方程 $f(x) = 0$，若存在 $2$ 个数 $x_1$ 和 $x_2$，且 $x_1 < x_2$，$f(x_1)
\times f(x_2) < 0$，则在 $(x_1, x_2)$ 之间一定有一个根。

## 输入格式

一行，$4$ 个实数 $a, b, c, d$。

## 输出格式

一行，$3$ 个实根，从小到大输出，并精确到小数点后 $2$ 位。

## 输入输出样例 #1

### 输入 #1

```
1 -5 -4 20

```

### 输出 #1

```
-2.00 2.00 5.00

```

## 说明/提示

**【题目来源】**

NOIP 2001 提高组第一题
*/

// 注：这题本意应该是让写二分法的，但是三次方程有求根公式，这个更快
//     而要求保留两位小数，在double下精度完全足够

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
  double x = *(const double*)a;
  double y = *(const double*)b;
  return (x > y) - (x < y);
}

int main() {
  double a, b, c, d;
  scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
  double pi = acos(-1.0);
  double p = (3 * a * c - b * b) / (3 * a * a);
  double q =
      (2 * b * b * b - 9 * a * b * c + 27 * a * a * d) / (27 * a * a * a);
  double y1 = 2 * sqrt(-p / 3) *
              cos((acos(3 * q * sqrt(-3 / p) / (2 * p)) - 2 * pi * 1) / 3);
  double y2 = 2 * sqrt(-p / 3) *
              cos((acos(3 * q * sqrt(-3 / p) / (2 * p)) - 2 * pi * 2) / 3);
  double y3 = 2 * sqrt(-p / 3) *
              cos((acos(3 * q * sqrt(-3 / p) / (2 * p)) - 2 * pi * 3) / 3);
  double delta = -b/(3*a);
  double x1 = y1+delta;
  double x2 = y2+delta;
  double x3 = y3+delta;
  double x[3] = {x1, x2, x3};
  qsort(x, sizeof(x)/sizeof(x[0]), sizeof(x[0]), cmp);
  printf("%.2lf %.2lf %.2lf", x[0], x[1], x[2]);
}