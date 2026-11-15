/*
题目名称：统计指定单词出现的次数。

题目内容：输入6个单词，查找第6个单词在前5个单词中出现的次数。



输入：6个单词（以空格分隔）。

输出：一个整数，表示第6个单词在前5个单词中出现的次数。



样例：

输入：Mary Olivia Donald Olivia Linda Olivia 

输出：2
*/

#include <stdio.h>
#include <string.h>

int main() {
  char s[5][100];
  char c[100];
  int counter = 0;
  scanf("%s %s %s %s %s %s", s[0], s[1], s[2], s[3], s[4], c);
  for (int i = 0; i < 5; i++) {
    counter += strcmp(c, s[i]) == 0;
  }
  printf("%d", counter);
}