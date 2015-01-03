#include <stdio.h>
#define ElementType int
#include "_LIST_H.h"
#include <malloc.h>

struct Node
{
	ElementType Coefficient;
	ElementType Exponent;
	PtrToNode Next;
};

int main(void)
{
	List L = createList();
	insertPoly(10, 1000, L);
	insertPoly(5, 14, L);
	insertPoly(1, 0, L);
//	printList(L);

	List P = createList();
	insertPoly(3, 1990, P);
	insertPoly(-2, 1492, P);
	insertPoly(11, 1, P);
	insertPoly(5, 0, P);
//	printList(P);
//	printList(expPoly(L, 2));

	Interger a = toInterger("12345");
	Interger b = toInterger("912345");
	printList(a);
	printList(b);
	printInterger(a);
	putchar('\n');
	printInterger(b);
	putchar('\n');

	Interger x = toInterger("2");
	printInterger(expInterger(x, 4000));
	return 0;
}
