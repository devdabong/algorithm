#include <stdio.h>
#include <stdlib.h>
#include "arrayCommon.h"



void stackInit(Stack *pstack)
{
	pstack->topIndex = -1;
}

int isEmpty(Stack *pstack)
{
	if (pstack -> topIndex == -1)
		return TRUE;
	else
		return FALSE;
}

void push(Stack *pstack, Data data)
{
	pstack -> topIndex += 1;
	pstack -> stackArr[pstack->topIndex] = data;

	printf("topIndex [%d] , push [%d]\n", pstack->topIndex, pstack -> stackArr[pstack->topIndex]);
}

Data pop(Stack *pstack)
{
	int ridx;

	if (isEmpty(pstack))
	{
		printf("Stack Memory Error!");
		exit(-1);
	}

	ridx = pstack -> topIndex;
	pstack -> topIndex -= 1;

	return pstack -> stackArr[ridx];
}	

Data peek(Stack *pstack)
{
	if(isEmpty(pstack))
	{
		printf("Stack Memory Error!");
		exit(-1);
	}

	return pstack -> stackArr[pstack->topIndex];
}

