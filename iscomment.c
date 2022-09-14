#include <stdbool.h>
#include "iscomment.h"

bool is_comment(const char *s)
{
    for (const char *p=s; *p; p++)
        if (*p == '#')
            return true;
    return false;
}