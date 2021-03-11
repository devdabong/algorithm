#define	TRUE		1
#define FALSE		0

typedef int Data;

typedef struct _Node
{
	Data data;
	struct _Node *next;

} Node;


typedef struct _ListStack
{
	Node *head;

} ListStack;


typedef ListStack Stack;


void StackInit(Stack *pstack);
int	IsEmpty(Stack *pstack);
void Push(Stack *pstack, Data data);
Data Pop(Stack *pstack);
Data Peek(Stack *pstack);
