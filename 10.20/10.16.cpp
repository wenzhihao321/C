#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<assert.h>
//strlen
// 1.�������ķ���
//int my_strlen(const char* arr)
//{
//  assert(arr != NULL);
//	int count = 0;
//	while (*arr!='\0')
//	{
//		arr++;
//		count++;
//	}
//	return count;
//}

 //2.�ݹ�
//int my_strlen(const char* arr)
//{
//	assert(arr != NULL);
//	while (*arr != '\0')
//	{
//		return 1+ my_strlen(arr+1);
//	}
//}

//3.ָ��
//int my_strlen(const char* arr)
//{
//  assert(arr != NULL);
//  const char* ret = arr;
//	while (*arr!='\0')
//	{
//		arr++;
//	}
//	return arr-ret;
//}
//int main()
//{
//	char arr[] = "���Һ�ϲ����";
//	int ret=my_strlen(arr);
//	printf("%d\n", ret);
//	return 0;
//}



////strcpy  strncpy
////char* my_strcpy(char* a1, char* a2)
////{
////	assert(a1 != NULL);
////	assert(a2 != NULL);
////	char* ret = a1;
////	while (*a2)
////	{
////		*a1 = *a2;
////		a1++;
////		a2++;
////	}
////	return ret;
////}
//
//char* my_strncpy(char* a1,const char* a2,int x)
//{
//	assert(a1 != NULL);
//	assert(a2 != NULL);
//	char* ret = a1;
//	while (x)
//	{
//		if((*a1)&&(*a2))
//		{
//			*a1 = *a2;
//			a1++;
//			a2++;
//			x--;
//		}
//	}
//	return ret;
//}
//int main()
//{
//	char arr1[20] = "************������";
//	char arr2[] = "���Һ�ϲ���㰡";
//	//char*ret=my_strcpy(arr1,arr2);
//	char* ret = my_strncpy(arr1, arr2,strlen(arr2));
//	printf("%s\n", ret);
//	return 0;
//}



//strcmp  strncmp
////int my_strcmp(const char*a1,const char*a2)
////{
////	assert(a1 != NULL);
////	assert(a2 != NULL);
////	while (*a1 == *a2)
////	{
////		if (*a1 == '\0')
////		{
////			return 0;
////		}
////		a1++;
////		a2++;
////	}
////	//if (*a1 > *a2)
////	//{
////	//	return 1;
////	//}
////	//else
////	//{
////	//	return -1;
////	//}
////	return (*a1 - *a2);
////}
// 
//int my_strncmp(const char* a1, const char* a2,int x)
//{
//	assert(a1 != NULL);
//	assert(a2 != NULL);
//	int ret = 0;
//	while (!(ret = *(a1) - *(a2)) && *a1 && *a2 && x)
//	{
//		a1++;
//		a2++;
//		x--;
//	}
//	return ret;
//}
//int main()
//{
//	char arr1[] = "����ϲ����";//ϲ>��>��>��
//	char arr2[] = "���Һ�ϲ���㰡";
//	//int  ret = my_strcmp(arr1, arr2);
//	int  ret = my_strncmp(arr1, arr2,14);
//	printf("%d\n", ret);
//	return 0;
//}



//strcat  strncat
////char* my_strcat(char* a1, char* a2)
////{
////    assert(a1 != NULL);
////	assert(a2 != NULL);
////	char* cp = a1;
////	while (*a1++)
////	{
////		;
////	}
////	a1--;
////	while (*a2)
////	{
////		if (!(*a1++ = *a2++))
////		{
////			return cp;
////		}
////	}
////	*a1 = '\0';
////	return cp;
////}
//char* my_strncat(char* a1, const char* a2,int x)
//{
//  assert(a1 != NULL);
//  assert(a2 != NULL);
//	char* cp = a1;
//	while (*a1++)
//	{
//		;
//	}
//	a1--;
//	while (x--)
//	{
//		if (!(*a1++ = *a2++))
//		{
//			return cp;
//		}
//	}
//	*a1 = '\0';
//	return cp;
//}
//int main()
//{
//	char arr1[40] = "���Һ�";
//	char arr2[] = "ϲ���㰡";
//	//char*ret = my_strcat(arr1, arr2);
//	char* ret = my_strncat(arr1, arr2,8);
//	printf("%s\n", ret);
//	return 0;
//}



//strstr
//char* my_strstr(char* a1, char* a2)
//{
//	assert(a1 != NULL);
//	assert(a2 != NULL);
//	char* p1 = a1;
//	char* p2 = a2;
//	char* cur = a1;
//	if (*p2 == '\0')
//	{
//		return p1;
//	}
//	while (*cur)
//	{
//		p1 = cur;
//		p2 = a2;
//		while ((*p1 != '\0') && (*p2 != '\0') && (*p1 == *p2))
//		{
//			p1++;
//			p2++;
//		}
//		if (*p2 == '\0')
//		{
//			return cur;
//		}
//		cur++;
//	}
//	return NULL;
//}
//int main()
//{
//	char arr1[40] = "***���Һ�ϲ����";
//	char arr2[] = "����";
//	char* ret = my_strstr(arr1, arr2);
//	printf("%s\n", ret);
//	return 0;
//}



////strtop
//int main()
//{
//	char arr[] = "��*��*��*ϲ*��*��";
//	const char* p = "*";
//	char buf[1024] = { 0 };
//	char* ret = NULL;
//	for (ret = strtok(arr, p); ret != NULL; ret = strtok(NULL, p))
//	{
//		printf("%s\n", ret);
//	}
//	return 0;
//}



////strerror
////������  ������Ϣ
////0 -      No error
////1 -      Operation not permitted
////2 -      No such file or directory
////...
////errno ��һ��ȫ�ֵĴ�����ı���
////��C���ԵĿ⺯����ִ�й����У������˴��󣬾ͻ�Ѷ�Ӧ�Ĵ����룬��ֵ��errno��
//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		printf("open file success\n");
//	}
//	return 0;
//}



//memcpy   ��������  ����������  �ṹ������  ���ܿ���
//ֻ���� ���ص����ڴ�Ŀ����Ϳ���
//void* my_memcpy(void* a2,const void*a1 , int x)
//{
//	assert(a1 != NULL);
//	assert(a2 != NULL);
//	char* p1 = (char*)a1;
//	char* p2 = (char*)a2;
//	while (x--)
//	{
//		*p2 = *p1;
//		p1++;
//		p2++;
//	}
//	return p2;
//}
//struct S
//{
//	char name[20];
//	int age;
//};
//int main()
//{
//	int arr1[] = { 3,27,5,2,0 };
//	int arr2[5] = {0};
//	struct S arr3[] = { {"С��",27},{"־��",12} };
//	struct S arr4[3] = { 0 };
//	my_memcpy(arr2,arr1,  sizeof(arr1));
//	my_memcpy(arr4, arr3, sizeof(arr1));
//	int i = 0;
//	for ( i = 0; i < 5; i++)
//	{
//		printf("%d ", arr2[i]);
//	}
//	return 0;
//}



//memmove   �����ص��ڴ�Ŀ���
//void* my_memmove(void* a2, const void* a1, int x)
//{
//	assert(a1 != NULL);
//	assert(a2 != NULL);
//	char* p1 = (char*)a1;	
//	char* p2 = (char*)a2;
//	if (p2 > p1)
//	{
//		while (x--)
//		{
//			*(p2 + x) = *(p1 + x);
//		}
//
//	}
//	else
//	{
//		while (x--)
//		{
//			*p2 = *p1;
//			p1++;
//			p2++;
//		}
//	}
//	return a2;
//}
//int main()
//{
//	int arr[] = { 3,27,5,2,0,1,3,1,4 };
//	my_memmove(arr,arr+2,20);
//	int i = 0;
//	for ( i = 0; i < 9; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}



//memcmp
//int main()
//{
//	int arr1[] = { 3,27,5,2,0,1,3,1,4 };
//	int arr2[] = { 3,27,5,2,0,1,4,1,3 };
//	int ret=memcmp(arr1, arr2, sizeof(arr1));
//	printf("%d\n", ret);
//	return 0;
//}



//memset
int main()
{
	char arr[40] = "";
	memset(arr, 'h',20);
	int i = 0;
	for (i = 0; i < 40; i++)
	{
		printf("%c ", arr[i]);
	}
	return 0;
}