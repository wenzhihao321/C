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
	////free�����������ͷŶ�̬���ٵĿռ��
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
	//������ʹ��malloc���ٵ�20���ֽڵĿռ�
	//�������20���ֽڲ����������ǵ�ʹ��
	//ϣ�������ܹ���40���ռ�
	//����Ϳ���ʹ��realloc��������̬���ٵ��ڴ�

	//reallocʹ�õ�ע�����
	//1.���pָ��Ŀռ�֮�����㹻���ڴ�ռ����׷�ӣ���ֱ��׷�ӣ��󷵻�p
	//2.���pָ��Ŀռ�֮��û���㹻���ڴ�ռ����׷�ӣ���realloc������������һ���µ��ڴ�����
	//  ����һ����������Ŀռ䣬���Ұ�ԭ���ڴ��е����ݿ����������ͷžɵ��ڴ�ռ�
	//  ��󷵻��¿��ٵ��ڴ�ռ��ַ
	//3.����һ���µı���������reallov�����ķ���ֵ
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
	//�ͷ��ڴ�
	free(p3);
	p3 = NULL;
	return 0;
}
