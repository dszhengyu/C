#include <stdio.h>
#include "AvlTree.h"

int main(void)
{
	AvlTree T = insertNoRecursive(10, NULL);
	insertNoRecursive(2, T);
	insertNoRecursive(20, T);
	insertNoRecursive(1, T);
	insertNoRecursive(0, T);
	insertNoRecursive(30, T);
	insertNoRecursive(25, T);

	printTree(T);
	return 0;
	insertNoRecursive(25, T);

	printTree(T);
	return 0;
}
