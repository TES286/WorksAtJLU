/*
题目编号：Exp04-Basic09，GJBook3-06-02

题目名称：检验矩阵主对角线对称

题目描述：编写程序，判断任意给定n*n的两维整型数组是否关于主对角线对称。


输入：第一行输入数组行数n（≤10），第二行随机输入n*n个整数作为数组元素值。

输出：如果数组关于主对角线对称，则输出YES；否则输出NO。



样例1：

输入：

3
1 2 3
2 1 2
3 2 1
输出：
YES
样例2：

输入：

3
0 0 1
2 1 2
3 2 1
输出：
NO
*/

#include <stdio.h>

#define N 15

void input_arr(int arr[N][N], int n) {
  int k;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &k);
      arr[i][j] = k;
    }
  }
}

int check(int arr[N][N], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      if (arr[i][j] != arr[j][i]) {
        return 0;
      }
    }
  }
  return 1;
}

int main() {
  int n;
  int arr[N][N];
  scanf("%d", &n);
  input_arr(arr, n);
  if (check(arr, n)) {
    printf("YES");
  } else {
    printf("NO");
  }
}
