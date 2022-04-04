#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<functional>

#include"stack.h"
#include"queue.h"
#include"priority_queue.h"


using namespace std;
void test_stack()
{
	milu::stack<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	while (!q.empty())
	{
		cout << q.back() << " ";
		q.pop();
	}
	cout << endl;
}
      
void test_queue()
{
	milu::queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
}

void test_priori_queue()
{
	//Ĭ����һ����ѣ�Ĭ�ϴ�����ȼ���  less
	//milu ::priority_queue<int> pq;
	//Ĭ����һ��С�ѣ�Ĭ��С�����ȼ���  greater
	milu::priority_queue<int,vector<int>,greater<int>> pq;
	pq.push(1);
	pq.push(2);
	pq.push(3);
	pq.push(1);
	pq.push(3);
	pq.push(4);
	pq.push(2);
	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
}

//�º��� -- ��������  �����Ķ����������һ��ȥʹ��
struct LessInt
{
	bool operator()(int a, int b)
	{
		return a < b;
	}
};

template<class T>
struct Less
{
	bool operator()(const T& a, const T& b)
	{
		return a < b;
	}
};

bool LessFunc1(int a, int b)
{
	return a < b;
}

int main()
{
	test_stack();

	test_queue();

	test_priori_queue();

	cout << LessFunc1(1, 2) << endl;

	LessInt LessFunc2;
	cout << LessFunc2(2, 4) << endl;


	return 0;
}