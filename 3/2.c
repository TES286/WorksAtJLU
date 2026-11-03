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