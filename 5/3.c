/*
题目编号：Exp05-Basic03，GJBook3例-07-01

题目名称：排序二维数组

题目描述：编写程序对输入的二维整型矩阵进行递增排序。



输入：第一行输入两个正整数n和m （n, m<=50）分别对应矩阵的行数和列数。随后n行，每行输入m个整数，每个整数间以空格间隔。

输出：排序后的矩阵：共n行，每行m个整数，之间以一个西文空格间隔，每行最后一个数字后除必要的回车换行符无其它字符，最后一行末尾无任何多余字符。



样例：

输入：
2 3
9 6 5
1 2 3
输出：
1 2 3
5 6 9
*/

#include <stdio.h>
#include <stdlib.h>

#define N 2600

void print_matrix(int numbers[N], int row, int col) {
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (j > 0) {
        putchar(' ');
      }
      printf("%d", numbers[col * i + j]);
      if (j == col - 1 && i < row - 1) {
        putchar('\n');
      }
    }
  }
}

void scan_int(int numbers[N], int limit) {
  for (int i = 0; i < limit; i++) {
    scanf("%d", &numbers[i]);
  }
}

void swap(int* numbers, int a, int b) {
  int tmp = numbers[a];
  numbers[a] = numbers[b];
  numbers[b] = tmp;
}

void copy(int* src, int* dst, int n) {
  if (n <= 0) return;
  while (n--) dst[n] = src[n];
}

void sort_(int* numbers, int len, int* tmp) {
  if (len <= 1) {
    return;
  } else if (len == 2) {
    if (numbers[0] <= numbers[1]) {
      return;
    } else {
      swap(numbers, 0, 1);
      return;
    }
  }

  int a = len / 2, b = len - a;
  sort_(numbers, a, tmp);
  sort_(&numbers[a], b, &tmp[a]);
  int i = 0, i1 = 0, i2 = a;
  while (i1 < a && i2 < len) {
    if (numbers[i1] <= numbers[i2]) {
      tmp[i++] = numbers[i1++];
    } else {
      tmp[i++] = numbers[i2++];
    }
  }
  copy(&numbers[i1], &tmp[i], a - i1);
  copy(&numbers[i2], &tmp[i], len - i2);
  copy(tmp, numbers, len);
}

void sort(int* numbers, int len){
  int* tmp = (int*)malloc(sizeof(int)*len);
  if(tmp==NULL) return;

  sort_(numbers, len, tmp);

  free(tmp);
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int numbers[N];
  scan_int(numbers, n * m);
  sort(numbers, n * m);
  print_matrix(numbers, n, m);
}
