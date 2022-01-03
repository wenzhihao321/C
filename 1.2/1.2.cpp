#include<iostream>
using namespace std;

struct Stack
{
	int* a;
	int size;
	int capacity;
};
void StackInit(struct Stack*p,int InitCapacity=4)
{
	p->a = (int*)malloc(sizeof(int) * InitCapacity);
	p->size = 0;
	p->capacity = InitCapacity;
}
int main()
{
	struct Stack st1;
	//假设我知道栈里面至少要存100个数据
	StackInit(&st1, 100);
	struct Stack st2;
	//假设我知道栈里面至少要存10个数据
	StackInit(&st2, 10);
	struct Stack st3;
	//假设我不知道栈里面要多少个数据，就不传InitCapacity就会直接使用缺省参数
	StackInit(&st3);
	return 0;
}