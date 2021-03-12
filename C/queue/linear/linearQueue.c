#include <stdio.h>
#include <stdlib.h>
#include "linearCommon.h"


void QueueInit(Que *pq)
{
	// front 인텍스와 rear 인덱스가 같은 위치부터 시작
	pq->front = 0;
	pq->rear = 0;
}


int IsEmpty(Que *pq) 
{
	if (pq->front == pq->rear)
		return TRUE;
	else
		return FALSE;
}

int NextPosIdx(int pos)
{
	// 투 포인터 사용
	// Enqueue => rear 인덱스 증가
	// Dequeue => front 인덱스 증가
	if (pos == QUE_LEN + 1)
		return 0; 
	else 
		return pos + 1;
}

void Enqueue(Que *pq, Data data) 
{
	if (NextPosIdx(pq->rear) == pq->front)
	{
		printf("Que Full!\n");
		exit(-1);
	}

	pq->rear = NextPosIdx(pq->rear);
	pq->queArr[pq->rear] = data;
}


Data Dequeue(Que *pq) 
{
	if (IsEmpty(pq))
	{
		printf("Que Empty!\n");
		exit(-1);
	}

	pq->front = NextPosIdx(pq->front);
	return pq->queArr[pq->front];
}

Data Peek(Que *pq) 
{
	if(IsEmpty(pq))
	{
		printf("Que Empty! Error!\n");
		exit(-1);
	}

	return pq->queArr[NextPosIdx(pq->front)];

}
