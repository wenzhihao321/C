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
void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
//ѡ������    ѡ��һ��������С������Ȼ�󲻶���������
void SelectSort(int* a, int n)
{
	int left=0, right=n-1;
	int minIndex = left, maxIndex = left;
	while (left < right)
	{
		//ѡ��������ֵ����С��ֵ
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
		//���max��leftλ���ص���max�������ˣ�Ҫ����һ��max��λ��
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
	//���򣬽����
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

//����ȡ��
int GetMidIndex(int* a, int left, int right)
{
	//��Ϊ����������һλ
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
//��������hoare�汾����   ����ָ�뷨
int PartSort1(int* a, int left, int right)
{
	int midindex = GetMidIndex(a, left, right);
	Swap(&a[midindex], &a[left]);
	int begin = left, end = right;
	int key = left;
	while (begin < end)
	{
		//��С	
		while (begin < end && a[end] >= a[key])
		{
			end--;
		}
		//�Ҵ�
		while (begin < end && a[begin] <= a[key])
		{
			begin++;
		}
		Swap(&a[begin], &a[end]);
	}
	//����
	Swap(&a[key], &a[begin]);
	return begin;
}

int PartSort2(int* a, int left, int right)
{
	int midindex = GetMidIndex(a, left, right);
	Swap(&a[midindex], &a[left]);
	int key = a[left];
	//��ߵ�λ�õ�ֵ����key��leftλ�ñ�Ϊ��
	while (left < right)
	{
		//��С��ֵ
		while (left < right && a[right] >= key)
		{
			right--;
		}
		//������ߵĿ�λ�У��ұ߾��γ��¿�λ
		a[left] = a[right];
		//�Ҵ��ֵ
		while (left < right && a[left] <= key)
		{
			left++;
		}
		//�����ұߵĿ�λ�У���߾��γ��¿�λ
		a[right] = a[left];
	}
	a[left] = key;
	return left;
}
// ��������ǰ��ָ�뷨   
//curȥ��С�ģ��ҵ���prev++Ȼ��cur��prev��ֵ
//��cur�ߵ�β������prev��key��ֵ
int PartSort3(int* a, int left, int right)
{
	int midindex = GetMidIndex(a, left, right);
	Swap(&a[midindex], &a[left]);
	int key = left;
	int prev = left, cur = left + 1;
	while (cur <=right)
	{
		//��С��
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
	//��ֻ��һ��ֵ��ʱ���ֹͣ
	if (left >= right)
	{
		return;
	}
	//1.�����������������ݽ϶࣬����ѡ��key���ˣ��ָ���������εݹ�
	//2.�����������������ݽ��٣���ȥ���εݹ鲻����
	if (right - left > 10)
	{
		//int meet = PartSort1(a,left,right);
		//int meet = PartSort2(a, left, right);
		int meet = PartSort3(a, left, right);
		//ÿ�δ��ݵ�������[left��meet-1]  [meet+1,right]
		QuickSort(a, left, meet - 1);
		QuickSort(a, meet + 1, right);
	}
	else//  right - left<10
	{
		InserSort(a + left, right - left + 1);
	}
} 
//�ǵݹ�
//�ݹ� �ִ��������Ż��ܺ��ˣ������Ѿ����Ǵ�����
// ��������->�ݹ����̫�������û�����⣬����ջ�ռ䲻��������ջ���
// ֻ�ܸĳɷǵݹ飬�ĳɷǵݹ������ַ�ʽ��
// 1��ֱ�Ӹ�ѭ��->쳲������������
// 2���������ǵݹ�Ϳ��ŷǵݹ�ȵȣ�ֻ����Stack�洢����ģ��ݹ����
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