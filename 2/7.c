/*
题目编号：Exp02-Basic07，GJBook3-03-07

题目名称：倍数

题目描述：任意一个整数n，如果n能同时被3、5、7整除，则n是3、5、7的倍数，如果n只能同时被其中的两个数整除，则n是两个数的倍数，如果n只能被其中一个数整除，则n是一个数的倍数，否则n不是3、5、7的倍数。


输入：输入一个整数。

输出：按照是否是倍数输出。


样例1：

输入：105
输出：3,5,7
样例2：

输入：30
输出：3,5
样例3：

输入：21
输出：3,7
样例4：

输入：35
输出：5,7
样例5：

输入：14
输出：7
样例6：

输入：101
输出：NULL
*/

#include <stdio.h>
#include <string.h>

typedef unsigned char bool;

int main() {
  unsigned long long data;
  scanf("%lld", &data);

  bool is3 = data % 3 == 0;
  bool is5 = data % 5 == 0;
  bool is7 = data % 7 == 0;

  char str[100] = "";
  if (is3) {
    strcat(str, "3,");
  }
  if (is5) {
    strcat(str, "5,");
  }
  if (is7) {
    strcat(str, "7,");
  }
  if (!(is3 || is5 || is7)) {
    strcat(str, "NULL,");
  }

  size_t len = strlen(str);
  if (len > 0) {
    str[len - 1] = '\0';
  }
  printf("%s", str);
}
