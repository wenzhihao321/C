#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

//int main()
//{
//	FILE* pf = fopen("text.txt", "r");
//	if (pf == NULL);
//	{
//		return 0;
//	}
//	//��λ�ļ�ָ��
//	//fseek(pf, -2, SEEK_END);
//	fgetc(pf);
//	int pos = ftell(pf);//ftell(pf)�������ʼλ�õ�ƫ����
//	printf("%d\n", pos);
//	//��ȡ�ļ�
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
	//���ļ�
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