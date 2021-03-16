#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define	TRUE			1
#define FALSE 			0
#define MAX_SIZE	10000

int cnt = 0;

typedef struct _deque{
	struct _deque *prev;
	int data;
	struct _deque *next;
} Deque;
//typedef Deque *head; 

//typedef Deque *tail;

void init(Deque *head, Deque *tail)
{
	head = 0x00;
	tail = 0x00;
}

void DequeInit(Deque *dp){
	dp->prev = 0x00;
	dp->next = 0x00;
}

int IsEmpty(Deque *dp){
	if(cnt == 0)
		return TRUE;
	else
		return FALSE;
}

void Push_front(int data, Deque *head, Deque *tail){
	Deque *newDeque = (Deque *)malloc(sizeof(Deque));
	DequeInit(newDeque);

	newDeque->data = data;
	newDeque->prev = head->prev;
	newDeque->next = head;
	head->prev = newDeque;

	head = newDeque;

	cnt++;
}

void Push_back(int data, Deque *tail){
	Deque *newDeque = (Deque *)malloc(sizeof(Deque));
	DequeInit(newDeque);

	newDeque->data = data;
	newDeque->next = tail->next;
	newDeque->prev = tail;
	tail->next = newDeque;

	tail = newDeque;

	cnt++;
}

int Size(){
	return cnt;
}

int Pop_front(Deque *dp, Deque *head){
	if (IsEmpty(dp))
		return -1;

	int val = head->data;

	
	Deque *d = head->next;
	
	d->prev = head->prev;

	head = d;

	cnt--;
	
	return val;
}

int Pop_back(Deque *dp, Deque *tail){
	if(IsEmpty(dp))
		return -1;

	int val = tail->data;

	Deque *d = tail->prev;

	d->next = tail->next;

	tail = d;

	cnt--;

	return val;
}

int Get_Front(Deque *dp, Deque *head){
	if (IsEmpty(dp))
		return -1;
	
	return head->data;
}

int Get_Back(Deque *dp, Deque *tail){
	if (IsEmpty(dp))
		return -1;

	return tail->data;
}

int main(){

	Deque deq;

	Deque* head = (Deque *)malloc(sizeof(Deque));
	Deque* tail = (Deque *)malloc(sizeof(Deque));

	//Deque* h = head;
	//Deque* t = tail;


	char str[11];
	int i;
	int n, num;

	printf("hi\n");
	scanf("%d", &n);
	
	DequeInit(&deq);
#if 0	
    h = deq->prev;
	t = deq->next;
	h->next = deq;
	t->prev = deq;
#endif
	head = (Deque *)deq;
	tail = (Deque *)deq;
	

	for(i=0; i<n; i++)
	{
		scanf("%s", str);

		if (!strcmp(str, "push_front"))
		{
			scanf("%d", &num);
			 
			Push_Front(num, h);
		}
		else if (!strcmp(str, "push_back"))
		{
			scanf("%d", &num);
			 
			Push_Back(num, t);
		}
		else if (!strcmp(str, "pop_front"))
		{
			printf("%d\n", Pop_Front(&deq, h));
		}
		else if (!strcmp(str, "pop_back"))
		{
			printf("%d\n", Pop_Back(&deq, t));
		}
		else if (!strcmp(str, "empty"))
		{
			printf("%d\n", IsEmpty(&deq));
		}
		else if (!strcmp(str, "size"))
		{
			printf("%d\n", Size(&deq));
		}
		else if (!strcmp(str, "front"))
		{
			printf("%d\n", Get_Front(&deq, h));
		}
		else if (!strcmp(str, "top"))
		{
			printf("%d\n", Get_Back(&deq, t));
		}
	}


	return 0;
}
