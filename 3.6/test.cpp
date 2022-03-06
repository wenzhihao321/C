#include"Date.h"
int main()
{
	Date d1(2022, 5, 27);
	d1.Print();
	Date d2(2021, 5, 27);
	d2.Print();
	cout << d1 - d2 << endl;


	return 0;
}