/*
题目编号：Exp03-Basic02，GJBook3-05-06

题目名称：逆序数

题目描述：编写函数，求任意位自然数的逆序数，例如5432就是2345的逆序数。



输入：任意一个整数（<10^18） 。

输出：如果输入的不是自然数，则输出NULL；否则输出对应的逆序数。

说明：一位数字的自然数，其逆序数为其本身。


样例1：

输入：120
输出：21
样例2：

输入：1357
输出：7531
样例3：

输入：-1357
输出：NULL
*/

#include <stdio.h>

int main(){
  char str[1000];
  int chr, idx=0;
  while(1){
    chr = getchar();
    if(chr=='\n'||chr==EOF||chr=='\r'){break;}
    if(!(chr>='0'&&chr<='9')){printf("NULL");return 0;}
    str[idx++]=chr;
  }
  if(idx==0){printf("NULL");return 0;}
  while(idx>0&&str[--idx]=='0'){}
  if(idx<=0){printf("0");return 0;}
  for(int n=idx; n>=0; n--){
    printf("%c", str[n]);
  }
}