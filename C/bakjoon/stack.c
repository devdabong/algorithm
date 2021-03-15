#include <stdio.h>
#include <string.h>

#define STACK_SIZE 	1000

typedef struct Stack 
{
	int top;
	int arr[STACK_SIZE];
} Stack;

int main()
{

	int cnt = 0;
	char input[5];

	scanf("%d", &cnt);

	for(int i=0; i<cnt; i++)
	{
		scanf("%s \n", &input);

		printf("!!");
	}

}

int empty(Stack *stack)
{
	if(stack->top == -1)
		return 1;
	else
		return 0;
}

void push(Stack *stack, int data)
{
	stack->top += 1;
	stack->arr[stack->top] = data;
}


int pop(Stack *stack)
{
	int idx;

	if (empty(stack))
		return -1;

	idx = stack->top;
	stack->top -= 1;

	return stack->arr[idx];
}


int size(Stack *stack)
{
	return stack->top + 1;	
}


int top(Stack *stack)
{
	return stack->arr[stack->top];
}
