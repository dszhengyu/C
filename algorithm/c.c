#include <stdio.h>
#include "Tree.h"
#include "_LIST_H.h"

int main(void)
{
	SearchTree T = insertTreeNode(123, NULL);
	insertTreeNode(11, T);
	insertTreeNode(443, T);
	insertTreeNode(4, T);
	insertTreeNode(743, T);
	insertTreeNode(943, T);
	insertTreeNode(43, T);
	insertTreeNode(143, T);

	printTree(T);
	putchar('\n');
	printTreeByLevel(T);
	return 0;
}
