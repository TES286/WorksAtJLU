/*
【计2014级期中试题】素数判断。

问题描述：一个大于1的自然数，只能被1和它本身整除，不能被其它除0以外的自然数整除，则该数称之为素数。编写函数，判断一个整数是否为素数。

注：判断素数部分必须编写成一个独立于main()函数的其它函数。

输入：一个大于1的自然数

输出：根据是否是素数输出Y/N



样例1：

输入：3

输出：Y

样例2：

输入：51

输出：N


*/

#include <stdio.h>

char is_prime(unsigned long long x) {
  for (unsigned long long i = 2; i < x / 2 + 1; i++) {
    if (x % i == 0) {
      return 0;
    }
  }
  return 1;
}

int main() {
  unsigned long long n;
  scanf("%lld", &n);
  if (is_prime(n)) {
    printf("Y");
  } else {
    printf("N");
  }
}
