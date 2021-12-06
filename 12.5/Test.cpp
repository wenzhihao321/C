#include"Sort.h"

int main()
{
	int arr1[] = { 10,9,8,7,6,5 };
	int n = sizeof(arr1) / sizeof(arr1[0]);
	InserSort(arr1, n);
	Print(arr1, n);
	int arr2[] = { 10,9,8,7,6,5,4,3,2,1,0,-1,-2,-3,-4,-5,-6,-7,-8,-9,-10,-11 };
	ShellSort(arr2, sizeof(arr2) / sizeof(arr2[0]));
	int arr3[] = { 10,9,8,7,6,5,4,3,2,1,0,-1,-2,-3,-4,-5,-6,-7,-8,-9,-10,-11 };
	BubbleSort(arr3, sizeof(arr3) / sizeof(arr3[0]));
	Print(arr3, sizeof(arr3) / sizeof(arr3[0]));

	return 0;
}