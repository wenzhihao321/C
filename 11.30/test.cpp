#include"Heap.h"
void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp;
	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
//建大堆
void AdjustDown(HPDataType* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
		{
			child++;
		}
		if (a[parent] < a[child])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
//向上调整
void AdjustUp(HPDataType* a,int child)
{
	int parent = (child - 1) / 2;
	while (child>0)
	{
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent= (child - 1) / 2;
		}
		else
		{
			break;
		}
	}

}
void HeapInit(HP* php, HPDataType* a, int n)
{
	assert(php);
	php->a =(HPDataType*) malloc(sizeof(HPDataType)*n);
	if (php->a == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	memcpy(php->a, a, sizeof(HPDataType)*n);
	php->size = n;
	php->capacity = n;
	//建大堆
	for (int i = n / 2 - 1; i >= 0; --i)
	{
		AdjustDown(php->a, php->size,i);
	}
}
void HeapDestroy(HP* php)
{
	assert(php);
	free(php->a);
	php->a = NULL;
	php->capacity = php->size = 0;
}
void HeapPush(HP* php, HPDataType x)
{
	assert(php);
	if (php->size == php->capacity)
	{
		HPDataType* tmp = (HPDataType*)realloc(php->a, sizeof(HPDataType)*php->capacity*2);
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		php->a = tmp;
		php->capacity = php->capacity * 2;
	}
	php->a[php->size ] = x;
	php->size++;

	AdjustUp(php->a, php->size-1);
}
//删除换到最后的这个原堆顶数据
void HeapPop(HP* php)
{
	assert(php);
	assert(php->size > 0);
	Swap(&php->a[php->size - 1], &php->a[0]);
	php->size--;
	AdjustDown(php->a, php->size, 0);
}
HPDataType HeapTop(HP* php)
{
	assert(php);
	assert(php->size > 0);
	return php->a[0];
}
int HeapSize(HP* php)
{
	assert(php);
	return php->size;
}
bool HeapEmpty(HP* php)
{
	assert(php);
	return php->size == 0;
}
void HeapPrint(HP* php)
{
	for (int i = 0; i < php->size; i++)
	{
		printf("%d ", php->a[i]);
	}
	printf("\n");
	int num = 0;
	int levelSize = 1;
	for (int i = 0; i < php->size; i++)
	{
		printf("%d ", php->a[i]);
		num++;
		if (num == levelSize)
		{
			printf("\n");
			levelSize *= 2;
			num = 0;
		}
	}
	printf("\n\n");
}