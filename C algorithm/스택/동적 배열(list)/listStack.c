#include <stdio.h>
#include <stdlib.h>
#include "listCommon.h"

void StackInit(Stack *pstack) 
{
	//NULL , 0x00, '\n'
	pstack -> head = 0x00;
}

int	IsEmpty(Stack *pstack) 
{
	if (pstack -> head == 0x00)
		return TRUE;
	else
		return FALSE;
}

// data 넣기
void Push(Stack *pstack, Data data) 
{
	Node *newNode = (Node *)malloc(sizeof(Node));

	newNode->data = data;
	newNode->next = pstack->head;

	pstack->head = newNode;
}

// topData 꺼내기
Data Pop(Stack *pstack) 
{
	Data topData;
	Node *rnode;

	if (IsEmpty(pstack))
	{
		printf("Stack Memory Error!");
		exit(-1);
	}	
	
	topData = pstack->head->data;
	rnode = pstack->head;

	pstack->head = pstack->head->next;
	free(rnode);

	return topData;
}

// topData 읽기
Data Peek(Stack *pstack) 
{
	if (IsEmpty(pstack))
	{
		printf("Stack Memory Error!");
		exit(-1);
	}

	return pstack->head->data;
}
