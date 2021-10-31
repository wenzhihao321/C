#include<iostream>

//柔性数组
////第一种写法
struct S
{
	int n;
	int arr[0];
};
int main()
{
	struct S* ps = (struct S*)malloc(sizeof(int) + 5 * sizeof(int));
	ps->n = 100;
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		ps->arr[i] = i;
	}
	struct S* ptr = (struct S*)realloc(ps, 44);
	if (ptr != NULL)
	{
		ps = ptr;
	}
	for (i = 5; i < 10; i++)
	{
		ps->arr[i] = i;
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d ", ps->arr[i]);
	}
	free(ps);
	ps = NULL;
	return 0;
}



////第二种写法
// 由于用了两次malloc开辟两次更容易出错
//struct S
//{
//	int n;
//	int*arr;//未知大小的-柔型数组成员-数组的大小是可以调整的
//};
//int main()
//{
//	struct S* ps = (struct S*)malloc(sizeof(struct S));
//	ps->arr = (int*)malloc(5 * sizeof(int));
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		ps->arr[i] = i;
//		printf("%d ", ps->arr[i]);
//	}
//	printf("\n");
//	//调整大小
//	int* ptr = (int*)realloc(ps->arr, 10 * sizeof(int));
//	if (ptr != NULL)
//	{
//		ps->arr = ptr;
//	}
//	for (i = 5; i < 10; i++)
//	{
//		ps->arr[i] = i;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", ps->arr[i]);
//	}
//	//释放内存
//	free(ps);
//	ps = NULL;
//	free(ps->arr);
//	ps->arr = NULL;
//	return 0;
//}