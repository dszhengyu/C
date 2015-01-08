#include <stdio.h>
#define ElementType int
#include "_Queue_H.h"
#include <malloc.h>


struct QueueRecord
{
	Node Front;
	Node Rear;
};

struct QueueNode
{
	ElementType Element;
	Node Next;
};

int IsEmpy(Queue Q)
{
	return Q->Front == NULL && Q->Rear == NULL;
}

Queue CreateListQueue()
{
	Queue Q = malloc(sizeof(struct QueueRecord));
	if (Q == NULL) {
		printf("Out Of Space");
		return NULL;
	}
	else {
		Q->Front = NULL;
		Q->Rear = NULL;
		return Q;
	}

}

void DisposeQueue(Queue Q)
{
	if (Q == NULL)
		return;

	MakeEmpty(Q);
	free(Q);
}

void MakeEmpty(Queue Q)
{
	if (Q == NULL)
		return;

	Node tmp = Q->Front;
	while (tmp != NULL) {
		Q->Front = Q->Front->Next;
		free(tmp);
		tmp = Q->Front;
	}
	Q->Rear = NULL;
}

void Enqueue(ElementType X, Queue Q)
{
	Node n = malloc(sizeof(struct QueueRecord));
	if (n == NULL) {
		printf("Out of Space!");
		return;
	}

	n->Element = X;
	n->Next = NULL;

	if (IsEmpy(Q)) {
		Q->Front = Q->Rear = n;
	}
	else {
		Q->Rear->Next = n;
		Q->Rear = n;
	}

}

ElementType Front(Queue Q)
{
	return Q->Front->Element;
}

void Dequeue(Queue Q)
{
	Node tmp = Q->Front;
	Q->Front = tmp->Next;
	free(tmp);
}

ElementType FrontAndDequeue(Queue Q)
{
	if (IsEmpy(Q))
		return -1;

	Node tmp = Q->Front;
	ElementType x = tmp->Element;
	Q->Front = tmp->Next;
	if (Q->Front == NULL)
		Q->Rear = NULL;
	free(tmp);
	return x;
}

void printQueue(Queue Q)
{
	Node n = Q->Front;
	
	while (n != NULL) {
		printf("%d\t", n->Element);
		n = n->Next;
	}
}
