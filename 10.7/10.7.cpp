#define _CRT_SECURE_NO_WARNINGS
#include<iostream>


//int main()
//{
//	//char arr[] = "192.168.31.121";
//	//const char* p = ".";
//	char arr[] = "小@惠@我@每@天@都@好@想@你@鸭";
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
	//errno是一个全局的错误码的变量
	//当c语言的库函数在执行过程中，发生了错误，就会把对应的错误码，赋值到errno中

//	char* str = strerror(2);
//	printf("%s\n", str);
	
	//打开文件
	FILE* pf = fopen("tesr,txt", "r");
	if (pf == NULL)
	{
		printf("%s\n",)
	}
	return 0;
}