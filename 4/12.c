/*
题目编号 ：Exp04-Enhance03，freshman-1006

题目名称：英文翻译自然数

题目描述：按常规英文输出1000以内自然数的英文读法。


输入：每个测试输入包含 1 个测试用例，给出正整数 n（0<= n <1000）

输出：输出占一行：如果 0<= n <1000, 用规定的格式输出 n，所有英文单词小写，最后一个单词后无字符；否则输出ERR。


样例1：

输入：41
输出：forty-one
样例2：

输入：123
输出：one hundred and twenty-three
*/

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    if (n < 0 || n >= 1000) {
        printf("ERR\n");
        return 0;
    }
    const char *one2nineteen[] = {
        "zero", "one", "two", "three", "four",
        "five", "six", "seven", "eight", "nine",
        "ten", "eleven", "twelve", "thirteen", "fourteen",
        "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"
    };
    const char *tens[] = {
        "", "", "twenty", "thirty", "forty",
        "fifty", "sixty", "seventy", "eighty", "ninety"
    };
    if (n < 20) {
        printf("%s\n", one2nineteen[n]);
        return 0;
    }
    if (n < 100) {
        int t = n / 10;
        int r = n % 10;

        printf("%s", tens[t]);
        if (r != 0) {
            printf("-%s", one2nineteen[r]);
        }
        printf("\n");
        return 0;
    }
    int hundred = n / 100;
    int rst = n % 100;
    printf("%s hundred", one2nineteen[hundred]);
    if (rst != 0) {
        printf(" and ");
        if (rst < 20) {
            printf("%s", one2nineteen[rst]);
        } else {
            int t = rst / 10;
            int r = rst % 10;
            printf("%s", tens[t]);
            if (r != 0) {
                printf("-%s", one2nineteen[r]);
            }
        }
    }
}