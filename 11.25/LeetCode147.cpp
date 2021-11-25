#include<iostream>
//对链表进行插入排序。
struct ListNode 
{
     int val;
     struct ListNode *next;
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
struct ListNode* insertionSortList(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    //1.初始条件
    struct ListNode* sortHead = head;
    struct ListNode* cur = head->next;
    sortHead->next = NULL;
    //2.终止条件
    while (cur)
    {
        //3.迭代条件
        struct ListNode* next = cur->next;
        struct ListNode* p = NULL, * c = sortHead;
        while (c)
        {
            if (cur->val < c->val)
            {
                break;
            }
            else
            {
                p = c;
                c = c->next;
            }
        }
        if (p == NULL)
        {
            cur->next = c;
            sortHead = cur;
        }
        else
        {
            p->next = cur;
            cur->next = c;
        }
        cur = next;
    }
    return sortHead;
}
int main()
{
    struct ListNode* a = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* b = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* c = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* d = (struct ListNode*)malloc(sizeof(struct ListNode));

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = nullptr;
    a->val = 4;
    b->val = 2;
    c->val = 1;
    d->val = 3;

    struct ListNode* tmp=insertionSortList(a);
    SListPrint(tmp);
    return 0;
}