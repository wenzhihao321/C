#pragma once
#include<iostream>
#include<assert.h>

typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;//栈顶
	int capacity;//容量，方便增容
}Stack;
void StackInit(Stack* pst);
void StackDestroy(Stack* pst);

void StackPush(Stack* pst, STDataType x);
void StackPop(Stack* pst);
//取栈顶的值
STDataType StackTop(Stack* pst);

//空返回1，非空返回0
bool StackEmpty(Stack* pst);
int StackSize(Stack* pst);