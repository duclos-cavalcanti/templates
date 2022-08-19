#include <stdio.h>

#include "utils.h"

void logError(const char *fmt, ...) {
    va_list valist;
    vfprintf(stderr, fmt, valist);
}
