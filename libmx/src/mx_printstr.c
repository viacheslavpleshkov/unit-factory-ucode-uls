#include "libmx.h"

void mx_printstr(const char *s) {
    if (!s)
        write(1, "(null)", 6);
    else
        write(1, s, mx_strlen(s));
}
