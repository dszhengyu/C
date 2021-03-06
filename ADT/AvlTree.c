#include "AvlTree.h"

static int Height(Position P)
{
	if (P == NULL)
		return -1;
	else
		return P->Height;
}

AvlTree Insert(AvlTreeElementType X, AvlTree T)
{
	if (T == NULL) {
		T == malloc(sizeof(struct AvlNode));
		if (T == NULL)
            err_sys("Out of Space");
		else {
			T->Element = X;
			T->Left = T->Right = NULL;
			T->Height = 0;
		}
	}
	else {
		if (X < T->Element) {
			T->Left = Insert(X, T->Left);
			if (Height(T->Left) - Height(T->Right) == 2)
				if (X < T->Left->Element)
					T = SingleRotateWithLeft(T);
				else
					T = DoubleRotateWithLeft(T);
		}
		else if (X > T->Element) {
			T->Right = Insert(X, T->Right);
			if (Height(T->Right) - Height(T->Left) == 2)
				if (X > T->Right->Element)
					T = SingleRotateWithRight(T);
				else
					T = DoubleRotateWithRight(T);
		}
	}

	T->Height = Max(Height(T->Left), Height(T->Right)) + 1;
	return T;
}

static Position SingleRotateWithLeft(Position K2)
{
	Position K1;

	K1 = K2->Left;
	K2->Left = K1->Right;
	K1->Right = K2;

	K2->Height = Max(Height(K2->Left), Height(K2->Right)) + 1;
	K1->Height = Max(Height(K1->Left), Height(K1->Right)) + 1;

	return K1;
}

static Position SingleRotateWithRight(Position K2)
{
	Position K1;

	K1 = K2->Right;
	K2->Right = K1->Left;
	K1->Left = K2;

	K2->Height = Max(Height(K2->Left), Height(K2->Right)) + 1;
	K1->Height = Max(Height(K1->Left), Height(K1->Right)) + 1;

	return K1;
}

static Position DoubleRotateWithLeft(Position K3)
{
	K3->Left = SingleRotateWithRight(K3->Left);

	return SingleRotateWithLeft(K3);
}	

static Position DoubleRotateWithRight(Position K3)
{
	K3->Right = SingleRotateWithLeft(K3->Right);

	return SingleRotateWithRight(K3);
}

AvlTree insertNoRecursive(AvlTreeElementType X, AvlTree T)
{
	//new tree
	if (T == NULL) {
		T = malloc(sizeof(struct AvlNode));

		if (T == NULL)
            err_sys("Out of Space!");
		T->Element = X;
		T->Left = T->Right = NULL;
		return T;
	}

	Stack S = CreateStack();

	while (T != NULL) {
		Push(T, S);
		if (X < T->Element) {
			T = T->Left;
		}
		else  if (X > T->Element) {
			T = T->Right;
		}
	}

	T = Top(S);
	Position *tmp;
	if (X < T->Element) {
		tmp = &(T->Left);
	}
	else {
		tmp = &(T->Right);
	}
	*tmp = malloc(sizeof(struct AvlNode));
	if (*tmp == NULL)
		err_sys("Out of Space!");

	T = *tmp;
	T->Left = T->Right = NULL;
	T->Element = X;
	T->Height = 0;

	AvlTree cur = NULL;
	while (!IsEmpty(S)) {
		cur = Top(S);
		Pop(S);
		if (X < cur->Element)
			cur->Left = T;
		else if (X > cur->Element)
			cur->Right = T;

		T = cur;
		if (Height(T->Left) - Height(T->Right) == 2) {
			if (X < T->Left->Element)
				T = SingleRotateWithLeft(T);
			else
				T = DoubleRotateWithLeft(T);
		}
		else if (Height(T->Right) - Height(T->Left) == 2) {
			if (X > T->Right->Element)
				T = SingleRotateWithRight(T);
			else
				T = DoubleRotateWithRight(T);
		}
		T->Height = Max(Height(T->Left), Height(T->Right)) + 1;
	}
	DisposeStack(S);
}

void printTree(AvlTree T)
{
	if (T != NULL) {
		printTree(T->Left);
		printf("Element = %d\tHeight = %d\n", T->Element, T->Height);
		printTree(T->Right);
	}
}
