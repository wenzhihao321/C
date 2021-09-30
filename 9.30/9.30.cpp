#include<iostream>
//写一个代码，在arr数组（有序数组）中找到7
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int k = 7;
	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (i = 0; i <= 10; i++)
	{
		if (k == arr[i])
		{
			printf("找到了你了，下标是：%d\n", i);
			break;
		}
		
	}
	if (i == sz)
	{
		printf("找不到\n");
	}
	return 0;
}