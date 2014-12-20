#include <stdio.h>
#include <malloc.h>
#define ElementType int
#include "_Queue_H_by_array.h"
#define MinQueueSize (5)

struct QueueRecord
{
	int Capacity;
	int Front;
	int Rear;
	int Size;
	ElementType *Array;
};

int IsEmpty(Queue Q)
{
	return Q->Size == 0;
}

void MakeEmpty(Queue Q)
{
	Q->Size = 0;
	Q->Front = 1;
	Q->Rear = 0;
}

static int Succ(int value, Queue Q)
{
	if (++value == Q->Capacity)
		value = 0;
	return value;
}

void Enqueue(ElementType X, Queue Q)
{
	if (IsFull(Q))
		printf("out of space!");
	else {
		Q->Size++;
		Q->Rear = Succ(Q->Rear, Q);
		Q->Array[Q->Rear] = X;
	}
}