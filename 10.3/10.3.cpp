#include<iostream>
#include<assert.h>
int my_strlen(char* arr1)
{
	int count = 0;
	assert(arr1 != NULL);
	while (*arr1!='\0')
	{
		count++;
		arr1++;
	}
	return count;
}

int main()
{
	//´íÎóÊ¾·¶
	//char arr1[] = {'a','b','c','d','e','f'};
	//int len=my_strlen(arr1);
	char arr1[] = "abcdef";
	int len=my_strlen(arr1);
	printf("%d\n", len);
	return 0;
}

