#include<iostream>
//��һ��������󣬾����ÿ�д������ǵ����ģ�������ϵ����ǵ����ģ����д�����������ľ����в���ĳ�������Ƿ���ڡ�
//Ҫ��ʱ�临�Ӷ�С��O��N��
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
		printf("�ҵ���\n");
	}
	else
	{
		printf("�Ҳ���\n");
	}
	return 0;
}