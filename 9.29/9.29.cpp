#include<iostream>
#include<assert.h>
//实现一个函数，可以左旋字符串中的k个字符
// ABCD左旋一个字符得到BCDA
// ABCD左旋一个字符得到CDAB
//暴力求解法
//void left_move(char arr[], int x)
//{
//	int i = 0;
//	int len = strlen(arr);
//	for (i = 0; i < x; i++)
//	{
//		//左旋转一个字符
//		//1
//		char tmp = *arr;
//		//2
//		int j = 0;
//		for (j = 0; j < len - 1; j++)
//		{
//			*(arr + j) = *(arr + j + 1);
//		}
//		*(arr + len - 1) = tmp;
//	}
// }

void reverse(char*left,char *right)
{
	assert(left!=NULL);
	assert(right!=NULL);
	while (left<right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}

}
//三步翻转法
void left_move(char arr[], int x)
{
	assert(arr);
	int len = strlen(arr);
	assert(x <= len);
	reverse(arr, arr + 1);//逆序左边
	reverse(arr+2, arr+len-1);//逆序右边
	reverse(arr, arr + len-1);//逆序整体
}
int main()
{
	char arr[] = "abcdef";
	left_move(arr, 2);
	printf("%s\n", arr);
	return 0;
}