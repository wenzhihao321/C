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
//插入排序
void InserSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end=i;
		int tmp=a[i+1];	//先记录要插入的值
		while (end >= 0)
		{
			//end位置的值大于要插入的值tmp就把end的值后移
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
//希尔排序
void ShellSort(int* a, int n)
{
	//gap>1的时候，预排序
	//gap==1的时候，直接插入排序
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