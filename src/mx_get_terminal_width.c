#include "uls.h"

int mx_get_terminal_width() {
    struct winsize term;

    ioctl(0, TIOCGWINSZ, &term);
    return term.ws_col;
}
