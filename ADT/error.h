#ifndef ERROR_H
#define ERROR_H

#include <stdio.h>
#include <stdlib.h>

#define	MAXLINE	4096

void	err_msg(const char *msg);
void	err_sys(const char *msg);

#endif
