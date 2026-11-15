/*
表达式计算。

问题描述：编程序，输入两个浮点数a和x，计算并输出如下表达式的值：

y=\frac{\sin x}{ax} + \left| \cos \frac{\pi x}{2} \right|

其中a,x,y均采用float类型，取值为3.1415926。输出结果要求保留小数点后3位。

提示：使用数学函数应括入math.h头文件，正弦、余弦和求绝对值对应的数学函数名分别为sin，cos和fabs。注意区分C语言表达式与数学表达式的差别哦。



输入：依次输入两个浮点数作为a和x的值

输出:  y的值



样例1：

输入：3.1 40

输出：1.006



样例2：

输入：1.6 21

输出：0.025



样例3：

输入：-4.2 40

输出：0.996


*/

#include <math.h>
#include <stdio.h>

int main() {
  float a, x;
  scanf("%f %f", &a, &x);
  float y = sin(x) / (a * x) + fabs(cos(3.1415926 / 2 * x));
  printf("%.3f\n", y);
}