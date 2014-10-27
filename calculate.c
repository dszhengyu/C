#include <stdio.h>
#include <stdlib.h>
#include "cal.h"

#define MAXOP 100


int getop(char []);
void push(double);
double pop(void);

int main()
{
	int type;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
		switch (type) {
		case NUMBER: 
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2);
			else
				printf("ERROR! DIVISION ZERO\n");
			break;
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		default:
			printf("UNKNOW INPUT\n");
			break;
		}
	}
	return 0;
}