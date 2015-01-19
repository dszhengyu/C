#ifndef _Tree_H_
#define _Tree_H_

#include <stdio.h>
#include "error.h"
#include <malloc.h>
#define ElementType int

struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;

SearchTree MakeEmpty(SearchTree T);
Position Find(ElementType X, SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);
SearchTree Insert(ElementType X, SearchTree T);
SearchTree Delete(ElementType X, SearchTree T);
ElementType Retrive(Position P);
void printTree(SearchTree T);

#endif

