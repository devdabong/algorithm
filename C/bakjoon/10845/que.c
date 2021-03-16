#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE			1
#define FALSE			0
#define MAX_SIZE	10000


typedef struct _que{
	int frontIdx;
	int backIdx;
	int arr[MAX_SIZE];
} Que;

typedef Que que;

void QueInit(Que *qp){
	qp->frontIdx = 0;
	qp->backIdx = 0;
}

int IsEmpty(Que *qp){
	if ((qp->backIdx + 1)%MAX_SIZE == (qp->frontIdx + 1)%MAX_SIZE)
	{
		return TRUE;
	}
	else 
	{	
		return FALSE;
	}
}

int IsFull(Que *qp){
	if ((qp->backIdx + 1) % MAX_SIZE == qp->frontIdx)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}	
}

void Push(Que *qp, int data){
	qp->backIdx = (qp->backIdx + 1) % MAX_SIZE;
	qp->arr[qp->backIdx] = data;
}

int Pop(Que *qp){
	if (IsEmpty(qp))
	{
		return -1;
	}
	else
	{
		qp->frontIdx = (qp->frontIdx + 1)%MAX_SIZE;

		return qp->arr[qp->frontIdx];
	}
}

int Size(Que *qp){
	return qp->backIdx - qp->frontIdx;
}

int getFront(Que *qp){
	if (IsEmpty(qp))
	{
		return -1;
	}	
	else
	{	
		return qp->arr[(qp->frontIdx + 1)%MAX_SIZE];
	}	
}

int getBack(Que *qp){
	if (IsEmpty(qp))
	{
		return -1;
	}
	else
	{
		return qp->arr[(qp->backIdx)%MAX_SIZE];
	}
}

int main()
{
	int i;
	char str[6];
	Que que;
	int n, num;

	printf("hi\n");
	scanf("%d", &n);

	 
	QueInit(&que);

	for(i=0; i<n; i++)
	{
		scanf("%s", str);
		 
		if (!strcmp(str, "push"))
		{
			scanf("%d", &num);
			 
			Push(&que, num);
		}
		else if (!strcmp(str, "pop"))
		{
			printf("%d\n", Pop(&que));
		}
		else if (!strcmp(str, "empty"))
		{
			printf("%d\n", IsEmpty(&que));
		}
		else if (!strcmp(str, "size"))
		{
			printf("%d\n", Size(&que));
		}
		else if (!strcmp(str, "front"))
		{
			printf("%d\n", getFront(&que));
		}
		else if (!strcmp(str, "back"))
		{
			printf("%d\n", getBack(&que));
		}
	}


	return 0;
}

