#include<iostream>
using namespace std;
//计算时间复杂度
//F(N)=N^2+2*N+10
void Fun1(int N)
{
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			++count;
		}
	}
	for (int k = 0; k < 2 * N; k++)
	{
		++count;
	}
	int M = 10;
	while (M--)
	{
		++count;
	}
	printf("%d\n", count);
}
int main()
{
	Fun1(1000);
	return 0;
}