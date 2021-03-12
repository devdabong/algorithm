#include <stdio.h>
#include <stdlib.h>
#include "circularCommon.h"


void QueueInit(Que *pq)
{
	// front 인텍스와 rear 인덱스가 같은 위치부터 시작
	pq->front = 0;
	pq->rear = 0;
}


// Linear Que :  인덱스 + 1 ==> 인덱스가 계속 늘어나서 메모리를 잡아먹음.
// Circular Que : (인덱스 + 1) % 큐 사이즈 ==> 나머지로 인덱스를 0부터  유지함.
int IsEmpty(Que *pq) 
{
	if ((pq->front + 1) % QUE_LEN  == (pq->rear + 1) % QUE_LEN)
		return TRUE;
	else
		return FALSE;
}

int IsFull(Que *pq)
{
	if ((pq->rear + 1) % QUE_LEN == pq->front)
		return TRUE;
	else
		return FALSE;
}	

void Enqueue(Que *pq, Data data) 
{
	if (IsFull(pq))
	{
		printf("Que Full!\n");	
		exit(-1);
	}

    pq->rear = (pq->rear + 1) % QUE_LEN;
	pq->queArr[pq->rear] = data;
}


Data Dequeue(Que *pq) 
{
	if (IsEmpty(pq))
	{
		printf("Que Empty!\n");
		exit(-1);
	}

    pq->front = (pq->front + 1) % QUE_LEN;

	return pq->queArr[pq->front];
}

Data Peek(Que *pq) 
{
	if(IsEmpty(pq))
	{
		printf("Que Empty! Error!\n");
		exit(-1);
	}

	return pq->queArr[pq->front];
}
