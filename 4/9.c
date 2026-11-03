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
