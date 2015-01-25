#ifndef _Tree_H_
#define _Tree_H_

#include <stdio.h>
#include "error.h"
#include <malloc.h>
#define ElementType int
#include "_LIST_H.h"

struct TreeNode;
typedef struct TreeNode *treePosition;
typedef struct TreeNode *SearchTree;

struct TreeNode
{
	ElementType Element;
	treePosition Left;
	treePosition Right;
};

SearchTree makeTreeEmpty(SearchTree T);
treePosition findTree(ElementType X, SearchTree T);
treePosition findTreeMin(SearchTree T);
treePosition findTreeMax(SearchTree T);
SearchTree insertTreeNode(ElementType X, SearchTree T);
SearchTree deleteTreeNode(ElementType X, SearchTree T);
ElementType Retrive(treePosition P);
void printTree(SearchTree T);
void printTreeByLevel(SearchTree T);

#endif

