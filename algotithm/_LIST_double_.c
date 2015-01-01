#include <stdio.h>
#include <malloc.h>
#define ElementType int
#include "_LIST_H.h"

struct Node
{
	ElementType Element;
	Position Prev;
	Position Next;
};

void swapNode(List L, Position P1, Position P2)
{
	Position head, tail;

	head = P1->Prev;
	tail = P2->Next;

	head->Next = P2;
	P2->Next = head;
	P1->Next = tail;
	tail->Prev = P1;
	P1->Prev = P2;
	P2->Next = P1;
}

int main()
{	
	return 0;
}
