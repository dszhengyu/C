#include "error.h"

void err_sys(const char *msg)
{
    err_msg(msg);
    exit(-1);
}


void err_msg(const char *msg)
{
    printf("%s\n", msg);
}
