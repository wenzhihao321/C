#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
struct Stu
{
	char name[20];
	int age;
};
int cmp_int(const void* e1, const void* e2)
{
	//比较两个整型值的大小
	return *(int*)e1 - *(int*)e2;
}
void test1()
{
	int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(arr[0]), cmp_int);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d  ", arr[i]);
	}
}
int cmp_float(const void* e1, const void* e2)
{
	//if (*(float*)e1 == *(float*)e2)
	//	return 0;
	//else if (*(float*)e1 > *(float*)e2)
	//	return 1;
	//else
	//	return -1;
	return ((int)*(float*)e1 - *(float*)e2);
}
void test2()
{
	float f[] = { 9.0,8.0,7.0,6.0,5.0,4.0,3.0,2.0,1.0 };
	int sz = sizeof(f) / sizeof(f[0]);
	qsort(f, sz, sizeof(f[0]), cmp_float);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%f  ", f[i]);
	}
}
int cmp_stu_by_age(const void* e1, const void* e2)
{
	//if (*(float*)e1 == *(float*)e2)
	//	return 0;
	//else if (*(float*)e1 > *(float*)e2)
	//	return 1;
	//else
	//	return -1;
	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
}
int cmp_stu_by_name(const void* e1, const void* e2)
{
	//if (*(float*)e1 == *(float*)e2)
	//	return 0;
	//else if (*(float*)e1 > *(float*)e2)
	//	return 1;
	//else
	//	return -1;
	return strcmp(((struct Stu*)e1)->name , ((struct Stu*)e2)->name);
}
void test3()
{
	struct Stu s[3] = { {"zhangsan",20},{"lisi",40},{"wangwu",30} };
	int sz = sizeof(s) / sizeof(s[0]);
	qsort(s, sz, sizeof(s[0]), cmp_stu_by_age);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d  ", s[i].age);
		printf("\n");
	}
	qsort(s, sz, sizeof(s[0]), cmp_stu_by_name);
	int j = 0;
	for (j = 0; j< sz; j++)
	{
		printf("%s  ", s[j].name);
		printf("\n");
	}
}
void swap(char* buf1, char* buf2, int width)
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		char tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
	}
}
void bubble_sort(void*base,int sz,int width,int(*cmp)(const void*e1,const void*e2))
{
	int i = 0;
	for (i = 0; i < sz-1; i++)
	{
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)
		{
			//比较两个数的大小
			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
			{
				//交换
				swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
			}
		}
	}
}
void test4()
{
	int arr[10]= { 9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr,sz,sizeof(arr[0]), cmp_int);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d  ", arr[i]);
	}
}
void test5()
{
	struct Stu s[3] = { {"zhangsan",20},{"lisi",40},{"wangwu",30} };
	int sz = sizeof(s) / sizeof(s[0]);
	bubble_sort(s, sz, sizeof(s[0]), cmp_stu_by_age);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d  ", s[i].age);
		printf("\n");
	}
	qsort(s, sz, sizeof(s[0]), cmp_stu_by_name);
	int j = 0;
	for (j = 0; j < sz; j++)
	{
		printf("%s  ", s[j].name);
		printf("\n");
	}
}
int main()
{
	test1();
	cout << endl;
	test2();
	cout << endl;
	test3();
	cout << endl;
	test4();
	cout << endl;
	test5();
	cout << endl;
	return 0;
}