#include <stdio.h>
#include <stdlib.h>
#include "ArrayCommon.h"

#define TRUE		  1
#define FALSE		  0
#define STACK_LEN	100

typedef int Data;

typedef struct _arrayStack
{
	Data stackArr[STACK_LEN];
	int topIndex;
} ArrayStack;

typedef ArrayStack Stack;

void StackInit(Stack *pstack)
{
	pstack->topIndex = -1;
}

int isEmpty(Stack *pstack)
{
	if (pstack->topIndex == -1)
		return TRUE;
	else
		return FALSE;
}

void push(Stack *pstack, Data data)
{
	pstack->topIndex += 1;
	pstack->stackArr[pstack->topIndex] = data;
}

Data pop(Stack *pstack)
{
	int rIdx;
	
	if(isEmpty(pstack))
	{
		printf("stack memory Error!");
		exit(-1);
	}

	rIdx = pstack->topIndex;
	pstack->topIndex -= 1;

	return pstack->stackArr[rIdx];
}

Data peek(Stack *pstack)
{
	if(isEmpty(pstack))
	{
		printf("stack memory Error!");
		exit(-1);
	}

	return pstack->stackArr[pstack->topIndex];
}

int main()
{
	Stack stack;
	StackInit(&stack);

	push(&stack, 1);
	push(&stack, 2);
	push(&stack, 3);
	push(&stack, 4);
	push(&stack, 5);

	while(!isEmpty(&stack))
		printf("%d ", pop(&stack));

	printf("\n");
	return 0;
}	
