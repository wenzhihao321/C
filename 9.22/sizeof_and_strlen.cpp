#include<iostream>
using namespace std;
int main()
{
	//һά����
	int a[] = { 1,2,3,4 };
	printf("%d\n", sizeof(a));//16 sizeof(������) ���������ܴ�С 
	printf("%d\n", sizeof(a + 0));//4/8 ��Ԫ�ص�ַ
	printf("%d\n", sizeof(*a));//4  ��Ԫ��
	printf("%d\n", sizeof(a + 1));//4/8
	printf("%d\n", sizeof(a[1]));//4
	printf("%d\n", sizeof(&a));//4/8 ȡ����ַ��С
	printf("%d\n", sizeof(*&a));//16
	printf("%d\n", sizeof(&a+1));//4/8  &a�������ַ +1�������������鵫���ǵ�ַ
	printf("%d\n", sizeof(&a[0]));//4/8 
	printf("%d\n", sizeof(&a[0] + 1));//4/8 

	//�ַ�����
	char arr[] = { 'a','b','c','d','e','f' };
	printf("%d\n", strlen(arr));//���ֵ
	printf("%d\n", strlen(arr + 0));//���ֵ
	printf("%d\n", strlen(*arr));//err	
	printf("%d\n", strlen(arr[1]));//err
	printf("%d\n", strlen(&arr));//���ֵ
	printf("%d\n", strlen(&arr + 1));//���ֵ-6
	printf("%d\n", strlen(&arr[0] + 1));//���ֵ-1

	printf("%d\n", sizeof(arr));//6 sizeof���������������Ĵ�С
	printf("%d\n", sizeof(arr+0));//4/8 ��Ԫ�صĵ�ַ
	printf("%d\n", sizeof(*arr));//1  arr����Ԫ�ص�ַ *arr����Ԫ��	
	printf("%d\n", sizeof(arr[1]));//1
	printf("%d\n", sizeof(&arr));//4/8 �����ַ
	printf("%d\n", sizeof(&arr+1));//4/8
	printf("%d\n", sizeof(&arr[0]+1));//4/8

	const char arr[] = "abcdef";
	printf("%d\n", strlen(arr));//6  strlen����'\0'��ֹ
	printf("%d\n", strlen(arr + 0));//6
	printf("%d\n", strlen(*arr));//err	
	printf("%d\n", strlen(arr[1]));//err
	printf("%d\n", strlen(&arr));//6
	printf("%d\n", strlen(&arr + 1));//���ֵ
	printf("%d\n", strlen(&arr[0] + 1));//5

	printf("%d\n", sizeof(arr));//7 sizeof���������������Ĵ�С
	printf("%d\n", sizeof(arr + 0));//4/8 ��Ԫ�صĵ�ַ
	printf("%d\n", sizeof(*arr));//1  arr����Ԫ�ص�ַ *arr����Ԫ��	
	printf("%d\n", sizeof(arr[1]));//1
	printf("%d\n", sizeof(&arr));//4/8 �����ַ
	printf("%d\n", sizeof(&arr + 1));//4/8 ����һ������ĵ�ַ
	printf("%d\n", sizeof(&arr[0] + 1));//4/8 �ڶ���Ԫ�صĵ�ַ

	 const char* p = "abcdef";
	 printf("%d\n", strlen(p));//6  strlen����'\0'��ֹ
	 printf("%d\n", strlen(p + 1));//5
	 //printf("%d\n", strlen(*p));//err	
	 //printf("%d\n", strlen(p[1]));//err
	 printf("%d\n", strlen(&p));//���ֵ ��ַ����ʲôʱ������'\0'��ȷ��
	 printf("%d\n", strlen(&p + 1));//���ֵ 
	 printf("%d\n", strlen(&p[0] + 1));//5

	 printf("%d\n", sizeof(p));//4/8 -����ָ������Ĵ�С
	 printf("%d\n", sizeof(p + 1));//4/8 - p+1 �õ����ַ�b�Ĵ�С
	 printf("%d\n", sizeof(*p));//1  arr����Ԫ�ص�ַ *arr����Ԫ��	
	 printf("%d\n", sizeof(p[0]));//1
	 printf("%d\n", sizeof(&p));//4/8 �����ַ
	 printf("%d\n", sizeof(&p + 1));//4/8 ����һ������ĵ�ַ
	 printf("%d\n", sizeof(&p[0] + 1));//4/8 �ڶ���Ԫ�صĵ�ַ

	 int a[3][4] = { 0 };
	 printf("%d\n", sizeof(a));//48 - 3*4*4=48
	 printf("%d\n", sizeof(a[0][0]));//4 -  һ�����͵Ĵ�С
	 printf("%d\n", sizeof(a[0]));//16  a[0]�൱�ڵ�һ����Ϊһά�����������
	                              // ��һ�е������С	
	 printf("%d\n", sizeof(a[0]+1));//4/8 ��һ������ĵڶ�����ַ
	 printf("%d\n", sizeof(*(a[0] + 1)));//4
	 printf("%d\n", sizeof(a + 1));//4  a�Ƕ�ά�������������û��sizeof��a����Ҳû��&��a��������a����Ԫ�صĵ�ַ
	 //���Ѷ�ά���鿴��һά����ʱ����ά�������Ԫ�������ĵ�һ�У�a���ǵ�һ�У���Ԫ�أ��ĵ�ַ
	 //a+1���ǵڶ��еĵ�ַ
	 printf("%d\n", sizeof(*(a + 1)));//16
	 printf("%d\n", sizeof(&a[0] + 1));//4/8 �ڶ�������ĵ�ַ
	 printf("%d\n", sizeof(*(&a[0] + 1)));//16 �ڶ�������Ĵ�С
	 printf("%d\n", sizeof(*a));//16 a����Ԫ�ص�ַ - ��һ�е�ַ��*a���ǵ�һ�У�sizeof��*a�����Ǽ����һ�еĴ�С
	 printf("%d\n", sizeof(a[3]));//16 

	 return 0;
}