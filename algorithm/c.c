#include <stdio.h>
#include "Tree.h"

int main(void)
{
	SearchTree T = Insert(123, NULL);
	Insert(11, T);
	Insert(443, T);
	Insert(43, T);
	Insert(743, T);
	Insert(943, T);
	Insert(043, T);
	Insert(143, T);

	printTree(T);
	return 0;
}
