#pragma once

#include<iostream>
#include<assert.h>
typedef int SeqDataType;

typedef struct SeqList
{
	SeqDataType* a;
	int size;//��Ч���ݵĸ���
	int capacity;//����
}SeqList;

//�ڴ��й������ݵĽṹ��ɾ��ĵĽӿ�

//ͷ��β�壬ͷɾβɾ

void SeqListPrint(SeqList* pq);
void SeqListInit(SeqList* pq);
void SeqListDestory(SeqList* pq);
void SeqListPushBack(SeqList* pq, SeqDataType x);
void SeqListPushFront(SeqList* pq, SeqDataType x);
void SeqListPopBack(SeqList* pq);
void SeqListPopFront(SeqList* pq);