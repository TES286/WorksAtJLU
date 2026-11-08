/*
# P1009 [NOIP 1998 普及组] 阶乘之和

## 题目描述

用高精度计算出 $S = 1! + 2! + 3! + \cdots + n!$（$n \le 50$）。

其中 `!` 表示阶乘，定义为 $n!=n\times (n-1)\times (n-2)\times \cdots \times
1$。例如，$5! = 5 \times 4 \times 3 \times 2 \times 1=120$。

## 输入格式

一个正整数 $n$。

## 输出格式

一个正整数 $S$，表示计算结果。

## 输入输出样例 #1

### 输入 #1

```
3

```

### 输出 #1

```
9
```

## 说明/提示

**【数据范围】**

对于 $100 \%$ 的数据，$1 \le n \le 50$。

**【其他说明】**

注，《深入浅出基础篇》中使用本题作为例题，但是其数据范围只有 $n \le
20$，使用书中的代码无法通过本题。

如果希望通过本题，请继续学习第八章高精度的知识。

NOIP1998 普及组 第二题
*/

// IT SHOULD WRITE BIGINT!

#define NULL 0

// l 是低位，n2 是高位

#include <stdint.h>
#include <stdio.h>

typedef uint32_t uint32;
typedef uint64_t uint64;
typedef struct {
  uint64 l, h;
} uint128;
typedef struct {
  uint128 l, h;
} uint256;
typedef struct {
  uint256 l, h;
} uint512;

const static uint32 zero32 = 0;
const static uint64 zero64 = 0;
const static uint128 zero128 = {.h = 0, .l = 0};
const static uint256 zero256 = {.h = {.h = 0, .l = 0}, .l = {.h = 0, .l = 0}};

static inline uint32 add32(uint32 a, uint32 b, unsigned* sign, unsigned u) {
  uint32 rst = a + b;
  *sign = (unsigned)(rst < a);
  rst += u;
  *sign |= (unsigned)(rst < u);
  return rst;
}

static inline uint64 add64(uint64 a, uint64 b, unsigned* sign, unsigned u) {
  uint64 rst = a + b;
  *sign = (unsigned)(rst < a);
  rst += u;
  *sign |= (unsigned)(rst < u);
  return rst;
}

static inline uint128 add128(uint128 a, uint128 b, unsigned* sign, unsigned u) {
  uint128 rst;
  unsigned c;
  rst.l = add64(a.l, b.l, &c, u);
  rst.h = add64(a.h, b.h, sign, c);
  return rst;
}

static inline uint256 add256(uint256 a, uint256 b, unsigned* sign, unsigned u) {
  uint256 rst;
  unsigned c;
  rst.l = add128(a.l, b.l, &c, u);
  rst.h = add128(a.h, b.h, sign, c);
  return rst;
}

static inline uint512 add512(uint512 a, uint512 b, unsigned* sign, unsigned u) {
  uint512 rst;
  unsigned c;
  rst.l = add256(a.l, b.l, &c, u);
  rst.h = add256(a.h, b.h, sign, c);
  return rst;
}

static inline uint64 mul32(uint32 a, uint32 b, uint32 overflow_l) {
  unsigned dummy;
  uint64 r = (uint64)a * (uint64)b;
  r = add64(r, overflow_l, &dummy, 0);  // never overflow
  return r;
}

static inline uint128 mul64(uint64 a, uint64 b, uint64 overflow_l) {
  unsigned dummy;
  uint128 r;
  uint32 al = (uint32)a, ah = a >> 32;
  uint32 bl = (uint32)b, bh = b >> 32;
  r.l = mul32(al, bl, 0);
  r.h = mul32(ah, bh, 0);
  uint64 lh = mul32(al, bh, 0);
  uint64 hl = mul32(ah, bl, 0);
  unsigned ovh;
  uint64 m = add64(lh, hl, &ovh, 0);
  uint128 b_ = {.h = m >> 32, .l = m << 32};
  r.h += ((uint64)ovh) << 32;
  r = add128(r, b_, &dummy, 0);
  uint128 ov = {.h = 0, .l = overflow_l};
  r = add128(r, ov, &dummy, 0);
  return r;
}

static inline uint256 mul128(uint128 a, uint128 b, uint128 overflow_l) {
  unsigned dummy;
  uint256 r;
  uint64 al = a.l, ah = a.h;
  uint64 bl = b.l, bh = b.h;
  r.l = mul64(al, bl, 0);
  r.h = mul64(ah, bh, 0);
  uint128 lh = mul64(al, bh, 0);
  uint128 hl = mul64(ah, bl, 0);
  unsigned ovh;
  uint128 m = add128(lh, hl, &ovh, 0);
  uint256 b_ = {.h = {.h = 0, .l = m.h}, .l = {.h = m.l, .l = 0}};
  r.h.h += ovh;
  r = add256(r, b_, &dummy, 0);
  uint256 ov = {.h = 0, .l = overflow_l};
  r = add256(r, ov, &dummy, 0);
  return r;
}

static inline uint512 mul256(uint256 a, uint256 b, uint256 overflow_l) {
  unsigned dummy;
  uint512 r;
  uint128 al = a.l, ah = a.h;
  uint128 bl = b.l, bh = b.h;
  r.l = mul128(al, bl, zero128);
  r.h = mul128(ah, bh, zero128);
  uint256 lh = mul128(al, bh, zero128);
  uint256 hl = mul128(ah, bl, zero128);
  unsigned ovh;
  uint256 m = add256(lh, hl, &ovh, 0);
  uint512 b_ = {.h = {.h = 0, .l = m.h}, .l = {.h = m.l, .l = 0}};
  r.h.h.l += ovh;
  r = add512(r, b_, &dummy, 0);
  uint512 ov = {.h = 0, .l = overflow_l};
  r = add512(r, ov, &dummy, 0);
  return r;
}

static inline unsigned eq128(uint128 a, uint128 b) {
  return a.h == b.h && a.l == b.l;
}

static inline unsigned eq256(uint256 a, uint256 b) {
  return eq128(a.h, b.h) && eq128(a.l, b.l);
}

static inline unsigned bit256(uint256 x, int i) {
  if (i < 64) return (unsigned)((x.l.l >> i) & 1u);
  if (i < 128) return (unsigned)((x.l.h >> (i - 64)) & 1u);
  if (i < 192) return (unsigned)((x.h.l >> (i - 128)) & 1u);
  return (unsigned)((x.h.h >> (i - 192)) & 1u);
}

static void print256(uint256 x) {
  unsigned char d[100] = {0};
  int len = 1;

  for (int i = 255; i >= 0; --i) {
    unsigned carry = bit256(x, i);

    for (int j = 0; j < len; ++j) {
      unsigned v = (unsigned)d[j] * 2u + carry;
      if (v >= 10u) {
        d[j] = (unsigned char)(v - 10u);
        carry = 1u;
      } else {
        d[j] = (unsigned char)v;
        carry = 0u;
      }
    }

    if (carry) {
      d[len++] = 1;
    }
  }

  while (len > 1 && d[len - 1] == 0) --len;

  for (int i = len - 1; i >= 0; --i) {
    putchar('0' + d[i]);
  }
  putchar('\n');
}

uint256 cache[64];

static inline void init() {
  for (int i = 0; i < 64; i++) {
    cache[i] = zero256;
  }
}

static inline uint256 factorial(int n) {
  if (!eq256(cache[n], zero256)) {
    return cache[n];
  }
  uint256 n_ = {.h = zero128, .l = {.h = 0, .l = n}};
  if (n == 2 || n == 1) {
    return n_;
  }
  uint256 rst = mul256(n_, factorial(n - 1), zero256).l;
  cache[n] = rst;
  return rst;
}

int main() {
  int n;
  unsigned dummy;
  scanf("%d", &n);
  init();
  uint256 rst = zero256;
  for (int i = 1;i <= n; i++ ) {
    rst = add256(rst, factorial(i), &dummy, 0);
  }
  print256(rst);
}