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
//	//写文件
//	//fputc写一个字符
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
//	//关闭文件
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
//	//读文件
//  //fgetc读一个字符
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
//	//关闭文件
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
//	//读文件
//	//fgets读一行
//	char buf[1024] = { 0 };
//	fgets(buf,1024,pf);
//	//printf("%s\n", buf);
//	puts(buf);
//	//关闭文件
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
//	//写文件
//	//fputs写一行
//	fputs("hui*wo*zhen*de*hao*xiang*ni", pf);
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//	//从键盘读取一行文本信息
//	char buf[1024] = { 0 };
//	//fgets(buf, 1024, stdin);//从标准输入流读取
//	//fputs(buf, stdout);//输出到标准输出流
//
//	gets_s(buf);//默认从键盘读写
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
//	struct S s = { 520,13.14f,"惠" };
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	////格式化的形式写文件
//	//fprintf(pf, "%d %f %s", s.n, s.score, s.arr);
//	//fclose(pf);
//	//格式化的输入数据
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
//	struct S s = { 520,13.14f,"惠" };
//	fscanf(stdin, "%d %f %s", &(s.n), &(s.score), s.arr);
//	fprintf(stdout,"%d %f %s", s.n, s.score, s.arr);
//	//%.2f打印两位小数
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
	struct S s = { 520,13.14f,"惠" };
	struct S tmp = { 0 };
	char buf[1024] = { 0 };
	//把格式化的数据转换成字符串存储到buf
	sprintf(buf, "%d %f %s", s.n, s.score, s.arr);
	//printf("%s\n", buf);
	//从buf中读取格式化的数据到tmp中
	sscanf(buf, "%d %f %s", &(tmp.n), &(tmp.score), tmp.arr);
	printf("%d %f %s", tmp.n,tmp.score, tmp.arr);
	return 0;
}