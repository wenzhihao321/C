#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
void meun()
{
	printf("*****************************\n");
	printf("***  1.加法      2.减法   ***\n");
	printf("***  3.乘法      4.除法   ***\n");
	printf("***        0.退出         ***\n");
	printf("*****************************\n");
}
int Add(int x, int y)
{
	return x + y;
}
int Sub(int x, int y)
{
	return x - y;
}
int Mul(int x, int y)
{
	return x * y;
}
int Div(int x, int y)
{
	return x / y;
}
void Calc(int(*pt)(int,int))
{
	int x = 0;
	int y = 0;
	printf("请输入要进行运算的两个数字：");
	scanf("%d%d", &x, &y);
	printf("%d\n",pt(x ,y));
}
int main()
{
	int input = 0;
	do
	{
		meun();
		printf("请选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			
			Calc(Add);
			break;
		case 2:
			Calc(Sub);
			break;
		case 3:
			Calc(Mul);
			break;
		case 4:
			Calc(Div);
			break;
		case 0:
			printf("退出\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	} while (input);
	return 0;
}
