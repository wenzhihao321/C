#include<iostream>
//дһ�����룬��arr���飨�������飩���ҵ�7
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
			printf("�ҵ������ˣ��±��ǣ�%d\n", i);
			break;
		}
		
	}
	if (i == sz)
	{
		printf("�Ҳ���\n");
	}
	return 0;
}