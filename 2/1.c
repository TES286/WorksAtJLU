/*
题目编号：Exp02-Basic01，GJBook3-03-03

题目名称：递增排序

题目描述：任意三个实数a、b、c，按照从小到大的顺序输出。



输入：输入三个实数（测试数据均只有一位小数）。

输出：按照从小到大顺序输出之前输入的三个实数，以一个西文空格间隔，且每个实数小数点后保留1位。



样例：

输入：
2.3  5.6  1.2
输出：
1.2 2.3 5.6
*/

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