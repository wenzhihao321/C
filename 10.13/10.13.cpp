#include<iostream>
#include<stddef.h>
//设置默认对齐数为4
//#pragma pack(4)
//struct S
//{
//	char c1;//1
//	//7
//	int i;
//	double d;//8
//};
struct S
{
	char c1;
	int i;
	double d;
};
//设置默认对齐数为1
//一般设置为2的次方数
//#pragma pack(1)
//struct S
//{
//	char c1;//1
//	//3
//	int i;
//	double d;//8 4 4
//};
int main()
{
	//struct S s;
	//printf("%d/n", sizeof(s));
	printf("%d\n", offsetof(struct S, c1));
	printf("%d\n", offsetof(struct S, i));
	printf("%d\n", offsetof(struct S, d));
	return 0;
}
