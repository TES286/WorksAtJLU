/*
题目编号 ：Exp04-Basic06，GJBook3-06-04

题目名称：循环右移

题目描述：编写程序，不使用其它辅助数组，把一维整型数组中的各个元素循环右移j位。

输入：

第一行输入两个整数，n表示数组长度（0<n<=100），j表示循环右移的位数（j>=0）；

第二行依次从键盘随机输入n个整数作为数组元素值。

输出：

循环右移后的整数数组，各元素间以一个西文空格间隔，最后一个元素后无字符。



样例1：

输入：
10 2
1 2 3 4 5 6 7 8 9 0
输出：
9 0 1 2 3 4 5 6 7 8
样例2：

输入：
10 23
1 2 3 4 5 6 7 8 9 0
输出：
8 9 0 1 2 3 4 5 6 7
*/

#include <stdio.h>

void rshift(int x[], int len) {
  int last = x[len - 1];
  for (int i = len - 1; i > 0; i--) {
    x[i] = x[i - 1];
  }
  x[0] = last;
}

int main() {
  int n, j, t;
  scanf("%d %d", &n, &j);
  j%=n;
  int x[10000];
  for (int i = 0; i < n; i++) {
    scanf("%d", &t);
    x[i] = t;
  }
  while (j--) rshift(x, n);
  int is_first = 1;
  for (int i=0; i<n; i++){
    if(!is_first){
      putchar(' ');
    }
    is_first = 0;
    printf("%d", x[i]);
  }
}