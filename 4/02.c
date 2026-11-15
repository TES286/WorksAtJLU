/*
题目编号：Exp04-Basic02

题目名称：n倍数关系

题目描述：

给定若干不完全相同的正整数（数值小于10000）和n（n<5)，计算这些正整数里面有多少数对满足：其中一个是另一个的n倍。例如：1 4 3 2 9 7 18 22，n=3时得到的答案是2；因为3是1的3倍，9是3的3倍。


输入：输入第一行给出正整数n的值，接下来包括多组测试数据。每组数据最多100个整数占用一行，以数字0结束(不计入100个整数里)。测试数据不超过20组，最后一行只包括-1，表示输入数据结束。

输出：对每组输入数据，输出一行，给出有多少数对满足其中一个是另一个n倍；如果没有满足要求的数对，则输出0。

（注：最后一行末尾无换行符等多余字符）。

样例：

输入：
2
1 4 3 2 9 7 18 22 0
2 4 8 8 0
7 5 11 13 1 3 0
-1
输出：
3
3
0
*/

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