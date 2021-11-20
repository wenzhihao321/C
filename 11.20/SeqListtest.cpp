#include"SeqList_g.h"
void menu()
{
	printf("***************************************\n");
	printf("****    1.ͷ��     2.β��        ******\n");
	printf("****    3.ͷɾ     4.βɾ        ******\n");
	printf("****    5.����     6.��ӡ        ******\n");
	printf("****    0.�˳�                   ******\n");
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
		printf("������������֣�");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("������Ҫͷ������֣���-1������");
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
			printf("������Ҫͷ������֣���-1������");
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
			printf("������Ҫ���ҵ�����:");
			scanf("%d", &x);
			a = SeqListFind(&s, x);
			if (a != -1)
			{
				printf("����ҵ����ֵ��±�Ϊ%d\n", a);
			}
			else
			{
				printf("����ʧ�ܣ��޴����֣�\n");
			}
			break;
		case 6:
			SeqListPrint(&s);
			break;
		case 0:
			break;
		default:
			printf("����������������룡\n");
			break;
		}
	} while (input);
	SeqListDestory(&s);
	return 0;
}