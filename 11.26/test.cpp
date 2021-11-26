#include"List.h"	

void testlist()
{
	ListNode* phead = ListNodeInit();
	ListPushback(phead, 1);
	Print(phead);
	ListPushback(phead, 2);
	ListPushback(phead, 3);
	ListPushback(phead, 4);
	Print(phead);
	ListPushfront(phead, 4);
	Print(phead);
	ListPopback(phead);
	Print(phead);
	ListNode* pos = ListFind(phead, 3);
	ListInset(pos, 5);
	ListErase(pos);
	Print(phead);
	ListDestory(phead);
	free(phead);
}


int main()
{
	testlist();
	return 0;
}