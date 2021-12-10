#include"Sort.h"
#include"Stack.h"
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

//三数取中
int GetMidIndex(int* a, int left, int right)
{
	//变为二进制右移一位
	int mid = (left + right) >> 1;
	// left  mid  right 
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
		{
			return mid;
		}
		else if (a[left] > a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
	else //(a[left]> a[mid])
	{
		if (a[mid] > a[right])
		{
			return mid;
		}
		else if (a[left] < a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
}
//快速排序hoare版本单趟   左右指针法
int PartSort1(int* a, int left, int right)
{
	int midindex = GetMidIndex(a, left, right);
	Swap(&a[midindex], &a[left]);
	int begin = left, end = right;
	int key = left;
	while (begin < end)
	{
		//找小	
		while (begin < end && a[end] >= a[key])
		{
			end--;
		}
		//找大
		while (begin < end && a[begin] <= a[key])
		{
			begin++;
		}
		Swap(&a[begin], &a[end]);
	}
	//相遇
	Swap(&a[key], &a[begin]);
	return begin;
}

int PartSort2(int* a, int left, int right)
{
	int midindex = GetMidIndex(a, left, right);
	Swap(&a[midindex], &a[left]);
	int key = a[left];
	//左边的位置的值给了key，left位置变为坑
	while (left < right)
	{
		//找小的值
		while (left < right && a[right] >= key)
		{
			right--;
		}
		//放在左边的坑位中，右边就形成新坑位
		a[left] = a[right];
		//找大的值
		while (left < right && a[left] <= key)
		{
			left++;
		}
		//放在右边的坑位中，左边就形成新坑位
		a[right] = a[left];
	}
	a[left] = key;
	return left;
}
// 快速排序前后指针法   
//cur去找小的，找到了prev++然后cur和prev的值
//当cur走到尾，交换prev个key的值
int PartSort3(int* a, int left, int right)
{
	int midindex = GetMidIndex(a, left, right);
	Swap(&a[midindex], &a[left]);
	int key = left;
	int prev = left, cur = left + 1;
	while (cur <=right)
	{
		//找小的
		if (a[cur] < a[key]&&++prev!=cur)
		{
			Swap(&a[prev], &a[cur]);
		}
		cur++;
	}
	Swap(&a[prev], &a[key]);
	return prev;
}
void QuickSort(int* a, int left, int right)
{
	//当只有一个值的时候就停止
	if (left >= right)
	{
		return;
	}
	//1.如果这个子区间是数据较多，继续选择key单趟，分割子区间分治递归
	//2.如果这个子区间是数据较少，再去分治递归不划算
	if (right - left > 10)
	{
		//int meet = PartSort1(a,left,right);
		//int meet = PartSort2(a, left, right);
		int meet = PartSort3(a, left, right);
		//每次传递的区间是[left，meet-1]  [meet+1,right]
		QuickSort(a, left, meet - 1);
		QuickSort(a, meet + 1, right);
	}
	else//  right - left<10
	{
		InserSort(a + left, right - left + 1);
	}
} 
//非递归
//递归 现代编译器优化很好了，性能已经不是大问题
// 最大的问题->递归深度太深，程序本身没有问题，但是栈空间不够，导致栈溢出
// 只能改成非递归，改成非递归有两种方式：
// 1、直接改循环->斐波那契数列求解
// 2、树遍历非递归和快排非递归等等，只能用Stack存储数据模拟递归过程
//
//
void QuickSortNonR(int* a, int left, int right)
{
	Stack pq;
	StackInit(&pq);
	StackPush(&pq, left);
	StackPush(&pq, right);
	while (!StackEmpty(&pq))
	{
		int begin, end;
		end = StackTop(&pq);
		StackPop(&pq);
		begin = StackTop(&pq);
		StackPop(&pq);
		int key = PartSort1(a, begin, end);
		if (begin < key - 1)
		{
			StackPush(&pq, begin);
			StackPush(&pq, key - 1);
		}
		if (key + 1 < end)
		{
			StackPush(&pq, key + 1);
			StackPush(&pq, end);
		}
	}
	StackDestroy(&pq);
}