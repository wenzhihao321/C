#pragma once
#include<iostream>
typedef int SlistType;
typedef struct SlistNode
{
	SlistType data;
	struct SlistNode* next;
}SlistNode;
void SListPrint(SlistNode*hlist);
void SListPushBack(SlistNode** hhlist, SlistType x);
void SListPushFront(SlistNode** hhlist, SlistType x);
void SListPopBack(SlistNode** hhlist);
void SListPopFront(SlistNode** hhlist);