#include<iostream>
#include<assert.h>
////1.计数器的方法
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

////2.递归
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

//3.指针-指针
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
	//错误示范
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
	//因为int my_strlen(const char* arr1)中的int为有符号的整型
	//在库函数中int是size_t==ussigned int 是无符号整型3-6=-3，负数会变成正数
	return 0;
}

