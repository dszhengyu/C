#include <stdio.h>
#include <malloc.h>
#define ElementType int
#include "_LIST_H.h"

struct Node
{
	ElementType Coefficient;
	ElementType Exponent;
	PtrToNode Next;
};

List createList(void)
{
	List L = malloc(sizeof(L));

	if (L != NULL) {
		L->Next = NULL;
	}

	return L;
}

void insertPoly(ElementType Coefficient, ElementType Exponent, List L)
{
	Position tmp = malloc(sizeof(Position));

	if (tmp == NULL) {
		printf("out of space");
		return;
	}

	tmp->Coefficient = Coefficient;
	tmp->Exponent = Exponent;
	tmp->Next = NULL;
	last(L)->Next = tmp;
}

Position last(List L)
{
	while (L->Next != NULL)
		L = L->Next;
	return L;
}

//exec 3.6
//the exponent of list goes from high to down
List addList(List L1, List L2)
{
	List L = createList();
	List L22; 
	
	if (L == NULL) {
		printf("out of space");
		return;
	}

	L1 = L1->Next;
	L2 = L2->Next;
	L22 = L2;
	while (L1 != NULL) {
		L2 = L22;
		while(L2 != NULL) {
			if (L1->Exponent == L2->Exponent) {
				insertPoly(L1->Coefficient + L2->Coefficient, L1->Exponent, L); 
				break;
			}
			else
				L2 = L2->Next;
		}

		if (L2 == NULL)
			insertPoly(L1->Coefficient, L1->Exponent, L);

		L1 = L1->Next;
	}

	return L;
}

void printList(List L)
{
	L = L->Next;
	while(L != NULL) {
		printf("coef = %d, exp = %d\t|", L->Coefficient, L->Exponent);
		L = L->Next;
	}
	putchar('\n');
	return;
}
