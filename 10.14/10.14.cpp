#include<iostream>

struct S
{
	int i;
	char c;
	double d;
};
void Init(struct S* pa)
{
	pa->i = 327;
	pa->c = 'H';
	pa->d = 5.20;
}
void Print1(struct S tmp)
{
	printf("%d %c %lf\n", tmp.i, tmp.c, tmp.d);
}
void Print2(const struct S *pa)//�粻�뱻�޸Ŀ��ԼӸ�const,�����Ͳ��ᱻ�޸ġ�
{
	printf("%d %c %lf\n", pa->i,pa->c,pa->d);
}
int main()
{
	struct S s = { 0 };
	Init(&s);
	Print1(s);
	Print2(&s);
	return 0;
}