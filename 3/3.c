#include <math.h>
#include <stdio.h>
struct Point {
  double x;
  double y;
};
int main() {
  struct Point points[100];
  int n;
  double x, y;
  scanf("%d", &n);
  for (int i = n - 1; i >= 0; i--) {
    scanf("%lf %lf", &x, &y);
    points[i].x = x;
    points[i].y = y;
  }
  if (n == 1) {
    printf("0.00");
    return 0;
  }
  struct Point last = points[0];
  double rst = 0.0;
  for (int t = 1; t < n; t++) {
    rst += sqrt(pow(last.x - points[t].x, 2) + pow(last.y - points[t].y, 2));
    last = points[t];
  }
  if (n > 2) {
    rst += sqrt(pow(last.x - points[0].x, 2) + pow(last.y - points[0].y, 2));
  }
  printf("%.2lf", rst);
}