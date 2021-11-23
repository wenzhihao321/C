#include<iostream>
//����һ��ͷ���Ϊ head �ķǿյ���������������м��㡣
//����������м��㣬�򷵻صڶ����м��㡣
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
	//1.��
	//2.�ǿ�
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