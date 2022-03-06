#pragma once
#include<iostream>
using namespace std;

class Date
{
public:
	Date(int year=0, int month=1, int day=0);
	void Print();
	//析构、拷贝构造、赋值重载，可以不写，默认生成就够了；
	//像Stack才需要自己写这三个
	Date& operator += (int day);
	Date operator + (int day);
	Date& operator -= (int day);
	Date operator - (int day);
	//前置++和后置++都完成了++，不同的是返回值不一样
	//因为他们的运算符是一样的，函数名就是一样的
	//为了区分，对后置++做了特殊处理，加一个参数，形成函数重载
	//++前置
	Date& operator ++ ();
	//后置++
	Date& operator ++ (int );
	Date& operator -- ();
	Date& operator -- (int);
	bool operator > (const Date& d);
	bool operator < (const Date& d);
	bool operator >= (const Date& d);
	bool operator <= (const Date& d);
	bool operator == (const Date& d);
	bool operator != (const Date& d);
	int operator - (const Date& d);


private:
	int _year;
	int _month;
	int _day;
};