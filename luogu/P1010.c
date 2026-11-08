/*
# P1010 [NOIP 1998 普及组] 幂次方

## 题目描述

任何一个正整数都可以用 $2$ 的幂次方表示。例如 $137=2^7+2^3+2^0 $。

同时约定次方用括号来表示，即 $a^b$ 可表示为 $a(b)$。

由此可知，$137$ 可表示为 $2(7)+2(3)+2(0)$。

进一步：

$7= 2^2+2+2^0$  ( $2^1$ 用 $2$ 表示)，并且 $3=2+2^0$。

所以最后 $137$ 可表示为 $2(2(2)+2+2(0))+2(2+2(0))+2(0)$。

又如 $1315=2^{10} +2^8 +2^5 +2+1$。

所以 $1315$ 最后可表示为 $2(2(2+2(0))+2)+2(2(2+2(0)))+2(2(2)+2(0))+2+2(0)$。

## 输入格式

一行一个正整数 $n$。

## 输出格式

符合约定的 $n$ 的 $0, 2$ 表示（在表示中不能有空格）。

## 输入输出样例 #1

### 输入 #1

```
1315
```

### 输出 #1

```
2(2(2+2(0))+2)+2(2(2+2(0)))+2(2(2)+2(0))+2+2(0)
```

## 说明/提示

**【数据范围】**

对于 $100\%$ 的数据，$1 \le n \le 2 \times {10}^4$。

NOIP1998 普及组 第三题
*/

#include <stdio.h>

#define M0 0b0000000000000001
#define M1 0b0000000000000010
#define M2 0b0000000000000100
#define M3 0b0000000000001000
#define M4 0b0000000000010000
#define M5 0b0000000000100000
#define M6 0b0000000001000000
#define M7 0b0000000010000000
#define M8 0b0000000100000000
#define M9 0b0000001000000000
#define M10 0b0000010000000000
#define M11 0b0000100000000000
#define M12 0b0001000000000000
#define M13 0b0010000000000000
#define M14 0b0100000000000000
#define M15 0b1000000000000000

/**
 * @input n
 * @output buffer
 * @input len
 * @return length_write
 */
inline static int build_str(short n, char* buffer) {
  int i = 0;
  unsigned is_first = 1;
  if (n & M15) {
    if(!is_first) buffer[i++] = '+';
    is_first = 0;
    buffer[i++] = '2';
    buffer[i++] = '(';
    i += build_str(15, &buffer[i]);
    buffer[i++] = ')';
  }
  if (n & M14) {
    if(!is_first) buffer[i++] = '+';
    is_first = 0;
    buffer[i++] = '2';
    buffer[i++] = '(';
    i += build_str(14, &buffer[i]);
    buffer[i++] = ')';
  }
  if (n & M13) {
    if(!is_first) buffer[i++] = '+';
    is_first = 0;
    buffer[i++] = '2';
    buffer[i++] = '(';
    i += build_str(13, &buffer[i]);
    buffer[i++] = ')';
  }
  if (n & M12) {
    if(!is_first) buffer[i++] = '+';
    is_first = 0;
    buffer[i++] = '2';
    buffer[i++] = '(';
    i += build_str(12, &buffer[i]);
    buffer[i++] = ')';
  }
  if (n & M11) {
    if(!is_first) buffer[i++] = '+';
    is_first = 0;
    buffer[i++] = '2';
    buffer[i++] = '(';
    i += build_str(11, &buffer[i]);
    buffer[i++] = ')';
  }
  if (n & M10) {
    if(!is_first) buffer[i++] = '+';
    is_first = 0;
    buffer[i++] = '2';
    buffer[i++] = '(';
    i += build_str(10, &buffer[i]);
    buffer[i++] = ')';
  }
  if (n & M9) {
    if(!is_first) buffer[i++] = '+';
    is_first = 0;
    buffer[i++] = '2';
    buffer[i++] = '(';
    i += build_str(9, &buffer[i]);
    buffer[i++] = ')';
  }
  if (n & M8) {
    if(!is_first) buffer[i++] = '+';
    is_first = 0;
    buffer[i++] = '2';
    buffer[i++] = '(';
    i += build_str(8, &buffer[i]);
    buffer[i++] = ')';
  }
  if (n & M7) {
    if(!is_first) buffer[i++] = '+';
    is_first = 0;
    buffer[i++] = '2';
    buffer[i++] = '(';
    i += build_str(7, &buffer[i]);
    buffer[i++] = ')';
  }
  if (n & M6) {
    if(!is_first) buffer[i++] = '+';
    is_first = 0;
    buffer[i++] = '2';
    buffer[i++] = '(';
    i += build_str(6, &buffer[i]);
    buffer[i++] = ')';
  }
  if (n & M5) {
    if(!is_first) buffer[i++] = '+';
    is_first = 0;
    buffer[i++] = '2';
    buffer[i++] = '(';
    i += build_str(5, &buffer[i]);
    buffer[i++] = ')';
  }
  if (n & M4) {
    if(!is_first) buffer[i++] = '+';
    is_first = 0;
    buffer[i++] = '2';
    buffer[i++] = '(';
    i += build_str(4, &buffer[i]);
    buffer[i++] = ')';
  }
  if (n & M3) {
    if(!is_first) buffer[i++] = '+';
    is_first = 0;
    buffer[i++] = '2';
    buffer[i++] = '(';
    i += build_str(3, &buffer[i]);
    buffer[i++] = ')';
  }
  if (n & M2) {
    if(!is_first) buffer[i++] = '+';
    is_first = 0;
    buffer[i++] = '2';
    buffer[i++] = '(';
    buffer[i++] = '2';
    buffer[i++] = ')';
  }
  if (n & M1) {
    if(!is_first) buffer[i++] = '+';
    is_first = 0;
    buffer[i++] = '2';
  }
  if(n&M0){
    if(!is_first) buffer[i++] = '+';
    is_first = 0;
    buffer[i++] = '2';
    buffer[i++] = '(';
    buffer[i++] = '0';
    buffer[i++] = ')';
  }
  return i;
}


int main(){
  short n;
  scanf("%hd", &n);
  char buffer[4096];
  int len = build_str(n, buffer);
  for(int i=0; i<len; i++){
    putchar(buffer[i]);
  }
}