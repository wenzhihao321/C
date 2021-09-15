#include<iostream>
#include<assert.h>
using namespace std;
//6分
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

//7分
//void my_strcpy(char* arr1, char* arr2)
//{
//	while(*arr1++ = *arr2++)
//	{
//		;
//	}
//}

//8分
//void my_strcpy(char* arr1, char* arr2)
//{
//	assert(arr1 != NULL);
//	assert(arr2 != NULL);
//	while (*arr1++ = *arr2++)
//	{
//		;
//	}
//}

//9分
//void my_strcpy(char* arr1, const char* arr2)
//{
//	assert(arr1 != NULL);
//	assert(arr2 != NULL);
//	while (*arr1++ = *arr2++)
//	{
//		;
//	}
//}

//10分
char* my_strcpy(char* arr1, char* arr2)
{
	char* ret = arr1;
	assert(arr1 != NULL);
	assert(arr2 != NULL);
	//将arr2指向的字符串拷贝到arr1指向的空间，包含'\0'字符
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
