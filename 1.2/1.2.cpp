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
	//������֪��ջ��������Ҫ��100������
	StackInit(&st1, 100);
	struct Stack st2;
	//������֪��ջ��������Ҫ��10������
	StackInit(&st2, 10);
	struct Stack st3;
	//�����Ҳ�֪��ջ����Ҫ���ٸ����ݣ��Ͳ���InitCapacity�ͻ�ֱ��ʹ��ȱʡ����
	StackInit(&st3);
	return 0;
}