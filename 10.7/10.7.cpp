#define _CRT_SECURE_NO_WARNINGS
#include<iostream>


//int main()
//{
//	//char arr[] = "192.168.31.121";
//	//const char* p = ".";
//	char arr[] = "С@��@��@ÿ@��@��@��@��@��@Ѽ";
//	const char* p = "@";
//	char buf[1024] = { 0 };
//	strcpy(buf, arr);
//	char* ret = NULL;
//	for (ret = strtok(buf, p); ret != NULL; ret = strtok(NULL, p))
//	{
//		printf("%s\n", ret);
//	}
//	return 0;
//}

int main()
{
	//0-No error
	//1-Operation not permitted
	//2-No such file or directory
	//...
	//errno��һ��ȫ�ֵĴ�����ı���
	//��c���ԵĿ⺯����ִ�й����У������˴��󣬾ͻ�Ѷ�Ӧ�Ĵ����룬��ֵ��errno��

//	char* str = strerror(2);
//	printf("%s\n", str);
	
	//���ļ�
	FILE* pf = fopen("tesr,txt", "r");
	if (pf == NULL)
	{
		printf("%s\n",)
	}
	return 0;
}