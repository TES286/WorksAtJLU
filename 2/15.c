/*
题目名称：时间值是否合法。

题目内容：输入三个正整数依次表示时、分、秒，判断值是否合法，合法输出OK，否则输出NO。



输入：三个正整数 

输出：OK或NO



样例1：

输入：12 54 21   

输出：OK 

样例2：

输入：25 25 12  

输出：NO
*/

#include <stdio.h>

int main(){
  int h, m, s;
  scanf("%d %d %d", &h, &m, &s);
  if(!(0<=h && h<=23)){
    printf("NO");
    return 0;
  }
  if(!(0<=m && m<=60)){
    printf("NO");
    return 0;
  }
  if(!(0<=s && s<=60)){
    printf("NO");
    return 0;
  }
  printf("OK");
}