#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

//int main()
//{
//	int a = 10000;
//	FILE* pf = fopen("test.txt", "wb");
//	fwrite(&a, 4, 1, pf);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

int main()
{
	//打开文件test.txt
	//相对路径
	//.. 表示上一级路径
	//. 表示当前路径 
	//fopen("../../test.txt","r")
	//fopen("test.txt","r");

	//绝对路径的写法
	FILE*pf=fopen("C:\\Users\\紫夜\\source\\repos\\11.5\\11.5\\test.txt", "w");
	if (pf == NULL)
	{
		printf("%s\n", strerror(errno));
		return 0;
	}
	//打开成功
	//读文件
	//关闭文件
	fclose(pf);
	pf = NULL;
	return 0;
}