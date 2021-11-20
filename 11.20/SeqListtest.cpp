#include"SeqList_g.h"
void menu()
{
	printf("***************************************\n");
	printf("****    1.头插     2.尾插        ******\n");
	printf("****    3.头删     4.尾删        ******\n");
	printf("****    5.查找     6.打印        ******\n");
	printf("****    0.退出                   ******\n");
	printf("***************************************\n");
}
int main()
{
	SeqList s;
	SeqListInit(&s);
	int input = 0;
	do
	{
		menu();
		int x = 0;
		int a = 0;
		printf("请输入操作数字：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("请输入要头插的数字，以-1结束：");
			while (1)
			{
				scanf("%d", &x);
				if (x == -1)
				{
					break;
				}
				SeqListPushFront(&s, x);
			}
			break;
		case 2:
			printf("请输入要头插的数字，以-1结束：");
			while (1)
			{
				scanf("%d", &x);
				if (x == -1)
				{
					break;
				}
				SeqListPushBack(&s, x);
			}
			break;
		case 3:
			SeqListPopFront(&s);
			break;
		case 4:
			SeqListPopBack(&s);
			break;
		case 5:
			printf("请输入要查找的数字:");
			scanf("%d", &x);
			a = SeqListFind(&s, x);
			if (a != -1)
			{
				printf("你查找的数字的下标为%d\n", a);
			}
			else
			{
				printf("查找失败，无此数字！\n");
			}
			break;
		case 6:
			SeqListPrint(&s);
			break;
		case 0:
			break;
		default:
			printf("输入错误，请重新输入！\n");
			break;
		}
	} while (input);
	SeqListDestory(&s);
	return 0;
}