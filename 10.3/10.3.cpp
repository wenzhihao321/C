#include<iostream>
#include<assert.h>
////1.�������ķ���
//int my_strlen(char* arr1)
//{
//	int count = 0;
//	assert(arr1 != NULL);
//	while (*arr1!='\0')
//	{
//		count++;
//		arr1++;
//	}
//	return count;
//}

////2.�ݹ�
//int my_strlen(char* arr1)
//{
//	assert(arr1 != NULL);
//	if (*arr1 != '\0')
//	{
//		return 1 + my_strlen(arr1 + 1);
//	}
//	else
//	{
//		return 0;
//	}
//}

//3.ָ��-ָ��
int my_strlen(const char* arr1)
{
	const char* ret = arr1;
	while (*arr1)
	{
		arr1++;
	}
	return arr1 - ret;
}

int main()
{
	//����ʾ��
	/*char arr1[] = {'a','b','c','d','e','f'};*/
	//int len=my_strlen(arr1);
	//char arr1[] = "abcdef";
	//int len=my_strlen(arr1);
	//printf("%d\n", len);
	
	if (strlen("abc") - strlen("abcdef") > 0)
	{
		printf("hehe\n");
	}
	else
	{
		printf("haha\n");
	}
	//��Ϊint my_strlen(const char* arr1)�е�intΪ�з��ŵ�����
	//�ڿ⺯����int��size_t==ussigned int ���޷�������3-6=-3��������������
	return 0;
}

