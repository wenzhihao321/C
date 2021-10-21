#include"contact.h"
void menu()
{
	printf("***********************************\n");
	printf("*****  1.add        2.del    ******\n");
	printf("*****  3.search     4.modify ******\n");
	printf("*****  5.show       6.sort   ******\n");
	printf("*****        0.exit          ******\n");
	printf("***********************************\n");
}

int main()
{
	int input;
	struct contact con[max];
	do
	{
		menu();
		printf("请输入：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			addcontact(con);
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 0:
			printf("退出通讯录\n");
			break;
		default:
			printf("输入错误\n");
			break;
		}
	} while (input);
	return 0;
}