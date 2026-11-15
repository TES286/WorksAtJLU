/*
题目编号：Exp04-Basic04，GJBook3-06-19

题目名称：删除重复元素

题目描述：编写函数，不使用其他辅助数组，把整型数组中重复元素删得只剩一个；所有未被删除元素都保留最先顺序移动到数组前面。


输入：第一行输入数组长度n（≤100），第二行依次从键盘随机输入n个整数作为数组元素值。

输出：已删除重复元素的数组，各元素间以一个西文空格间隔，最后一个元素后无字符。



样例1：

输入：
10
1 1 2 3 3 3 2 1 2 4
输出：
1 2 3 4
样例2：

输入：
10
1 0 2 2 2 2 2 2 2 2
输出：
1 0 2
*/

#include <stdio.h>

int within(int x[1000], int n, int len) {
  for (int i = 0; i < len; i++) {
    if (x[i] == n) {
      return 1;
    }
  }
  return 0;
}

int main() {
  int x[1000];
  int n, k, j = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &k);
    if (within(x, k, j)) {
      continue;
    }
    x[j++] = k;
  }
  int is_first = 1;
  for (int m = 0; m < j; m++) {
    if (!is_first) {
      printf(" ");
    }
    printf("%d", x[m]);
    is_first = 0;
  }
}