/*
题目编号: Exp04-Basic08,GJBook3-06-03

题目名称: 矩阵转置

问题描述: 编写程序，将任意给定n*n的两维整型数组转置。



输入：第一行输入数组行数n（≤10），第二行随机输入n*n个整数作为数组元素值。

输出：按先行后列、从左至右的顺序输出转置后数组内的所有元素，每行n个元素，同一行内的各元素间以一个西文空格间隔，除最后一行外，每行行末均有一个换行符，除此以外无任何多余字符。



样例1：

输入：
3
1 2 3
1 2 3
1 2 3
输出：
1 1 1
2 2 2
3 3 3
说明：1）前两行的最后一个元素后面仅有一个换行符；2）最后一行的最后一个元素后面无换行符。
样例2：

输入：
3
1 1 1
2 2 2
3 3 3
输出：
1 2 3
1 2 3
1 2 3
*/

#include <stdio.h>

#define N 15

void print_arr(int arr[N][N], int n) {
  int is_first_line = 1;
  int is_first_col = 1;
  for (int i = 0; i < n; i++) {
    if (!is_first_line) {
      printf("\n");
    }
    is_first_line = 0;
    for (int j = 0; j < n; j++) {
      if (!is_first_col) {
        printf(" ");
      }
      is_first_col = 0;
      printf("%d", arr[j][i]);
    }
    is_first_col = 1;
  }
}

void input_arr(int arr[N][N], int n) {
  int k;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &k);
      arr[i][j] = k;
    }
  }
}

int main() {
  int arr[N][N];
  int n;
  scanf("%d", &n);
  input_arr(arr, n);
  print_arr(arr, n);
}