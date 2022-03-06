#pragma once
#include<iostream>
using namespace std;

class Date
{
public:
	Date(int year=0, int month=1, int day=0);
	void Print();
	//�������������졢��ֵ���أ����Բ�д��Ĭ�����ɾ͹��ˣ�
	//��Stack����Ҫ�Լ�д������
	Date& operator += (int day);
	Date operator + (int day);
	Date& operator -= (int day);
	Date operator - (int day);
	//ǰ��++�ͺ���++�������++����ͬ���Ƿ���ֵ��һ��
	//��Ϊ���ǵ��������һ���ģ�����������һ����
	//Ϊ�����֣��Ժ���++�������⴦����һ���������γɺ�������
	//++ǰ��
	Date& operator ++ ();
	//����++
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