#pragma once
#include<iostream>
#include<stdio.h>
#include<assert.h>

typedef int LTDataType;
typedef struct ListNode
{
	ListNode* next;
	ListNode* prev;
	LTDataType data;
}ListNode;
void Print(ListNode* phead);
ListNode* BuyListNode(LTDataType x);
ListNode* ListNodeInit();
void ListPushback(ListNode*phead,LTDataType x);
void ListPushfront(ListNode* phead, LTDataType x);
void ListPopback(ListNode* phead);
void ListPopfront(ListNode* phead);
ListNode* ListFind(ListNode* phead, LTDataType x);
void ListInset(ListNode* pos, LTDataType x);
void ListErase(ListNode* pos);
//¿Õ·µ»Ø1£¬·Ç¿Õ·µ»Ø0
int ListEmpty(ListNode* phead);
int ListSize(ListNode* phead);
void ListDestory(ListNode* phead);