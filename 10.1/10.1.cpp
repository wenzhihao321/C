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
//�Ľ�
int is_left_move(char* a1, char* a2)
{
	int len = strlen(a1);
	//1.��a1�ַ���׷��һ��a1�ַ���
	//strcat
	//�����Լ����Լ�׷���ַ���������׷��'\0'�ᱻ�ĵ������²�����ֹ
    //strncat(str1,str1,6)
	strncat(a1, a1,len);
	//2.�ж�a2ָ����ַ����Ƿ���a1ָ����ַ������Ӵ�
	//strstr-���Ӵ�,���ص����׸���ַ
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