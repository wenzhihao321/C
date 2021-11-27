#include"Stack.h"

void test()
{
	Stack st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	bool a = StackEmpty(&st);
	while (!a)
	{
		
		printf("%d ", StackTop(&st));
		StackPop(&st);
		a = StackEmpty(&st);
	}
	StackDestroy(&st);
}


int main()
{
	test();
	return 0;
}