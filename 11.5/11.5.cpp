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
	//���ļ�test.txt
	//���·��
	//.. ��ʾ��һ��·��
	//. ��ʾ��ǰ·�� 
	//fopen("../../test.txt","r")
	//fopen("test.txt","r");

	//����·����д��
	FILE*pf=fopen("C:\\Users\\��ҹ\\source\\repos\\11.5\\11.5\\test.txt", "w");
	if (pf == NULL)
	{
		printf("%s\n", strerror(errno));
		return 0;
	}
	//�򿪳ɹ�
	//���ļ�
	//�ر��ļ�
	fclose(pf);
	pf = NULL;
	return 0;
}