#include"SList.h"

void TestSList1()
{
	SlistNode* hlist = NULL;
	SListPushBack(&hlist, 1);
	SListPushBack(&hlist, 2);
	SListPushBack(&hlist, 3);
	SListPushBack(&hlist, 4);
	SListPrint(hlist);
	//SListPushFront(&hlist, 0);
	//SListPrint(hlist);
	//SListPopBack(&hlist);
	//SListPrint(hlist);
	//SListPopFront(&hlist);
	//SListPrint(hlist);
	SlistNode* pos = SListFind(hlist,1);
	//����޸�����
	if (pos)
	{
		//pos->data = 520;
		printf("�ҵ��ˣ�\n");
	}
	else
	{
		printf("û���ҵ�!\n");
	}
	//SListInsetAfter(pos, 200);
	//SListPrint(hlist);
	//SListInsetBefore(&hlist,pos, 300);
	//SListPrint(hlist);
	//SListEraseBefore(&hlist, pos);
	//SListPrint(hlist);
	SListEraseCur(&hlist, pos);
	SListPrint(hlist);
}
int main()
{
	TestSList1();
	return 0;
}