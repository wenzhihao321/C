#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<assert.h>
//拷贝函数
char* my_strcpy(char* arr1,const char* arr2)
{
	assert(arr1 != NULL);
	assert(arr2 != NULL);
	char* ret = arr1;
	//拷贝arr2指向的字符串到arr1指向的空间，包含'\0'
	while (*arr1++=*arr2++)
	{
		;
	}
	//返回目的空间的起始地址
	return ret;
}

//追加函数
char* my_strcat(char* arr1, char* arr2)
{
	assert(arr1 != NULL);
	assert(arr2 != NULL);
	char* ret = arr1;
	//1、找到目的字符串的'\0'
	while (*arr1 != '\0')
	{
		arr1++;
	}
	//2.追加
	while (*arr1++ = *arr2++)
	{
		;
	}
	return ret;
}
int main()
{
	////拷贝的目的数组的空间必须比源头数组的空间大
	//char arr1[] = "abcdefghi";
	//char arr2[] = "bit";
	////错误示范
	////char arr2[] = { 'b','i','t' };
	////char*arr1 = "abcdefghi";

	////strcpy(arr1, arr2);
	//my_strcpy(arr1, arr2);
	//printf("%s\n", arr1);

	//错误示范，目标空间必须足够大
	//char arr1[] = "hello";
	char arr1[30] = "hello";
	char arr2[] = "world";
	//strcat(arr1, arr2);
	my_strcat(arr1, arr2);
	printf("%s\n", arr1);
	return 0;
}
