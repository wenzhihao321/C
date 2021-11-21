#include"SList.h"

void TestSList1()
{
	SlistNode* hlist = NULL;
	SListPushBack(&hlist, 1);
	SListPushBack(&hlist, 2);
	SListPushBack(&hlist, 3);
	SListPushBack(&hlist, 4);
	SListPrint(hlist);
	SListPushFront(&hlist, 0);
	SListPrint(hlist);
	SListPopBack(&hlist);
	SListPrint(hlist);
	SListPopFront(&hlist);
	SListPrint(hlist);
}
int main()
{
	TestSList1();
	return 0;
}