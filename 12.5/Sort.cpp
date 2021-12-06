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
void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
//选择排序    选出一个最大和最小的数，然后不断往里面缩
void SelectSort(int* a, int n)
{
	int left=0, right=n-1;
	int minIndex = left, maxIndex = left;
	while (left < right)
	{
		//选出了最大的值和最小的值
		for (int i = left; i <= right; i++)
		{
			if (a[minIndex] > a[i])
			{
				minIndex = i;
			}
			if (a[maxIndex] < a[i])
			{
				maxIndex = i;
			}
		}
		Swap(&a[left], &a[minIndex]);
		//如果max和left位置重叠，max被换走了，要修正一下max的位置
		if (maxIndex == left)
		{
			maxIndex = minIndex;
		}
		Swap(&a[right], &a[maxIndex]);
		left++;
		right--;
	}
}
void AdjustDwon(int* a, int n, int root)
{
	int parent = root;
	int child = root * 2 + 1;
	while (child<n)
	{
		if (child+1<n&&a[child] < a[child + 1])
		{
			child++;
		}
		if (a[parent] < a[child])
		{
			Swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapSort(int* a, int n)
{
	//升序，建大堆
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDwon(a, n, i);
	}
	int tail = n;
	for (int i = 0; i < n-1; i++)
	{ 
		Swap(&a[0], &a[tail-1]);
		AdjustDwon(a, --tail, 0);
	}
}
void BubbleSort(int* a, int n)
{
	for (int end = n; end > 0; end--)
	{
		int exchange = 0;
		for (int i = 0; i < n - 1; i++)
		{
			if (a[i] > a[i + 1])
			{
				Swap(&a[i], &a[i + 1]);
				exchange = 1;
			}
		}
		if (exchange == 0)
		{
			break;
		}
	}


}
