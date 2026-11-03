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