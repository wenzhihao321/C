#include<iostream>
//using namespace std;
#include<assert.h>
struct S
{
	char name[20];
	int age;
};

void my_memcpy(void* arr2,  void* arr1, size_t num)
{
	assert(arr1 != NULL);
	assert(arr2 != NULL);
	char* ret1 = (char*)arr1;
	char* ret2 = (char*)arr2;

	while (num--)
	{
		*ret2 = *ret1;
		++ret2;
		++ret1;
		//*(char*)arr2 = *(char*)arr1;
		//((char*)arr2)++;
		//((char*)arr1)++;
	}	

}


//C���Ա�׼��
//memcpy ֻ���� ���ص����ڴ濽���Ϳ���
//memmove �����ص��ڴ�Ŀ���
int main()
{
	int arr[]= { 1,2,3,4,5,6,7,8,9,10 };
	//my_memcpy(arr+2,arr,20);
	memmove(arr + 2, arr, 20);//�����ڴ��ص��������
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}

//int main()
//{
//	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int arr2[10] = { 0 };
//	struct S arr3[] = { {"����",20},{"����",30} };
//	struct S arr4[3] = { 0 };
//	my_memcpy(arr2, arr1, sizeof(arr1));
//	my_memcpy(arr4,arr3,sizeof(arr3));
//	return 0;
//}