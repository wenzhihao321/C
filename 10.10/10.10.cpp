#include<iostream>
#include<assert.h>
void my_memmove(void* dest, void* src, int x)
{
	assert(dest != NULL);
	assert(src != NULL);
	char* ret1 = (char*)dest;
	char* ret2 = (char*)src;
	//if (dest > src&&dest<(char*)src+x)
	//{
	//	while (x--)
	//	{
	//		*(ret1 + x) = *(ret2 + x);
	//	}
	//}
	if (dest > src )
	{
		while (x--)
		{
			*(ret1 + x) = *(ret2 + x);
		}
	}
	else
	{
		while (x--)
		{

			*ret1 = *ret2;
			ret1++;
			ret2++;
		}
	}
}

//void my_memmove(void*dest, void* src, int x)
//{
//	assert(dest != NULL);
//	assert(src != NULL);
//	char* ret1 = (char*)dest;
//	char* ret2 = (char*)src;
//	if (dest<src)
//	{
//		while (x--)
//		{
//			*ret1 = *ret2;
//			ret1++;
//			ret2++;
//		}
//	}
//	else
//	{
//		while (x--)
//		{
//			*(ret1 + x) = *(ret2 + x);
//		}
//	}
//}

int main()
{
	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
	int arr2[20] = { 0 };
	my_memmove(arr2, arr1, sizeof(arr1));
	my_memmove(arr1+2 , arr1 , 20);
	return 0;
}

