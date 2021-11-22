#pragma once
#include<iostream>
#include<assert.h>
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
SlistNode*SListFind(SlistNode* hlist, SlistType x);
void SListInsetAfter(SlistNode* pos, SlistType x);
void SListInsetBefore(SlistNode** hhlist,SlistNode* pos, SlistType x);
void SListEraseAfter(SlistNode* pos);
void SListEraseBefore(SlistNode** hhlist,SlistNode* pos);
void SListEraseCur(SlistNode** hhlist, SlistNode* pos);