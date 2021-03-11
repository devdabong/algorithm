#define	TRUE		  1	
#define FALSE		  0	
#define STACK_LEN	100

typedef int Data;

typedef struct array_stack
{
	Data stackArr[STACK_LEN];
	int topIndex;
} ArrayStack;

typedef ArrayStack Stack;

void stackInit(Stack *pstack);
int  isEmpty(Stack *pstack);

void push(Stack *pstack, Data data);
Data pop(Stack *pstack);
Data peek(Stack *pstack);

