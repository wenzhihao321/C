#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<assert.h>
//��������
char* my_strcpy(char* arr1,const char* arr2)
{
	assert(arr1 != NULL);
	assert(arr2 != NULL);
	char* ret = arr1;
	//����arr2ָ����ַ�����arr1ָ��Ŀռ䣬����'\0'
	while (*arr1++=*arr2++)
	{
		;
	}
	//����Ŀ�Ŀռ����ʼ��ַ
	return ret;
}

//׷�Ӻ���
char* my_strcat(char* arr1, char* arr2)
{
	assert(arr1 != NULL);
	assert(arr2 != NULL);
	char* ret = arr1;
	//1���ҵ�Ŀ���ַ�����'\0'
	while (*arr1 != '\0')
	{
		arr1++;
	}
	//2.׷��
	while (*arr1++ = *arr2++)
	{
		;
	}
	return ret;
}
int main()
{
	////������Ŀ������Ŀռ�����Դͷ����Ŀռ��
	//char arr1[] = "abcdefghi";
	//char arr2[] = "bit";
	////����ʾ��
	////char arr2[] = { 'b','i','t' };
	////char*arr1 = "abcdefghi";

	////strcpy(arr1, arr2);
	//my_strcpy(arr1, arr2);
	//printf("%s\n", arr1);

	//����ʾ����Ŀ��ռ�����㹻��
	//char arr1[] = "hello";
	char arr1[30] = "hello";
	char arr2[] = "world";
	//strcat(arr1, arr2);
	my_strcat(arr1, arr2);
	printf("%s\n", arr1);
	return 0;
}
