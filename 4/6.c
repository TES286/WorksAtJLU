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