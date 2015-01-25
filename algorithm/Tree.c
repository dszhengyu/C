#include "Tree.h"

SearchTree makeTreeEmpty(SearchTree T)
{
	if (T != NULL) {
		makeTreeEmpty(T->Left);
		makeTreeEmpty(T->Right);
		free(T);
	}
	return NULL;
}

treePosition findTree(ElementType X, SearchTree T)
{
	if (T == NULL) {
		printf("Not in Tree");
		return NULL;
	}
	
	if (X < T->Element)
		return findTree(X, T->Left);
	else if (X < T->Element)
		return findTree(X, T->Right);
	else
		return T;
}

treePosition findTreeMin(SearchTree T)
{
	while (T->Left != NULL)
		T = T->Left;
	return T;
}

treePosition findTreeMax(SearchTree T)
{
	if (T == NULL)
		return NULL;
	if (T->Right != NULL)
		return findTreeMax(T->Right);
	else
		return T;
}

SearchTree insertTreeNode(ElementType X, SearchTree T)
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
			T->Left = insertTreeNode(X, T->Left);
		else if (X > T->Element)
			T->Right = insertTreeNode(X, T->Right);
	}

	return T;
}

SearchTree deleteTreeNode(ElementType X, SearchTree T)
{
	treePosition tmp;

	if (T == NULL)
		err_sys("Out of Space");
	else if (X < T->Element)
		T->Left = deleteTreeNode(X, T->Left);
	else if (X > T->Element)
		T->Right = deleteTreeNode(X, T->Right);
	else
		if (T->Left && T->Right) {
			tmp = findTreeMin(T);
			T->Element = tmp->Element;
			T->Right = deleteTreeNode(T->Element, T->Right);
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

ElementType Retrive(treePosition P);

void printTree(SearchTree T)
{
	if (T != NULL) {
		printf("%d\t", T->Element);
		printTree(T->Left);
		printTree(T->Right);
	}
}

static List *initListArray(int MAXLEVEL)
{
	List *listArray = malloc(sizeof(List) * MAXLEVEL);
	int i;

	if (listArray == NULL)
		err_sys("Out of Space!");

	for (i = 0; i <	MAXLEVEL; i++)
		listArray[i] = NULL;

	return listArray;
}

static void fillListArray(SearchTree T, List *listArray)
{
	static int level = -1;
	++level;
	int tmp = level;
	
	if (T == NULL)
		return;
	if (listArray[level] == NULL)
		listArray[level] = createList();
	
	Insert(T->Element, listArray[level], listArray[level]);
	fillListArray(T->Left, listArray);
	level = tmp;
	fillListArray(T->Right, listArray);
	level = ++tmp;
}

void printTreeByLevel(SearchTree T)
{
	List *array = initListArray(100);

	fillListArray(T, array);
	
	List *tmp = array;

	while (*tmp != NULL) {
		Position P = (*tmp)->Next;
		while (P != NULL) {
			printf("%d\t", P->Element);
			P = P->Next;
		}
		DeleteList(*tmp);
		++tmp;
		putchar('\n');
	}

	free(array);
}
