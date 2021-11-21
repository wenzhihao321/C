#include"SList.h"

void SListPrint(SlistNode* hlist)
{
	SlistNode* cur = hlist;
	while (cur != NULL)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}
SlistNode* BuySlistNode(SlistType x)
{
	SlistNode* node = (SlistNode*)malloc(sizeof(SlistNode));
	node->data = x;
	node->next = NULL;
	return node;
}
void SListPushBack(SlistNode** hhlist, SlistType x)
{
	SlistNode* newnode = BuySlistNode(x);
	//1.空
	//2.非空
	if (*hhlist==NULL)
	{
		*hhlist = newnode;
	}
	else
	{
		SlistNode* tail = *hhlist;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}
void SListPushFront(SlistNode** hhlist, SlistType x)
{
	SlistNode* newnode = BuySlistNode(x);
	newnode->next = *hhlist;
	*hhlist = newnode;
}
void SListPopBack(SlistNode** hhlist)
{
	//1.没有节点
	//2.一个节点
	//3.多个节点
	if (*hhlist == NULL)
	{
		return;
	}
	else if ((*hhlist)->next==NULL)
	{
		free(*hhlist);
		*hhlist = NULL;
	}
	else
	{
		SlistNode* tail = *hhlist;
		SlistNode* prev = NULL;
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		tail = NULL;
		prev->next = NULL;
	}
}
void SListPopFront(SlistNode** hhlist)
{
	if (*hhlist == NULL)
	{
		return;
	}
	else
	{
		SlistNode* next = (*hhlist)->next;
		free(*hhlist);
		*hhlist = next;
	}
}