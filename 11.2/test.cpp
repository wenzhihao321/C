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
		printf("�����룺");
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
			printf("�˳�ͨѶ¼\n");
			break;
		default:
			printf("�������\n");
			break;
		}
	} while (input);
	return 0;
}