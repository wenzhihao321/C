#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
void meun()
{
	printf("*****************************\n");
	printf("***  1.�ӷ�      2.����   ***\n");
	printf("***  3.�˷�      4.����   ***\n");
	printf("***        0.�˳�         ***\n");
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
	printf("������Ҫ����������������֣�");
	scanf("%d%d", &x, &y);
	printf("%d\n",pt(x ,y));
}
int main()
{
	int input = 0;
	do
	{
		meun();
		printf("��ѡ��");
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
			printf("�˳�\n");
			break;
		default:
			printf("�����������������\n");
			break;
		}
	} while (input);
	return 0;
}
