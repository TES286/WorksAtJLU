#include <stdio.h>

int cmp(const void* a, const void* b) {
  float x = *(const float*)a;
  float y = *(const float*)b;
  return (x > y) - (x < y);
}

int main() {
  float nums[3];
  scanf("%f %f %f", &nums[0], &nums[1], &nums[2]);
  qsort(nums, 3, sizeof(float), cmp);
  printf("%.1f %.1f %.1f\n", nums[0], nums[1], nums[2]);
}