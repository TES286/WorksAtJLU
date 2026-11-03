/*
题目编号 ：Exp04-Enhance02，GJBook3-06-26

题目名称：约瑟夫问题(Josephus)

题目描述：

古代某法官要判决 n 个犯人死刑, 他有一条荒唐的逻辑,
将犯人首尾相接排成圆圈，所有计数从1开始； 然后从第 s 个人开始数, 每数到第 m
个犯人，则拉出来处决; 然后再数 m 个，数到的犯人再处决；... ;
但剩下的最后一个犯人可以赦免。编程序，给出处决顺序，并告知哪一个人活下来。



输入：三个正整数 n（≤1000），s和m，都可以使用int类型变量表示。

输出：依次输出被处决人员的编号，每个编号之间用一个西文空格间隔，最后一个编号后无字符。


样例：

输入：6 1 5
输出：5 4 6 2 3 1
*/

#include <stdlib.h>
#include <stdio.h>

struct Entry {
  struct Entry* next;
  int id;
};

void delete_node(struct Entry* table, int id) {
  struct Entry* this_ = table;
  struct Entry* current = table;
  void* p;
  do {
    if (current->next->id == id) {
      p = current->next;
      current->next = current->next->next;
      free(p);
      break;
    }
    current = current->next;
  } while (current->next != this_);
}

struct Entry* step(struct Entry* table, int step) {
  while (step--) {
    table = table->next;
  }
  return table;
}

struct Entry* locate(struct Entry* table, int locator) {
  while (1) {
    if (table->id == locator) {
      return table;
    }
    table = table->next;
  }
}

int main() {
  int n, s, m;
  scanf("%d %d %d", &n, &s, &m);
  struct Entry* first = (struct Entry*)malloc(sizeof(struct Entry));
  first->id = 1;
  first->next = first;
  struct Entry* current = first;
  for (int i = 2; i <= n; i++) {
    struct Entry* p = (struct Entry*)malloc(sizeof(struct Entry));
    p->id = i;
    p->next = first;
    current->next = p;
    current = p;
  }
  struct Entry* c = locate(first, s);
  struct Entry* x = c;
  int id;
  int remain = n;
  while (x != x->next) {
    x = step(x, (m - 1) % remain);
    id = x->id;
    printf("%d ", id);
    x = x->next;
    delete_node(x, id);
    remain--;
  }
  printf("%d", x->id);
  free(x);
}