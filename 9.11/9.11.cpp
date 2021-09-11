#include<iostream>
using namespace std;
#include<stdio.h>
int my_strlen(char* arr)
{
	int count = 0;
	while (*arr != '\0')
	{
		count++;
		arr++;
	}
	return count;
}
void reverse_str(char* arr)
{
	char tmp = 0;
	tmp = arr[0];
	int len = my_strlen(arr);
	arr[0] = arr[len - 1];
	arr[len - 1] = '\0';
	if (len>=2)
	{
		reverse_str(arr + 1);
	}
	arr[len - 1] = tmp;
}
int main()
{
	char arr[] = "nez*in*iuh*oaix";
	char arr1[] = "nak*oah*em*an*em*";
	reverse_str(arr);
	reverse_str(arr1);
	cout << arr<<arr1;
	return 0;
}
