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