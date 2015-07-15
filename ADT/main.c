#include <stdio.h>
#include "_LIST_H.h"

int main(void)
{

    List L = (List)malloc(sizeof(List));
    L->Element = 0;
    L->Next = NULL;
    Insert(1, L, L);
    Insert(2, L, L);
    Insert(3, L, L);
    Insert(4, L, L);
    Insert(5, L, L);
    Insert(6, L, L);
    printList(L);
    reverseList2(L);
    printList(L);
//	AvlTree T = insertNoRecursive(10, NULL);
//	insertNoRecursive(2, T);
//	insertNoRecursive(20, T);
//	insertNoRecursive(1, T);
//	insertNoRecursive(0, T);
//	insertNoRecursive(30, T);
//	insertNoRecursive(25, T);

//	printTree(T);
	return 0;
}
