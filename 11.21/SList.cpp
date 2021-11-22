#include"SList.h"

void SListPrint(SlistNode* hlist)
{
	SlistNode* cur = hlist;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
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
SlistNode*SListFind(SlistNode* hlist, SlistType x)
{
	SlistNode* cur = hlist;
	//while(cur!=NULL)
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
void SListInsetAfter(SlistNode* pos, SlistType x)
{
	assert(pos);
	SlistNode* newnode = BuySlistNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}
void SListInsetBefore(SlistNode** hhlist,SlistNode* pos, SlistType x)
{
	assert(pos);
	SlistNode* newnode = BuySlistNode(x);
	if (pos == *hhlist)//头插
	{
		newnode->next = pos;
		*hhlist = newnode;
	}
	else
	{
		SlistNode* cur = *hhlist;
		SlistNode* prev = NULL;
		while (cur != pos)
		{
			prev = cur;
			cur = cur->next;
		}
		prev->next = newnode;
		newnode->next = pos;
	}
}
void SListEraseAfter(SlistNode* pos)
{
	assert(pos);
	if (pos->next == NULL)
	{
		return;
	}
	else
	{
		SlistNode* next = pos->next;
		pos->next =next->next;
		free(next);
	}
}
void SListEraseBefore(SlistNode** hhlist, SlistNode* pos)
{
	assert(pos);
	if (pos == *hhlist)
	{
		return;
	}
	else
	{
		SlistNode* cur = *hhlist;
		if ((*hhlist)->next==pos)
		{
			*hhlist = pos;
			free(cur);
			cur = NULL;
		}
		else
		{
			while ((*hhlist)->next != pos)
			{
				cur = cur->next;
			}
			(*hhlist)->next = pos;
			free(cur);
			cur = NULL;
		}
	}
}
void SListEraseCur(SlistNode** hhlist, SlistNode* pos)
{
	assert(pos);
	if (pos == *hhlist)
	{
		(*hhlist) = pos->next;
		free(pos);
		pos = NULL;
	}
	else
	{
		SlistNode* cur = *hhlist;
		SlistNode* prev = NULL;
		while (cur != pos)
		{
			prev = cur;
			cur = cur->next;
		}
		prev->next = cur->next;
		free(cur);
		cur = NULL;
	}
}
