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
////������DEBUG�ͻ�ִ�У�û���򲻻�
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
////Ϊ��ִ�У�Ϊ�ٲ�ִ��
//#if 0
//		printf("%d ", arr[i]);
//#endif
//		}
//	return 0;
//}

//int main()
//{
//#if 1==1
//	printf("С��");
//#elif 2==1
//	printf("С��");
//#else
//	printf("С��");
//#endif
//	return 0;
//}

int main()
{
#if defined(DEBUG)
	printf("С�ݺ�����\n");
#endif
//һ����
#ifdef DEBUG
	printf("С�ݺ�����");
#endif
#if !defined(DEBUG)
	printf("С�ݺ�����\n");
#endif
	return 0;
}