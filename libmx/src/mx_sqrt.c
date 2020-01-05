#include "libmx.h"

int mx_sqrt(int x) {
    int result = 1;

    if (x >= 1000000)
        result = 1000;
    if (x >= 1000000000)
        result = 31662;
    if (x >= 2000000000)
        result = 44721;
    if (x <= 0)
        return 0;
    while(result * result < x) {
        if (result > 46340)
            return 0;
        result++;
    }
    if (result * result == x)
        return result;
    else
        return 0;
}
