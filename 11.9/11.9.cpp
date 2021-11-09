#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

//int main()
//{
//	FILE* pf = fopen("text.txt", "r");
//	if (pf == NULL);
//	{
//		return 0;
//	}
//	//定位文件指针
//	//fseek(pf, -2, SEEK_END);
//	fgetc(pf);
//	int pos = ftell(pf);//ftell(pf)相对于起始位置的偏移量
//	printf("%d\n", pos);
//	//读取文件
//	//int ch=fgetc(pf);
//	//printf("%c\n", ch);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//	FILE* pf = fopen("text.txt", "r");
//	if (pf == NULL);
//	{
//		return 0;
//	}
//	rewind(pf);
//	int ch=fgetc(pf);
//	printf("%c\n", ch);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

int main()
{
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL);
	{
		perror("open file test.txt");
		return 0;
	}
	//读文件
	int ch = 0;
	while ((ch = fgetc(pf)) != EOF)
	{
		putchar(ch);
	}
	if (ferror(pf))
	{
		printf("error\n");
	}
	else if (feof(pf))
	{
		printf("end of file\n");
	}
	fclose(pf);
	pf = NULL;
	return 0;
}