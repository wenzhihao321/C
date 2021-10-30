#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

int main()
{
	////malloc
	//int* p1 = (int *)malloc(10*sizeof(int));
	//if (p1 == NULL)
	//{
	//	printf("%s\n", strerror(errno));
	//}
	//else
	//{
	//	int i = 0;
	//	printf("malloc:");
	//	for (i = 0; i < 10; i++)
	//	{
	//		*(p1 + i) = i;
	//		printf("%d ", *(p1 + i));
	//	}
	//	printf("\n");
	//}
	//free(p1);
	//p1 = NULL;



	////calloc
	////int* p = (int *)malloc(10*sizeof(int));
	//int* p2 = (int*)calloc(10, sizeof(int));
	//if (p2== NULL)
	//{
	//	printf("%s\n", strerror(errno));
	//}
	//else
	//{
	//	int i = 0;
	//	printf("calloc:");
	//	for (i = 0; i < 10; i++)
	//	{
	//		printf("%d ", *(p2 + i));
	//	}
	//	printf("\n");
	//}
	////free函数是用来释放动态开辟的空间的
	//free(p2);
	//p2 = NULL;



	//realloc
	int* p3 = (int*)malloc(20);
	if (p3 == NULL)
	{
		printf("%s\n", strerror(errno));
	}
	else
	{
		int i = 0;
		for (i = 0; i < 5; i++)
		{
			*(p3 + i) = i;
		}
	}
	//就是在使用malloc开辟的20个字节的空间
	//假设这里，20个字节不能满足我们的使用
	//希望我们能够有40个空间
	//这里就可以使用realloc来调整动态开辟的内存

	//realloc使用的注意事项：
	//1.如果p指向的空间之后有足够的内存空间可以追加，则直接追加，后返回p
	//2.如果p指向的空间之后没有足够的内存空间可以追加，测realloc函数会重新找一个新的内存区域
	//  开辟一块满足需求的空间，并且把原来内存中的数据拷贝回来，释放旧的内存空间
	//  最后返回新开辟的内存空间地址
	//3.得用一个新的变量来接收reallov函数的返回值
	int* ptr = (int*)realloc(p3, 40);
	if (ptr != NULL)
	{
		p3 = ptr;
		int i = 0;
		for (i = 5; i < 10; i++)
		{
			*(p3 + i) = i;
		}
		for (i = 0; i < 10; i++)
		{
			printf("%d ", *(p3 + i));
		}
	}
	//释放内存
	free(p3);
	p3 = NULL;
	return 0;
}
