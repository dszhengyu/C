#include <stdio.h>
#define ElementType int
#include "_Cursor_H.h"
#define N 10	//the legth of array

struct Node
{
	ElementType Element;
	Position Next;
};

struct Node CursorSpace[N];

static  Position CursorAlloc(void)
{
	Position P;

	P = CursorSpace[0].Next;
	CursorSpace[0].Next = CursorSpace[P].Next;

	return P;
}

static void CursorFree(Position P)
{
	CursorSpace[P].Next = CursorSpace[0].Next;
	CursorSpace[0].Next = P;
}

int IsEmpty(const List L)
{
	return (CursorSpace[L].Next == 0);
}

int IsLast(const Position P, const List L)
{
	return CursorSpace[P].Element == 0;
}

//return position x in list, or 0 if not found
Position Find(ElementType X, const List L)
{
	Position P;

	P = CursorSpace[L].Next;
	while (P != 0 && CursorSpace[P].Element != X)
		P = CursorSpace[P].Next;

	return P;
}

//delete the first x in list
void Delete(ElementType X, List L)
{
	Position P, tmp;

	P = FindPrevious(X, L);

	if (!IsLast(P, L)) {
		tmp = CursorSpace[P].Next;
		CursorSpace[P].Next = CursorSpace[tmp].Next;
		CursorFree(tmp);
	}
}
//insert after P
void Insert(ElementType X, List L, Position P)
{
	Position tmp;

	if ((tmp = CursorAlloc()) == 0) 
		printf("out of space!");

	CursorSpace[tmp].Element = X;
	CursorSpace[tmp].Next = CursorSpace[P].Next;
	CursorSpace[P].Next = tmp;
}

//exec 3.15
Position findAdj(ElememntType x, List L)
{
	Position P = L;

	while (P->Next && P->Next->Element != x) {
		P = P->Next;
	}

	if (P->Next) {
		Position tmp = P->Next;
		P->Next = P->Next->Next;
		tmp->Next = L->Next;
		L->Next = tmp
			return tmp;
	}
	else P->Next;
}
