#include"Heap.h"

//����
//void HeapSort(int* a, int n)
//{
//	for (int i = n / 2 - 1; i >= 0; --i)
//	{
//		AdjustUp(a, n, i);
//	}
//	int end = n - 1;
//	while (end > 0)
//	{
//		Swap(&a[0], &a[end]);
//		//ѡ���δ��
//		AdjustUp(a, end, 0);
//		end--;
//	}
//}
int main()
{
	int a[] = { 15,18,28,34,65,19,49,25,37, 27};
	int n = sizeof(a) / sizeof(a[0]);
	HP php;
	HeapInit(&php, a, n);
	HeapPrint(&php);

	HeapPush(&php,8);
	HeapPrint(&php);

	HeapPush(&php, 88);
	HeapPrint(&php);

	HeapPop(&php);
	HeapPrint(&php);
	printf("�Ѷ���%d\n", HeapTop(&php));
	printf("�Ѵ�СΪ%d\n", HeapSize(&php));
	HeapEmpty(&php);
	if (HeapEmpty(&php) == 1)
	{
		printf("��Ϊ��");
	}
	else
	{
		printf("�Ѳ�Ϊ��");
	}
	HeapDestroy(&php);
	return 0;
}