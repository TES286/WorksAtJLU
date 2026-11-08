/*
# P1015 [NOIP 1999 普及组] 回文数

## 题目描述

若一个数（首位不为零）从左向右读与从右向左读都一样，我们就将其称为回文数。

例如，给定一个十进制数 $56$，将 $56$ 加 $65$（即把 $56$ 从右向左读），得到的 $121$ 是一个回文数。

又如，对于十进制数 $87$：

STEP1：$87+78=165$  
STEP2：$165+561=726$  
STEP3：$726+627=1353$   
STEP4：$1353+3531=4884$  

在这里，一步是指进行一次 $N$ 进制加法，上例最少用了 $4$ 步得到回文数 $4884$。

请编写程序，给定一个 $N$ 进制数 $M$，求最少经过几步可以得到回文数。如果在 $30$ 步以内（包含 $30$ 步）不可能得到回文数，则输出 `Impossible!`。

其中，$2\le N\le 10$ 或 $N=16$，$M$ 的长度不超过 $100$ 位，且只包含数字或大写字母。

## 输入格式

输入共两行。

第一行包含一个整数 $N$。

第二行包含一个 $N$ 进制数 $M$。

## 输出格式

如果能在 $30$ 步以内得到回文数，输出格式形如 `STEP=ans`，其中 $\text{ans}$ 为最少得到回文数的步数。

否则输出 `Impossible!`。

## 输入输出样例 #1

### 输入 #1

```
10
87

```

### 输出 #1

```
STEP=4

```
*/
#include <stdio.h>

typedef unsigned char uint8;

#define N 200

inline static void add(uint8 a[N], uint8 b[N], uint8 n){
  uint8 ch = 0;
  uint8 chn[2] = {0, n};
  for(int i=0; i<N; i++){
    a[i] = a[i] + b[i] + ch;
    ch = a[i] >= n;
    a[i] = a[i] - chn[ch];
  }
}

inline static int len(uint8 number[N]){
  int l = N-1;
  while(number[l] == 0) l--;
  return l+1;
}

inline static unsigned check(uint8 number[N]){
  int l = len(number);
  unsigned f = 1;
  for(int i=0; i<l/2; i++){
    f &= number[i] == number[l-i-1];
  }
  return f;
}

inline static void reverse(uint8 number[N], uint8 number_r[N]){
  int l = len(number)-1;
  for(int i=0; i<=l; i++){
    number_r[i] = number[l-i];
  }
}

char s2n[256];

inline static void init(){
  for(int i='0'; i<='9'; i++){
    s2n[i] = i-'0';
  }
  for(int i='A'; i<='F'; i++){
    s2n[i] = i-'A'+10;
  }
}

int main(){
  init();

  uint8 n;
  scanf("%hhu", &n);
  while (getchar()!='\n') ;
  int ch, i=0;
  uint8 number[N] = {0};
  uint8 number_r[N] = {0};
  while((ch=getchar())!=EOF&&ch!='\n'&&ch!='\r'&&ch!='\0'){
    number[i++]=s2n[ch];
  }
  for(int i=0; i<=30; i++){
    if(check(number)) {printf("STEP=%d", i); return 0;}
    reverse(number, number_r);
    add(number, number_r, n);
  }
  printf("Impossible!");
}
