#include"SeqList.h"

void SeqListInit(SeqList* pq)
{
	assert(pq);
	pq->a = NULL;
	pq->capacity = pq->size = 0;
}
void SeqListDestory(SeqList* pq)
{
	assert(pq);

	free(pq->a);
	pq->a = NULL;
	pq->capacity = pq->size = 0;
}
void SeqListPrint(SeqList* pq)
{
	assert(pq);
	for (int i = 0; i < pq->size; ++i)
	{
		printf("%d ", pq->a[i]);
	}
	printf("\n");
}
void SeqCheckCapacity(SeqList* pq)
{
	assert(pq);
	if (pq->size == pq->capacity)
	{
		int newcapacity = pq->capacity == 0 ? 4 : pq->capacity * 2;
		SeqDataType* newA = (SeqDataType*)realloc(pq->a, sizeof(SeqDataType) * newcapacity);
		if (newA == NULL)
		{
			printf("reallocʧ�ܣ�\n");
			exit(-1);
		}
		pq->a = newA;
		pq->capacity = newcapacity;
	}
}
void SeqListPushBack(SeqList* pq, SeqDataType x)
{
	assert(pq);
	SeqCheckCapacity(pq);
	pq->a[pq->size] = x;
	pq->size++;
}
void SeqListPushFront(SeqList* pq, SeqDataType x)
{
	assert(pq);
	SeqCheckCapacity(pq);

	int end = pq->size - 1;
	while (end >= 0)
	{
		pq->a[end + 1] = pq->a[end];
		end--;
	}
	pq->a[0] = x;
	pq->size++;
}
void SeqListPopBack(SeqList* pq)
{
	assert(pq);
	assert(pq->size > 0);
	--pq->size;
}
//void SeqListPopFront(SeqList* pq)
//{
//	assert(pq);
//}