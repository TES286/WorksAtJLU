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