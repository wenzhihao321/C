#include<iostream>
using namespace std;
//非递归n的阶乘
int fac1(int k)
{
	int i = 0;
	int ret = 1;
	for (i = 1; i <= k; i++)
	{
		ret *= i;
	}
	return ret;
}
//递归n的阶乘
int fac2(int k)
{
	if (k <= 1)
	{
		return 1;
	}
	else
	{
		return k * fac2(k - 1);
	}
}
int main()
{
	int k = 1;
	int ret = 0;
	cin >> k;
	ret = fac1(k);
	cout << ret<<endl;
	ret = fac2(k);
	cout << ret<<endl;
	return 0;
}