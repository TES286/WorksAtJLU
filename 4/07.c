/*
题目编号：Exp04-Basic07，GJBook3-06-01

题目名称：检验矩阵重复元素

题目描述：编写程序判断任意给定n*n的两维整型数组中是否有相同元素。


输入：第一行输入数组行数n（≤10），第二行随机输入n*n个整数作为数组元素值。

输出：如果数组中有相同元素，则输出YES；否则，输出NO。


样例1：

输入：
3
1 2 3 4 5 6 7 8 9
输出：
NO
样例2：

输入：
3
1 1 2 3 4 5 6 7 8
输出：
YES
*/

#include <stdio.h>

int within(int x[10000], int n, int len) {
  for (int i = 0; i < len; i++) {
    if (x[i] == n) {
      return 1;
    }
  }
  return 0;
}

int main() {
  int n, t;
  scanf("%d", &n);
  int x[10000];
  for (int i = 0; i < n*n; i++) {
    scanf("%d", &t);
    if (within(x, t, i)) {
      printf("YES");
      return 0;
    }
    x[i] = t;
  }
  printf("NO");
}