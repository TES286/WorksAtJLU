#include <stdio.h>

int exam(const int nums[1000], int n, int len) {
  int counter = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (nums[i] * n == nums[j] || nums[j] * n == nums[i]) {
        counter++;
      }
    }
  }
  return counter;
}

int main() {
  int nums[1000];
  int n, i, t;
  int is_first = 1;
  scanf("%d", &n);
  while (1) {
    i = 0;
    while (1) {
      scanf("%d", &t);
      if (t == 0) {
        break;
      }
      if (t == -1) {
        return 0;
      }
      nums[i] = t;
      i++;
    }
    if (!is_first) {
      printf("\n");
    }
    printf("%d", exam(nums, n, i));
    is_first = 0;
  }
}