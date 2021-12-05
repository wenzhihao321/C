#include"Sort.h"
void Print(int* a,int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
//��������
void InserSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end=i;
		int tmp=a[i+1];	//�ȼ�¼Ҫ�����ֵ
		while (end >= 0)
		{
			//endλ�õ�ֵ����Ҫ�����ֵtmp�Ͱ�end��ֵ����
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
			}
			else
			{
				break;
			}
			end--;
		}
		a[end + 1] = tmp;
	}
}
//ϣ������
void ShellSort(int* a, int n)
{
	//gap>1��ʱ��Ԥ����
	//gap==1��ʱ��ֱ�Ӳ�������
	int gap=n;
	while (gap > 1)
	{
		gap =(gap / 3 + 1);
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
		printf("gap=%d-> ", gap);
		Print(a, n);
	}
}