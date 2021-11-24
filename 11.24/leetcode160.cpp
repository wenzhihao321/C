#include<iostream>

//���������������ͷ�ڵ� headA �� headB ��
//�����ҳ������������������ཻ����ʼ�ڵ㡣
//����������������ཻ�ڵ㣬���� null ��
struct ListNode 
{
    int val;
    struct ListNode* next;  
};

void SListPrint(struct ListNode* hlist)
{
    struct ListNode* cur = hlist;
    while (cur != NULL)
    {
        printf("%d->", cur->val);
        cur = cur->next;
    }
    printf("NULL\n");
}
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
{
    //�ж��Ƿ�Ϊ��
    if (headA == NULL || headB == NULL)
    {
        return NULL;
    }
    struct ListNode* curA = headA;
    struct ListNode* curB = headB;
    int lenA = 0, lenB = 0;
    while (curA->next)
    {
        curA = curA->next;
        lenA++;
    }
    while (curB->next)
    {
        curB = curB->next;
        lenB++;
    }
    //���ཻ
    if (curA != curB)
    {
        return NULL;
    }
    struct ListNode* longlist = headA, * shortlist = headB;
    if (lenA < lenB)
    {
        longlist = headB;
        shortlist = headA;
    }
    int gap = abs(lenA - lenB);
    //�������߲�����
    while (gap--)
    {
        longlist = longlist->next;
    }
    while (longlist != shortlist)
    {
        longlist = longlist->next;
        shortlist = shortlist->next;
    }
    return longlist;
}
int main()
{
    struct ListNode* nodeA1=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* nodeA2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* nodeAB1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* nodeAB2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* nodeAB3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* nodeB1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* nodeB2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* nodeB3 = (struct ListNode*)malloc(sizeof(struct ListNode));

    nodeA1->val = 5;
    nodeA2->val = 9;
    nodeAB1->val = 1;
    nodeAB2->val = 2;
    nodeAB3->val = 3;
    nodeB1->val = 6;
    nodeB2->val = 4;
    nodeB3->val = 7;

    nodeA1->next = nodeA2;
    nodeA2->next = nodeAB1;
    nodeB1->next = nodeB2;
    nodeB2->next = nodeB3;
    nodeB3->next = nodeAB1;
    nodeAB1->next = nodeAB2;
    nodeAB2->next = nodeAB3;
    nodeAB3->next = NULL;

    struct ListNode* tmp=getIntersectionNode(nodeA1, nodeB1);
    SListPrint(tmp);
    return 0;
}