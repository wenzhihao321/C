#include<iostream>
using namespace std;
int main()
{
	//一维数组
	int a[] = { 1,2,3,4 };
	printf("%d\n", sizeof(a));//16 sizeof(数组名) 计算数组总大小 
	printf("%d\n", sizeof(a + 0));//4/8 首元素地址
	printf("%d\n", sizeof(*a));//4  首元素
	printf("%d\n", sizeof(a + 1));//4/8
	printf("%d\n", sizeof(a[1]));//4
	printf("%d\n", sizeof(&a));//4/8 取出地址大小
	printf("%d\n", sizeof(*&a));//16
	printf("%d\n", sizeof(&a+1));//4/8  &a是数组地址 +1是跳过整个数组但还是地址
	printf("%d\n", sizeof(&a[0]));//4/8 
	printf("%d\n", sizeof(&a[0] + 1));//4/8 

	//字符数组
	char arr[] = { 'a','b','c','d','e','f' };
	printf("%d\n", strlen(arr));//随机值
	printf("%d\n", strlen(arr + 0));//随机值
	printf("%d\n", strlen(*arr));//err	
	printf("%d\n", strlen(arr[1]));//err
	printf("%d\n", strlen(&arr));//随机值
	printf("%d\n", strlen(&arr + 1));//随机值-6
	printf("%d\n", strlen(&arr[0] + 1));//随机值-1

	printf("%d\n", sizeof(arr));//6 sizeof计算的是整个数组的大小
	printf("%d\n", sizeof(arr+0));//4/8 首元素的地址
	printf("%d\n", sizeof(*arr));//1  arr是首元素地址 *arr是首元素	
	printf("%d\n", sizeof(arr[1]));//1
	printf("%d\n", sizeof(&arr));//4/8 数组地址
	printf("%d\n", sizeof(&arr+1));//4/8
	printf("%d\n", sizeof(&arr[0]+1));//4/8

	const char arr[] = "abcdef";
	printf("%d\n", strlen(arr));//6  strlen遇到'\0'终止
	printf("%d\n", strlen(arr + 0));//6
	printf("%d\n", strlen(*arr));//err	
	printf("%d\n", strlen(arr[1]));//err
	printf("%d\n", strlen(&arr));//6
	printf("%d\n", strlen(&arr + 1));//随机值
	printf("%d\n", strlen(&arr[0] + 1));//5

	printf("%d\n", sizeof(arr));//7 sizeof计算的是整个数组的大小
	printf("%d\n", sizeof(arr + 0));//4/8 首元素的地址
	printf("%d\n", sizeof(*arr));//1  arr是首元素地址 *arr是首元素	
	printf("%d\n", sizeof(arr[1]));//1
	printf("%d\n", sizeof(&arr));//4/8 数组地址
	printf("%d\n", sizeof(&arr + 1));//4/8 跳过一个数组的地址
	printf("%d\n", sizeof(&arr[0] + 1));//4/8 第二个元素的地址

	 const char* p = "abcdef";
	 printf("%d\n", strlen(p));//6  strlen遇到'\0'终止
	 printf("%d\n", strlen(p + 1));//5
	 //printf("%d\n", strlen(*p));//err	
	 //printf("%d\n", strlen(p[1]));//err
	 printf("%d\n", strlen(&p));//随机值 地址后面什么时候遇到'\0'不确定
	 printf("%d\n", strlen(&p + 1));//随机值 
	 printf("%d\n", strlen(&p[0] + 1));//5

	 printf("%d\n", sizeof(p));//4/8 -计算指针变量的大小
	 printf("%d\n", sizeof(p + 1));//4/8 - p+1 得到的字符b的大小
	 printf("%d\n", sizeof(*p));//1  arr是首元素地址 *arr是首元素	
	 printf("%d\n", sizeof(p[0]));//1
	 printf("%d\n", sizeof(&p));//4/8 数组地址
	 printf("%d\n", sizeof(&p + 1));//4/8 跳过一个数组的地址
	 printf("%d\n", sizeof(&p[0] + 1));//4/8 第二个元素的地址

	 int a[3][4] = { 0 };
	 printf("%d\n", sizeof(a));//48 - 3*4*4=48
	 printf("%d\n", sizeof(a[0][0]));//4 -  一个整型的大小
	 printf("%d\n", sizeof(a[0]));//16  a[0]相当于第一行做为一维数组的数组名
	                              // 第一行的数组大小	
	 printf("%d\n", sizeof(a[0]+1));//4/8 第一行数组的第二个地址
	 printf("%d\n", sizeof(*(a[0] + 1)));//4
	 printf("%d\n", sizeof(a + 1));//4  a是二维数组的数组名，没有sizeof（a），也没有&（a），所以a是首元素的地址
	 //而把二维数组看成一维数组时，二维数组的首元素是他的第一行，a就是第一行（首元素）的地址
	 //a+1就是第二行的地址
	 printf("%d\n", sizeof(*(a + 1)));//16
	 printf("%d\n", sizeof(&a[0] + 1));//4/8 第二行数组的地址
	 printf("%d\n", sizeof(*(&a[0] + 1)));//16 第二个数组的大小
	 printf("%d\n", sizeof(*a));//16 a是首元素地址 - 第一行地址，*a就是第一行，sizeof（*a）就是计算第一行的大小
	 printf("%d\n", sizeof(a[3]));//16 

	 return 0;
}