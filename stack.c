#include <stdio.h>
#define MAXVAL 100
#include "cal.h"

int sp = 0;
double val[MAXVAL];

void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("ERROR: STACK OVERFLOW\n");
}

double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("ERROR: NOTHING TO POP\n");
	    return -1;
	}
}