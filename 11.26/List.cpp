#include"List.h"

void Print(ListNode* phead)
{
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}
ListNode* BuyListNode(LTDataType x)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = x;
	node->next = NULL;
	node->prev = NULL;
	return node;
}
ListNode* ListNodeInit()
{
	ListNode* phead = BuyListNode(0);
	phead->next = phead;
	phead->prev = phead;
	return phead;
}
void ListPushback(ListNode* phead, LTDataType x)
{
	//assert(phead);
	//ListNode* tail = phead->prev;
	//ListNode* newnode = BuyListNode(x);
	//tail->next = newnode;
	//newnode->prev = tail;
	//newnode->next = phead;
	//phead->prev = newnode;
	ListInset(phead, x);
}
void ListPushfront(ListNode* phead, LTDataType x)
{
	//assert(phead);
	//ListNode* next = phead->next;
	//ListNode* newnode = BuyListNode(x);
	//phead->next = newnode;
	//newnode->next = next;
	//next->prev = newnode;
	//newnode->prev = phead;
	ListInset(phead->next, x);
}
void ListPopback(ListNode* phead)
{
	//assert(phead);
	//assert(phead != phead->prev);
	//ListNode* tail = phead->prev;
	//ListNode* tailprev = tail->prev;
	//free(tail);
	//phead->prev = tailprev;
	//tailprev->next = phead;
	ListErase(phead->prev);
}
void ListPopfront(ListNode* phead)
{
	//assert(phead);
	//assert(phead != phead->prev);
	//ListNode* cur = phead->next;
	//ListNode* next = cur->next;
	//free(cur);
	//cur = NULL;
	//phead->next = next;
	//next->prev = phead;
	ListErase(phead->next);
}
ListNode* ListFind(ListNode* phead, LTDataType x)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
void ListInset(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* newnode = BuyListNode(x);
	ListNode* posPrev = pos->prev;
	posPrev->next = newnode;
	newnode->next = pos;
	pos->prev = newnode;
	newnode->prev = posPrev;
}
void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* posNext = pos->next;
	ListNode* posPrev = pos->prev;
	free(pos);
	posPrev->next = posNext;
	posNext->prev = posPrev;
}
int ListEmpty(ListNode* phead)
{
	assert(phead);
	return phead->next == phead ? 1 : 0;
	//return phead->next == phead;
}
int ListSize(ListNode* phead)
{
	assert(phead);
	int size = 0;
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		size++;
		cur = cur->next;
	}
	return size;
}
void ListDestory(ListNode* phead)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}
}