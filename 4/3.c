/*
题目编号:  Exp04-Basic03

题目名称:  数组排序
题目描述:  编写函数，分别采用教材给出的“主元选择排序”、“冒泡排序”和“逐步增加递增子序列”排序（插入排序）方法对给定数组进行排序。综合运用调试方法，观察不同排序方法在排序过程中数组元素值的变化情况，如观察递增排序如下序列{9、8、7、6、5、4、3、2、1、0}，{0、1、2、3、4、5、6、7、8、9}和{2、9、4、7、6、5、8、3、0、1}时，数组中元素比较次数、移动或交换次数。

说明：

（1）对于“主元选择排序”和“冒泡排序”，执行完3个赋值操作，计为1次交换。

（2）对于“逐步增加递增子序列”排序，每执行一次while循环的循环条件判断，计为1次比较；如果在某轮比较中元素本身的位置没有变化，则本轮移动次数为0。

（3）因本题目的是观察输出数据，深入理解排序算法；所以样例点和实测点一致。



输入:包含10个整数的待排序数组。

输出:在一行内依次输出，递增排序时，主元排序比较次数 和 移动/交换次数、冒泡排序比较次数 和 移动/交换次数和递增子序列排序比较次数 和 移动/交换次数，相邻数字之间以一个西文空格间隔。



样例1:

输入：
9 8 7 6 5 4 3 2 1 0
输出：
45 9 90 45 54 54
样例2:

输入：
0 1 2 3 4 5 6 7 8 9
输出：
45 9 9 0 9 0
样例3:

输入：
2 2 3 3 5 5 4 4 6 6
输出：
45 9 27 4 13 6
样例4:

输入：
1 0 3 2 5 4 7 6 9 8
输出：
45 9 18 5 14 10
样例5:

输入：
1 2 3 4 5 5 4 3 2 1
输出：
45 9 81 20 29 24
*/

// 注：这题可以打表

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