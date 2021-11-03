#include"dong contact.h"
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
	struct contact con;
	Initcontact(&con);
	do
	{
		menu();
		printf("请输入：");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			addcontact(&con);
			break;
		case DEL:
			delcontact(&con);
			break;
		case SEARCH:
			searchcontact(&con);
			break;
		case MODIFY:
			moidfycontact(&con);
			break;
		case SHOW:
			showcontact(&con);
			break;
		case SORT:
			sortcontact(&con);
			break;
		case EXIT:
			destroycontact(&con);
			printf("退出通讯录\n");
			break;
		default:
			printf("输入错误\n");
			break;
		}
	} while (input);
	return 0;
}