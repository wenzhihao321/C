#include<iostream>
#include<assert.h>
//ʵ��һ�����������������ַ����е�k���ַ�
// ABCD����һ���ַ��õ�BCDA
// ABCD����һ���ַ��õ�CDAB
//������ⷨ
//void left_move(char arr[], int x)
//{
//	int i = 0;
//	int len = strlen(arr);
//	for (i = 0; i < x; i++)
//	{
//		//����תһ���ַ�
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
//������ת��
void left_move(char arr[], int x)
{
	assert(arr);
	int len = strlen(arr);
	assert(x <= len);
	reverse(arr, arr + 1);//�������
	reverse(arr+2, arr+len-1);//�����ұ�
	reverse(arr, arr + len-1);//��������
}
int main()
{
	char arr[] = "abcdef";
	left_move(arr, 2);
	printf("%s\n", arr);
	return 0;
}