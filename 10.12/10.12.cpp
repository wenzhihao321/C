#include<iostream>

struct S1
{
	char a;
	char b;
	int i;
};
struct S2
{
	char a;
	double b;
	int i;
	int u;
};
struct S3
{
	double w;
	char b;
	int i;
	char e;
	double c;
}; 
struct S4
{
	char a;
	struct S3 s3;
	struct S1 s1;
	double b;
};
int main()
{
	struct S1 s1 = { 0 };
	printf("%d\n", sizeof(s1));
	struct S2 s2 = { 0 };
	printf("%d\n", sizeof(s2));
	struct S3 s3 = { 0 };
	printf("%d\n", sizeof(s3));
	struct S4 s4 = { 0 };
	printf("%d\n", sizeof(s4));
	return 0;
}