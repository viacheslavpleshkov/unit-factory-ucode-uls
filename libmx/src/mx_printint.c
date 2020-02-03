#include "libmx.h"

void mx_printint(int n) {
    int len = 0;
    int del = 1;
    int sign = 1;

    if (n == 0) {
        mx_printchar('0');
        return;
    }
    for (int i = n; i != 0; i /= 10, len++) 
        if (i != n) 
            del *= 10;
    if (n < 0) {
        sign = -1;
        mx_printchar('-');
    }
    for (int i = 0; i < len; i++) {
        mx_printchar((n / del) * sign + '0');
        n %= del;
        del /= 10;
    }
}
