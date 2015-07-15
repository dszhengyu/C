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

//exec 3.10
Grouper createGrouper(void)
{
	Grouper g = malloc(sizeof(struct Node));

	if (g == NULL) {
		printf("Out of Space");
		return NULL;
	}
	else {
		g->Element = 0;
		g->Prev = NULL;
		g->Next = NULL;
		return g;
	}
}

Group initGroup(int N)
{
	if (N < 1) {
		printf("nobody participate in\n");
		return NULL;
	}
	
	Group g;
	Grouper p, n;
	int no = 1;
	g = p = n = createGrouper();
	p->Element = no++;
	N--;

	while (--N >= 0) {
		n = createGrouper();
		if (n == NULL) 
			return;
		
		n->Element = no++;
		n->Prev = p;
		p->Next = n;
		p = n;
	}
	n->Next = g;
	g->Prev =  n;
	return g;
}

void freeGrouper(Grouper g)
{
	Grouper p, n;

	p = g->Prev;
	n = g->Next;
	p->Next = n;
	n->Prev = p;
	free(g);
}

void runGroup(int N, int M)
{
	Group g = initGroup(N);

	if (g == NULL)
		return;

	int cnt = M;
	while (g->Next != g) {
		cnt = M;
		while (cnt-- != 0)
			g = g->Next;
		g = g->Next;
		freeGrouper(g->Prev);
	}
	printf("the No.%d grouper left\n", g->Element);
}
