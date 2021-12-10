#pragma once
#include<iostream>
#include<assert.h>

typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;//ջ��
	int capacity;//��������������
}Stack;
void StackInit(Stack* pst);
void StackDestroy(Stack* pst);

void StackPush(Stack* pst, STDataType x);
void StackPop(Stack* pst);
//ȡջ����ֵ
STDataType StackTop(Stack* pst);

//�շ���1���ǿշ���0
bool StackEmpty(Stack* pst);
int StackSize(Stack* pst);