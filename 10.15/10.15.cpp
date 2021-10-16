#include<iostream>

//
////int check_sys()
////{
////	int i = 1;
////	//返回1，表示小端
////	//返回0，表示大端
////	return *(char*)&i;
////}
// int check_sys()
//{
//	 union un
//	 {
//		 char c;
//		 int i;
//     }U;
//	 U.i = 1;
//	 return U.c;
//}
//int main()
//{
//	int ret = check_sys();
//	if (ret == 1)
//	{
//		printf("小端存储\n");
//	}
//	else
//	{
//		printf("大端存储\n");
//	}
//	return 0;
//}
union un
{
	int i;
	char arr[10];
	double d;
}u;
int main()
{
	printf("%d\n",sizeof(u));
	return 0;
}