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
	//默认是一个大堆，默认大的优先级高  less
	//milu ::priority_queue<int> pq;
	//默认是一个小堆，默认小的优先级高  greater
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

//仿函数 -- 函数对象  这个类的对象可以像函数一样去使用
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