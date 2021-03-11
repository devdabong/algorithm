#include <stdio.h>
#include "arrayCommon.h"

int main()
{
	// 스택 초기화
	Stack stack;
	stackInit(&stack);

	printf("init topIndex: %d\n", stack.topIndex);  

	// 데이터 넣기
	push(&stack, 1);
	push(&stack, 2);
	push(&stack, 3);
	push(&stack, 4);
	push(&stack, 5);


	// 데이터 꺼내기
	while (!isEmpty(&stack))
		printf("%d ", pop(&stack));

	printf("\n");

	return 0;
}

