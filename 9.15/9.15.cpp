#include<iostream>
#include<assert.h>
using namespace std;
//6��
//void my_strcpy(char *arr1,char* arr2)
//{
//	while (*arr2 != '\0')
//	{
//		*arr1 = *arr2;
//		arr1++;
//		arr2++;
//	}
//	*arr1 = *arr2;
//}

//7��
//void my_strcpy(char* arr1, char* arr2)
//{
//	while(*arr1++ = *arr2++)
//	{
//		;
//	}
//}

//8��
//void my_strcpy(char* arr1, char* arr2)
//{
//	assert(arr1 != NULL);
//	assert(arr2 != NULL);
//	while (*arr1++ = *arr2++)
//	{
//		;
//	}
//}

//9��
//void my_strcpy(char* arr1, const char* arr2)
//{
//	assert(arr1 != NULL);
//	assert(arr2 != NULL);
//	while (*arr1++ = *arr2++)
//	{
//		;
//	}
//}

//10��
char* my_strcpy(char* arr1, char* arr2)
{
	char* ret = arr1;
	assert(arr1 != NULL);
	assert(arr2 != NULL);
	//��arr2ָ����ַ���������arr1ָ��Ŀռ䣬����'\0'�ַ�
	while (*arr1++ = *arr2++)
	{
		;
	}
	return ret;
}
int main()
{
	char arr1[] = "**************";
	char arr2[] = "bit";
	printf("%s\n", my_strcpy(arr1, arr2));
	return 0;
}
