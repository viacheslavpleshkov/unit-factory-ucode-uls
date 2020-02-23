#include "uls.h"

int mx_ls_get_terminal_width(void) {
    struct winsize term;
    
    ioctl(0, TIOCGWINSZ, &term);
    if (isatty(1) != 0)
        return term.ws_col;
    return 79;
}
