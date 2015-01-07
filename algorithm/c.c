#include <stdio.h>
#define ElementType int
#include "_Queue_H_by_array.h"
#include <malloc.h>


int main(void)
{
	Queue Q = CreateQueue(100);
	Enqueue(10, Q);
	Enqueue(130, Q);
	Enqueue(120, Q);
	Enqueue(310, Q);
	Enqueue(610, Q);
	Enqueue(810, Q);
	printQueue(Q);
	printf("\n%d\t", FrontAndDequeue(Q));
	printf("\n%d\t", FrontAndDequeue(Q));
	printf("\n%d\t", FrontAndDequeue(Q));
	printf("\n%d\t", FrontAndDequeue(Q));
	printf("\n%d\t", FrontAndDequeue(Q));
	printf("\n%d\t", FrontAndDequeue(Q));
	printf("\n%d\t", FrontAndDequeue(Q));
	printf("\n%d\t", FrontAndDequeue(Q));
	printf("\n%d\t", FrontAndDequeue(Q));
	printf("\n%d\t", FrontAndDequeue(Q));
	return 0;
}
