#pragma once

#include<iostream>
#include<assert.h>
typedef int SeqDataType;

typedef struct SeqList
{
	SeqDataType* a;
	int size;//有效数据的个数
	int capacity;//容量
}SeqList;

//内存中管理数据的结构增删查改的接口

//头插尾插，头删尾删

void SeqListPrint(SeqList* pq);
void SeqListInit(SeqList* pq);
void SeqListDestory(SeqList* pq);
void SeqListPushBack(SeqList* pq, SeqDataType x);
void SeqListPushFront(SeqList* pq, SeqDataType x);
void SeqListPopBack(SeqList* pq);
void SeqListPopFront(SeqList* pq);