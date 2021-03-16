#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE			1
#define FALSE 		    0


typedef struct _node{
	int idx;
	int data;
	struct _node *next;
} Node;

typedef struct _listStack{
	Node *head;
} ListStack;

typedef ListStack Stack;

void StackInit(Stack *sp){
	sp->head = 0x00;
}

int IsEmpty(Stack *sp){
	Node *n;

	if(sp->head == 0x00)
	{
		Node *newNode = (Node *)malloc(sizeof(Node));

		n = sp->head;

		newNode->idx = -1;
		sp->head = newNode;
		
		free(n);

		printf("%d kkakakakk\n", sp->head->idx);

		return TRUE;
	}

	return FALSE;
}

void Push(Stack *sp, int data){

	Node *newNode = (Node *)malloc(sizeof(Node));

	if (IsEmpty(sp)){
		newNode->idx = sp->head->idx + 1;
	}

	newNode->next = sp->head;
	newNode->data = data;
	newNode->idx = sp->head->idx + 1;
	
	printf("%d \t %d", newNode->idx, newNode->data);
	printf("///////\n");

	sp->head = newNode;
}

int Pop(Stack *sp){
	int topData;

	Node *n;

	if (IsEmpty(sp)) {
		return -1;
	}	

	topData = sp->head->data;

	n = sp->head;

	sp->head = sp->head->next;
	free(n);

	return topData;
}

int Size(Stack *sp){
	if(sp->head == 0x00)
		return 0;

	return sp->head->idx;	
}

int Peek(Stack *sp){
	return sp->head->data;
}

int main()
{
	Stack stack;
	char str[6];
	int i;
	int n, num;

	printf("hi\n");
	scanf("%d", &n);

	StackInit(&stack);

	
	for(i=0; i<n; i++)
	{
		scanf("%s", str);

		if (!strcmp(str, "push"))
		{
			scanf("%d", &num);
			 
			Push(&stack, num);
			//printf("push %d\n", num);	
		}
		else if (!strcmp(str, "pop"))
		{
			printf("%d\n", Pop(&stack));
		}
		else if (!strcmp(str, "empty"))
		{
			printf("%d\n", IsEmpty(&stack));
		}
		else if (!strcmp(str, "size"))
		{
			printf("%d\n", Size(&stack));
		}
		else if (!strcmp(str, "top"))
		{
			printf("%d\n", Peek(&stack));
		}
	}


	return 0;
}
