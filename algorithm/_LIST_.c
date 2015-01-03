#include <stdio.h>
#include <malloc.h>
#define ElementType int
#include "_LIST_H.h"

struct Node
{
	ElementType Element;
	Position Next;
};

int IsEmpty(List L)
{
	return L->Next == NULL;
}

int IsLast(Position P, List L)
{
	return P->Next == NULL;
}

Position Find(ElementType X, List L)
{
	Position P;
	
	P = L->Next;
	while (P != NULL && P->Element != X)
		P = P->Next;

	return P;
}
 //return the prrevious node or NULL is it is not exist
Position FindPrevious(ElementType X, List L) 
{
	Position P;

	P = L;
	
	while (P->Next != NULL && P->Next->Element != X)
		P = P->Next;

	P = (P->Next->Element == X) ? P : NULL;

	return P;
}

void Delete(ElementType X, List L)
{
	Position P, temp;

	P = FindPrevious(X, L);
	
	if (P != NULL) {
		temp = P->Next;
		P->Next = temp->Next;
		free(temp);
	}
}

void Insert(ElementType X, List L, Position P)
{
	Position temp;

	temp = (Position)malloc(sizeof(struct Node));

	if (temp == NULL) {
		printf("out of space!");
		return;
	}
	temp->Element = X;
	temp->Next = P->Next;
	P->Next = temp;

}

//delete the list but keep the head point
void DeleteList(List L)
{
	Position P, temp;

	P = L->Next;
	L->Next = NULL;

	while (P != NULL) {
		temp = P->Next;
		free(P);
		P = temp;
	}
}

//exercise, pint a list
void printList(List L)
{
	Position P;

	P = L->Next;
	while (P != NULL) {
		printf("%d\t", P->Element);	
		P = P->Next;
	}
	putchar('\n');
}

//exercise 3.2
void PrintLots(List L, List P)
{
	int i;
	Position X, Y;

	X = L->Next;
	Y = P->Next;
	for (i = 0; X != NULL && Y != NULL; i++, X = X-> Next) {
		if (i < Y->Element) {
			continue;
		}
		else {
			printf("%d\t%d\n", i, X->Element);
			Y = Y->Next;
		}
	}
}

//exec 3.3.a
void swapNode(List L, Position P1, Position P2)
{
	Position tmp;
	
	tmp = FindPrevious(P1->Element, L);
	tmp->Next = P2;
	P1->Next = P2->Next;
	P2->Next = P1;
}

//exec 3.4
List andList(List L1, List L2)
{
	List L = malloc(sizeof(List));
	L->Next = NULL;

	L1 = L1->Next;
	L2 = L2->Next;
	while (L1 != NULL && L2 != NULL) {
		ElementType a, b;

		a = L1->Element;
		b = L2->Element;

		if (a > b) 
			L2 = L2->Next;
		else if (a < b)
			L1 = L1->Next;
		else {
			Insert(a, L, last(L));
			printf("%d\n", a);
			L1 = L1->Next;
			L2 = L2->Next;
		}

	}
	return L;
}

Position last(List L)
{
	while (L->Next != NULL)
		L = L->Next;
	return L;
}

//exec 3.5
List orList(List L1, List L2)
{
	List L = createList();

	if (L == NULL) {
		printf("out of space");
		return;
	}

	L1 = L1->Next;
	L2 = L2->Next;
	while (L1 != NULL && L2 != NULL) {
		ElementType a, b;
		a = L1->Element;
		b = L2->Element;

		if (a > b) {
			Insert(b, L, last(L));
			L2 = L2->Next;
		}
		else if (a < b) {
			Insert(a, L, last(L));
			L1 = L1->Next;
		}
		else {
			Insert(a, L, last(L));
			L1 = L1->Next;
			L2 = L2->Next;
		}
	}
	
	while (L1 != NULL) {
		Insert(L1->Element, L, last(L));
		L1 = L1->Next;
	}
	while(L2 != NULL) {
		Insert(L2->Element, L, last(L));
		L2 = L2->Next;
	}
	return L;
}

List createList(void)
{
	List L = malloc(sizeof(L));

	if (L != NULL) {
		L->next = NULL;
	}

	return L;
}

