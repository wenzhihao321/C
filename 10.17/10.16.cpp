#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<assert.h>
//strlen
// 1.º∆ ˝∆˜µƒ∑Ω∑®
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

 //2.µ›πÈ
//int my_strlen(const char* arr)
//{
//	assert(arr != NULL);
//	while (*arr != '\0')
//	{
//		return 1+ my_strlen(arr+1);
//	}
//}

//3.÷∏’Î
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
//	char arr[] = "ª›Œ“∫√œ≤ª∂ƒ„";
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
//	char arr1[20] = "************£°£°£°";
//	char arr2[] = "ª›Œ“∫√œ≤ª∂ƒ„∞°";
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
//	char arr1[] = "ª›Œ“œ≤ª∂ƒ„";//œ≤>ƒ„>ª∂>∫√
//	char arr2[] = "ª›Œ“∫√œ≤ª∂ƒ„∞°";
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
//	char arr1[40] = "ª›Œ“∫√";
//	char arr2[] = "œ≤ª∂ƒ„∞°";
//	//char*ret = my_strcat(arr1, arr2);
//	char* ret = my_strncat(arr1, arr2,8);
//	printf("%s\n", ret);
//	return 0;
//}



//strstr
char* my_strstr(char* a1, char* a2)
{
	assert(a1 != NULL);
	assert(a2 != NULL);
	char* p1 = a1;
	char* p2 = a2;
	char* cur = a1;
	if (*p2 != '\0')
	{
		return p1;
	}
	while (*cur)
	{
		while ((p1 != '\0') && (p2 != '\0') && (*p1 == *p2))
		{
			p1++;
			p2++;
		}
		if (*p2 == '\0')
		{
			return cur;
		}
		cur++;
	}
	return NULL;
}
int main()
{
	char arr1[40] = "***ª›Œ“œ≤ª∂ƒ„";
	char arr2[] = "ª›Œ“";
	char* ret = my_strstr(arr1, arr2);
	printf("%s\n", ret);
	return 0;
}



//strtop
//strerror
//memcpy
//memmove
//memset
//memcmp