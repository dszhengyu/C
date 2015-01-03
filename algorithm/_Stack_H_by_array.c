#include <stdio.h>
#define ElementType int
#include "_Stack_H_by_array.h"
#include <malloc.h>
#define EmptyTOS (-1)
#define MinStackSize (5)

struct StackRecord
{
	int Capacity;
	int TopOfStack;
	ElementType *Array;
};

Stack CreateStack(int MaxElements)
{
	Stack S;

	if (MaxElements < MinStackSize) {
		printf("Stack Size Too Small");
		return NULL;
	}

	S = (Stack)malloc(sizeof(struct StackRecord));
	if (S == NULL) {
		printf("out of space!");
		return NULL;
	}

	S->Array = (ElementType *)malloc(sizeof(ElementType) * MaxElements);
	if (S->Array == NULL) {
		printf("out of space!");
		return NULL;
	}

	S->Capacity = MaxElements;
	MakeEmpty(S);

	return S;
}

void DisposeStack(Stack S)
{
	if (S != NULL) {
		free(S->Array);
		free(S);
	}
}

int IsEmpty(Stack S)
{
	return S->TopOfStack == EmptyTOS;
}

void MakeEmpty(Stack S)
{
	S->TopOfStack = EmptyTOS;
}

void Push(ElementType X, Stack S)
{
	if (IsFull(S))
		printf("out of space!");
	else
		S->Array[++S->TopOfStack] = X;
}

ElementType Top(Stack S)
{
	if (IsEmpty(S)) {
		printf("stack empty!");
		return -1;
	}
	else
		return S->Array[S->TopOfStack];
}

void Pop(Stack S)
{
	if (IsEmpty(S))
		printf("stack empty");
	else
		--S->TopOfStack;
}

