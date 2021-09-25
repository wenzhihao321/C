#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
void reverse(char* arr)
{
	int sz = strlen(arr);
	char* left = arr;
	char* right = arr + sz - 1;
	while(left<=right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}

//void reverse(char* arr)
//{
//	int sz = strlen(arr);
//	int left = 0;
//	int right = sz-1;
//	while (left <= right)
//	{
//		char tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = tmp;
//		left++;
//		right--;
//	}
//}
int main()
{
	char arr[256] = { 0 };
	//scanf("%s", arr);//�����ո�Ͳ�����
	gets_s(arr);//��ȡһ�У�����ո�
	reverse(arr);
	printf("%s\n", arr);
	return 0;
}