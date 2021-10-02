#include<iostream>
//有一个数组矩阵，矩阵的每行从左到右是递增的，矩阵从上到下是递增的，请编写程序再这样的矩阵中查找某个数字是否存在。
//要求：时间复杂度小于O（N）
int findNum(int arr[3][3],int k,int row,int col)
{
	int i = 0;
	int j = col - 1;
	while (i<row||j>=0)//while (i<=row-1||j>=0)
	{
		if (arr[i][j] > k)
		{
			j--;
		}
		else if (arr[i][j] < j)
		{
			i++;
		}
		else
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	int arr[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
	int k = 7;
	int ret = findNum(arr,k,3,3);
	if (ret == 1)
	{
		printf("找到了\n");
	}
	else
	{
		printf("找不到\n");
	}
	return 0;
}