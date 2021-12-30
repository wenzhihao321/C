#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int test(int x, int y)
{
    if (y == 0)
    {
        return 0;
    }
    int sum = x * y;
    int i = x % y;
    while (i != 0)
    {
        x = y;
        y = i;
        i = x % y;
    }
    int k = sum / y;
    return k;
}
int main()
{
    int x, y = 0;
    scanf("%d%d", &x, &y);
    int k = test(x, y);
    printf("%d\n", k);
    return 0;
}
