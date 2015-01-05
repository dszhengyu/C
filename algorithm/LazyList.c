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

List createList()
{
	List L = malloc(sizeof(struct Head));

	if (L ==NULL)
		printf("Out of Space!\n");

	return L;
}

void insertNodeToHead(List L, ElementType x)
{
	Node n = malloc(sizeof(struct Node));

	if (n == NULL) {
		printf("Out of Space!");
		return;
	}
	else {
		n->element = x;
		n->deleted = 0;
		n->next = L->next;
		L->next = n;
		L->real++;
	}
}

void deleteNodeLazy(List L, Node n)
{
	n->deleted = 1;
	L->real--;
	L->fake++;

	if (L->real == L->fake) {
		Node tmp, n;
		n = L->next;
		L->fake = 0;

		//make sure n is real node to take the next step
		while (n->deleted == 1) {
			L->next = n->next;
			free(n);
			n = L->next;
		}

		while (n->next != NULL) {
			if (n->next->deleted == 1) {
				tmp = n->next;
				n->next = tmp->next;
				free(tmp);
			}
			else
				n = n->next;
		}
	}
}

void printList(List L)
{
	Node n = L->next;
	while (n != NULL) {
//		if (n->deleted == 0)
			printf("%d\t", n->element);
		n = n->next;
	}
}
