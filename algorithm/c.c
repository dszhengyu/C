#include <stdio.h>
#define ElementType int
#include "LazyList.h"
#include <malloc.h>


struct Head
{
	int real;
	int fake;
	Node next;
};

struct Node
{
	ElementType element;
	int deleted;
	Node next;
};

int main(void)
{
	List L = createList();
	insertNodeToHead(L, 1);
	insertNodeToHead(L, 2);
	insertNodeToHead(L, 3);
	insertNodeToHead(L, 4);
	insertNodeToHead(L, 5);
	insertNodeToHead(L, 6);
	printList(L);
	putchar('\n');
	deleteNodeLazy(L, L->next);
	deleteNodeLazy(L, L->next->next);
	printList(L);
	putchar('\n');
	deleteNodeLazy(L, L->next->next->next);
	printList(L);
	putchar('\n');
	deleteNodeLazy(L, L->next);
	printList(L);
	putchar('\n');
	return 0;
}
