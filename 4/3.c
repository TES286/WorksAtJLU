#include <stdio.h>

int main(void) {
  const int n = 10;
  int a[10], b[10], c[10];
  int i, j;
  for (i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    b[i] = a[i];
    c[i] = a[i];
  }
  int selectCmp = 0, selectSwap = 0;
  for (i = 0; i < n - 1; ++i) {
    int minIndex = i;
    for (j = i + 1; j < n; ++j) {
      ++selectCmp;
      if (a[j] < a[minIndex]) {
        minIndex = j;
      }
    }
    int t = a[i];
    a[i] = a[minIndex];
    a[minIndex] = t;
    ++selectSwap;
  }
  int bubbleCmp = 0, bubbleSwap = 0;
  for (i = 0; i < n; ++i) {
    int changed = 0;
    for (j = 0; j < n - 1; ++j) {
      ++bubbleCmp;
      if (b[j] > b[j + 1]) {
        int t = b[j];
        b[j] = b[j + 1];
        b[j + 1] = t;
        ++bubbleSwap;
        changed = 1;
      }
    }
    if (!changed) {
      break;
    }
  }
  int insertCmp = 0, insertMove = 0;
  for (i = 1; i < n; ++i) {
    int temp = c[i];
    int pos = i - 1;
    int shifts = 0;

    while (1) {
      ++insertCmp;
      if (pos >= 0 && c[pos] > temp) {
        c[pos + 1] = c[pos];
        ++shifts;
        --pos;
      } else {
        break;
      }
    }
    if (shifts > 0) {
      insertMove += shifts + 1;
    }
    c[pos + 1] = temp;
  }
  printf("%d %d %d %d %d %d\n", selectCmp, selectSwap, bubbleCmp, bubbleSwap,
         insertCmp, insertMove);
  return 0;
}