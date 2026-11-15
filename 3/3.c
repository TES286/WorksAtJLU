/*
题目编号 ：Exp03-Basic03

题目名称：多边形周长

题目描述：编写程序，求由键盘按顺时针方向输入n（0<n<=10)个顶点坐标的多边形周长（测试数据已保证当n>2时，各点按输入方向依次连接可构成封闭的n边形）。



输入：第一行输入一个非负整数，作为n值（0<n<=10)；以后每行两个浮点数（double），为多边形各顶点的坐标。

输出：多边形的周长，精确到小数点后2位。当n==1时，输出0.00；当n==2时，输出两点之间的距离。


样例1：

输入：
4
0  0
0  1
1  1
1  0
输出：4.00
样例2：

输入：
1
2 3
输出：
0.00
样例3：

输入：
2
2 3
2 4
输出：
1.00
*/

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