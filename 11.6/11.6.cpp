#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

//int main()
//{
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	//д�ļ�
//	//fputcдһ���ַ�
//	fputc('h', pf);
//	fputc('u', pf);
//	fputc('i', pf);
//	fputc('w', pf);
//	fputc('o', pf);
//	fputc('h', pf);
//	fputc('a', pf);
//	fputc('o',pf);
//	fputc('x', pf);
//	fputc('i', pf);
//	fputc('a', pf);
//	fputc('n', pf);
//	fputc('g', pf);
//	fputc('n', pf);
//	fputc('i', pf);
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	//���ļ�
//  //fgetc��һ���ַ�
//	int ch = fgetc(pf);
//	printf("%c", ch);
//	ch = fgetc(pf);
//	printf("%c", ch);
//	ch = fgetc(pf);
//	printf("%c", ch);
//	ch = fgetc(pf);
//	printf("%c", ch);
//	ch = fgetc(pf);
//	printf("%c", ch);
//	ch = fgetc(pf);
//	printf("%c", ch);
//	ch = fgetc(pf);
//	printf("%c", ch);
//	ch = fgetc(pf);
//	printf("%c", ch);
//	ch = fgetc(pf);
//	printf("%c", ch);
//	ch = fgetc(pf);
//	printf("%c", ch);
//	ch = fgetc(pf);
//	printf("%c", ch);
//	ch = fgetc(pf);
//	printf("%c", ch);
//	ch = fgetc(pf);
//	printf("%c", ch);
//	ch = fgetc(pf);
//	printf("%c", ch);
//	ch = fgetc(pf);
//	printf("%c", ch);
//
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	//���ļ�
//	//fgets��һ��
//	char buf[1024] = { 0 };
//	fgets(buf,1024,pf);
//	//printf("%s\n", buf);
//	puts(buf);
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	//д�ļ�
//	//fputsдһ��
//	fputs("hui*wo*zhen*de*hao*xiang*ni", pf);
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//	//�Ӽ��̶�ȡһ���ı���Ϣ
//	char buf[1024] = { 0 };
//	//fgets(buf, 1024, stdin);//�ӱ�׼��������ȡ
//	//fputs(buf, stdout);//�������׼�����
//
//	gets_s(buf);//Ĭ�ϴӼ��̶�д
//	puts(buf);
//
//	return 0;
//}

//struct S
//{
//	int n;
//	float score;
//	char arr[10];
//};
//int main()
//{
//	struct S s = { 520,13.14f,"��" };
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	////��ʽ������ʽд�ļ�
//	//fprintf(pf, "%d %f %s", s.n, s.score, s.arr);
//	//fclose(pf);
//	//��ʽ������������
//	fscanf(pf,"%d %f %s", &(s.n), &(s.score), s.arr);
//	printf("%d %f %s", s.n, s.score, s.arr);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//struct S
//{
//	int n;
//	float score;
//	char arr[10];
//};
//int main()
//{
//	struct S s = { 520,13.14f,"��" };
//	fscanf(stdin, "%d %f %s", &(s.n), &(s.score), s.arr);
//	fprintf(stdout,"%d %f %s", s.n, s.score, s.arr);
//	//%.2f��ӡ��λС��
//	return 0;
//}

struct S
{
	int n;
	float score;
	char arr[10];
};
int main()
{
	struct S s = { 520,13.14f,"��" };
	struct S tmp = { 0 };
	char buf[1024] = { 0 };
	//�Ѹ�ʽ��������ת�����ַ����洢��buf
	sprintf(buf, "%d %f %s", s.n, s.score, s.arr);
	//printf("%s\n", buf);
	//��buf�ж�ȡ��ʽ�������ݵ�tmp��
	sscanf(buf, "%d %f %s", &(tmp.n), &(tmp.score), tmp.arr);
	printf("%d %f %s", tmp.n,tmp.score, tmp.arr);
	return 0;
}