#include<iostream>
//给定一个头结点为 head 的非空单链表，返回链表的中间结点。
//如果有两个中间结点，则返回第二个中间结点。
struct ListNode 
{
    int data;
    struct ListNode* next;
};
struct ListNode* middleNode(struct ListNode* head)
{
    struct ListNode* fast = head, * slow = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
struct ListNode* BuySlistNode(int x)
{
	struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
	node->data = x;
	node->next = NULL;
	return node;
}
void SListPushBack(struct ListNode** hhlist, int x)
{
	struct ListNode* newnode = BuySlistNode(x);
	//1.空
	//2.非空
	if (*hhlist == NULL)
	{
		*hhlist = newnode;
	}
	else
	{
		struct ListNode* tail = *hhlist;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}
void SListPrint(struct ListNode* hlist)
{
	struct ListNode* cur = hlist;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}
int main()
{
	struct ListNode* hlist = NULL;
	SListPushBack(&hlist, 1);
	SListPushBack(&hlist, 2);
	SListPushBack(&hlist, 3);
	SListPushBack(&hlist, 4);
	SListPrint(hlist);
	struct ListNode* tmp = middleNode(hlist);
	SListPrint(tmp);
}