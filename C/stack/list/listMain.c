#include <stdio.h>
#include "listCommon.h"

int main()
{
	// 스택 초기화
	Stack stack;
	StackInit(&stack);

	Push(&stack, 1);
	Push(&stack, 2);
	Push(&stack, 3);
	Push(&stack, 4);
	Push(&stack, 5);


	while(!IsEmpty(&stack))
		printf("%d ", Pop(&stack));

	printf("\n");

	return 0;
}

