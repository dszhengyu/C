#include <stdio.h>
#include <malloc.h>
#define ElementType int
#include "_LIST_H.h"

struct Node
{
	ElementType Element;
	Position Next;
};

int main()
{
	return 0;
}

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

	if (temp == NULL)
		printf("out of space!");

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