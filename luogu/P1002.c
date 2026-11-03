#include <stdio.h>

struct Point {
  int x;
  int y;
};

typedef struct Point P;
long long cache[25][25];

void init() {
  for (int i = 0; i < 25; i++) {
    for (int j = 0; j < 25; j++) {
      cache[i][j] = -1;
    }
  }
}

int in_skip(P p, P skips[], int len) {
  for (int i = 0; i < len; i++) {
    if (p.x == skips[i].x && p.y == skips[i].y) {
      return 1;
    }
  }
  return 0;
}

long long gp(P src, P dst, P skips[], int len) {
  if (cache[src.x][src.y] != -1) {
    return cache[src.x][src.y];
  }
  long long n = 0;
  if (in_skip(src, skips, len)) {
    return 0;
  }
  if (src.x == dst.x && src.y == dst.y) {
    return 1;
  }
  if (src.x < dst.x) {
    src.x++;
    n += gp(src, dst, skips, len);
    src.x--;
  }
  if (src.y < dst.y) {
    src.y++;
    n += gp(src, dst, skips, len);
    src.y--;
  }
  cache[src.x][src.y] = n;
  return n;
}

int main() {
  P b, m;
  scanf("%d %d %d %d", &b.x, &b.y, &m.x, &m.y);
  P sk[9] = {
      {.x = -2, .y = -1}, {.x = 2, .y = -1}, {.x = -1, .y = -2},
      {.x = 1, .y = -2},  {.x = -2, .y = 1}, {.x = 2, .y = 1},
      {.x = -1, .y = 2},  {.x = 1, .y = 2},  {.x = 0, .y = 0},
  };
  for (int i = 0; i < 9; i++) {
    sk[i].x += m.x;
    sk[i].y += m.y;
  }
  P s = {.x = 0, .y = 0};
  init();
  printf("%lld", gp(s, b, sk, 9));
}
