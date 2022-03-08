#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int main()
{
    int year, month, day;
    cin >> year >> month >> day;
    //0,31,28,31,30,31,30,31,31,30,31,30,31
    int arr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    int firstmonth = 1, firstday = 0;
    while (firstmonth < month)
    {
        firstday += arr[firstmonth];
        ++firstmonth;
    }
    if ((month > 2) && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
    {
        ++firstday;
    }
    cout << firstday + day << std::endl;
    return 0;
}