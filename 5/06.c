/*
题目名称：字符串替换。

题目内容：编程序，将字符串中的所有大写英文字母按如下规则替换,其余类型的字符不替换。

原字母：ABCDEFGHIJKLMNOPQRSTUVWXYZ 

替换后字母：ZYXWVUTSRQPONMLKJIHGFEDCBA



输入：在一行中输入一个不超过99个字符、并以回车结束的字符串。

输出：在一行中输出替换完成后的字符串。



样例：

输入：Hijklmn OPq …XYZ    

输出：Sijklmn LKq …CBA
*/

#include <stdio.h>

unsigned char alphabet[0xFF + 1];

void init() {
  for (int i = 0; i <= 0xFF; i++) alphabet[i] = i;
  for (int i = 'A'; i <= 'Z'; i++) alphabet[i] = 'Z' - (i - 'A');
}

int main() {
  init();
  int ch;
  while ((ch = getchar()) != '\0' && ch != '\n' && ch != '\r' && ch != EOF) {
    putchar(alphabet[ch]);
  }
}
