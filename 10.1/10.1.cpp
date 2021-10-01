#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <assert.h>


//void reverse(char* left,char* right)
//{
//	assert(left!=NULL);
//	assert(right != NULL);
//	while (left < right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//
//void left_move(char* arr, int x)
//{
//	assert(arr);
//	int len = strlen(arr);
//	assert(x<=len);
//	printf("%s\n", arr);
//	reverse(arr, arr + x - 1);
//	printf("%s\n", arr);
//	reverse(arr + x, arr + len - 1);
//	printf("%s\n", arr);
//	reverse(arr, arr + len - 1);
//	printf("%s\n", arr);
//}
////abcdef
////bcdefa
////cdefab
////defabc
////efabcd
////fabcde
//int is_left_move(char* a1, char* a2)
//{
//	int len = strlen(a1);
//	int i = 0;
//	for (i = 0; i < len; i++)
//	{
//		left_move(a1, 1);
//		int ret = strcmp(a1, a2);
//		if (ret == 0)
//		{
//			return 1;
//		}
//	}
//	return 0;
//}
//改进
int is_left_move(char* a1, char* a2)
{
	int len = strlen(a1);
	//1.在a1字符串追加一个a1字符串
	//strcat
	//不能自己给自己追加字符串，自我追加'\0'会被改掉，导致不会中止
    //strncat(str1,str1,6)
	strncat(a1, a1,len);
	//2.判断a2指向的字符串是否是a1指向的字符串的子串
	//strstr-找子串,返回的是首个地址
	char* ret = strstr(a1, a2);
	if (ret == NULL)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int main()
{
	 char arr1[30] = "abcdef";
	 char arr2[] = "cdefab";
	 int ret=is_left_move(arr1, arr2);
	 if (ret == 1)
	 {
		 printf("YES\n");
	 }
	 else
	 {
		 printf("NO\n");
	 }
	return 0;
}