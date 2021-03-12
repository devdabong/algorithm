#define TRUE	  	  1
#define FALSE 	  	  0
#define QUE_LEN		100

typedef int Data;

typedef struct _CQueue
{
	int 	front;	// 맨 앞 요소
	int 	rear;	// 맨 뒤 요소
	Data 	queArr[QUE_LEN];
} CQueue;

typedef CQueue Que;

void QueueInit(Que *pq);
int IsEmpty(Que *pq);
int IsFull(Que *pq);
void Enqueue(Que *pq, Data data);
Data Dequeue(Que *pq);
Data Peek(Que *pq);
