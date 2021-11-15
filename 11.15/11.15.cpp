#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#define DEBUG
//int main()
//{
//	int arr[10] = { 0 };
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		arr[i] = i; 
////定义了DEBUG就会执行，没有则不会
//#ifdef DEBUG
//		printf("%d ", arr[i]);
//#endif
//	}
//	return 0;
//}

//int main()
//{
//	int arr[10] = { 0 };
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		arr[i] = i; 
////为真执行，为假不执行
//#if 0
//		printf("%d ", arr[i]);
//#endif
//		}
//	return 0;
//}

//int main()
//{
//#if 1==1
//	printf("小惠");
//#elif 2==1
//	printf("小惠");
//#else
//	printf("小惠");
//#endif
//	return 0;
//}

int main()
{
#if defined(DEBUG)
	printf("小惠好想你\n");
#endif
//一样的
#ifdef DEBUG
	printf("小惠好想你");
#endif
#if !defined(DEBUG)
	printf("小惠好想你\n");
#endif
	return 0;
}