#include<iostream>
using namespace std;
//写一个函数求a的二进制（补码）表示中有几个1
//int get_bit_one(int n)
//{
//	int count = 0;
//	while (n)
//	{
//		if (n % 2 == 1)
//		{
//			count++;
//		}
//		n = n / 2;
//	}
//	return count;
//}
//改进1
//int get_bit_one(unsigned int n)
//{
//	int count = 0;
//	while (n)
//	{
//		if (n % 2 == 1)
//		{
//			count++;
//		}
//		n = n / 2;
//	}
//	return count;
//}
//改进2
//int get_bit_one(unsigned int n)
//{
//	int count = 0;
//	int i = 0;
//	for (i = 0; i < 32; i++)
//	{
//		if (((n >> i) & 1)==1)
//		{
//			count++;
//		}
//	}
//	return count;
//}
//改进3
int get_bit_one(unsigned int n)
{
	int count = 0;
	while (n)
	{
		n=n& (n - 1);
		count++;
	}
	return count;
}
int main()
{
	int n = 0;
	cin >> n;
	int count = get_bit_one(n);
	cout << count;
	return 0;
}
