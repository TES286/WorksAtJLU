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

void sort(int* numbers, int len) {
  if (len <= 1) {
    return;
  } else if (len == 2) {
    if (numbers[0] < numbers[1]) {
      return;
    } else {
      swap(numbers, 0, 1);
      return;
    }
  }

  int a = len / 2, b = len - a;
  sort(numbers, a);
  sort(&numbers[a], b);
  int* tmp = (int*)malloc(sizeof(int) * len);
  int i = 0, i1 = 0, i2 = a;
  while (i1 < a && i2 < len) {
    if (numbers[i1] < numbers[i2]) {
      tmp[i++] = numbers[i1++];
    } else {
      tmp[i++] = numbers[i2++];
    }
  }
  copy(&numbers[i1], &tmp[i], a - i1);
  copy(&numbers[i2], &tmp[i], len - i2);
  copy(tmp, numbers, len);
  free(tmp);
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int numbers[N];
  scan_int(numbers, n * m);
  sort(numbers, n*m);
  print_matrix(numbers, n, m);
}
