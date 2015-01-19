#include "Tree.h"

struct TreeNode
{
	ElementType Element;
	Position Left;
	Position Right;
};


SearchTree MakeEmpty(SearchTree T)
{
	if (T != NULL) {
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);
	}
	return NULL;
}

Position Find(ElementType X, SearchTree T)
{
	if (T == NULL) {
		printf("Not in Tree");
		return NULL;
	}
	
	if (X < T->Element)
		return Find(X, T->Left);
	else if (X < T->Element)
		return Find(X, T->Right);
	else
		return T;
}

Position FindMin(SearchTree T)
{
	while (T->Left != NULL)
		T = T->Left;
	return T;
}

Position FindMax(SearchTree T)
{
	if (T == NULL)
		return NULL;
	if (T->Right != NULL)
		return FindMax(T->Right);
	else
		return T;
}

SearchTree Insert(ElementType X, SearchTree T)
{
	if (T == NULL) {
		T = malloc(sizeof(struct TreeNode));
		if (T == NULL) {
			printf("Out of Space");
			return NULL;
		}
		else {
			T->Element = X;
			T->Left = T->Right = NULL;
		}
	}
	else {
		if (X < T->Element)
			T->Left = Insert(X, T->Left);
		else if (X > T->Element)
			T->Right = Insert(X, T->Right);
	}

	return T;
}

SearchTree Delete(ElementType X, SearchTree T)
{
	Position tmp;

	if (T == NULL)
		err_sys("Out of Space");
	else if (X < T->Element)
		T->Left = Delete(X, T->Left);
	else if (X > T->Element)
		T->Right = Delete(X, T->Right);
	else
		if (T->Left && T->Right) {
			tmp = FindMin(T);
			T->Element = tmp->Element;
			T->Right = Delete(T->Element, T->Right);
		}
		else {
			tmp = T;
			if (T->Left == NULL)
				T = T->Right;
			else if (T->Right == NULL)
				T = T->Left;
			free(tmp);
		}
	return T;
}

ElementType Retrive(Position P);

void printTree(SearchTree T)
{
	if (T != NULL) {
		printf("%d\t", T->Element);
		printTree(T->Left);
		printTree(T->Right);
	}
}
