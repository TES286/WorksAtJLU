#include <stdio.h>

int main(){
  char str[1000];
  int i=0, s;
  while ((s = getchar())!=-1)
  {
    str[i++]=s;
  }
  for(int j=i-1; j>=0; j--){
    putchar(str[j]);
  }
}
