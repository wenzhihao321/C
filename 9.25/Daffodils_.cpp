#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//int main()
//{
//	//�ж�i�Ƿ�Ϊˮ�ɻ�������������
//	int i = 0;
//	for (i = 0; i < 100000; i++)
//	{
//		int n = 1;
//		int tmp = i;
//		int sum = 0;
//		while (tmp/=10)
//		{
//			n++;
//		}
//		tmp = i;
//		while (tmp)
//		{
//			sum+=pow(tmp % 10, n);
//			tmp /= 10;
//		}
//		if (i == sum)
//		{
//			printf("%d ", i);
//		}
//	}
//}
int main()
{
	int line = 0;
	scanf("%d", &line);
	int i = 0;
	//��ӡ�ϰ벿��
	for (i = 0; i < line; i++)
	{
		//��ӡ�ո�
		int j = 0;
		for (j = 0; j < line - 1 - i; j++)
		{
			printf(" ");
		}
		//��ӡ*
		for (j = 0; j < 2*i+1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	//��ӡ�°��겿��
	for (i=0 ;i<line - 1;i++)
	{
		//��ӡ�ո�
		int j = 0;
		for (j=0;j<=i;j++)
		{
			printf(" ");
		}
		//��ӡ*
		for (j=0;j<2*(line-1-i)-1;j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}