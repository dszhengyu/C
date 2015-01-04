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
	Insert(3, L, last(L));
	printList(L);
	findInSelfAdj(3, L);
	printList(L);
	return 0;
}
