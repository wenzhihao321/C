#pragma once
#include<vector>


namespace milu
{
	template<class T>
	struct less
	{
		bool operator()(const T& a, const T& b)
		{
			return a < b;
		}
	};
	template<class T>
	struct greater
	{
		bool operator()(const T& a, const T& b)
		{
			return a > b;
		}
	};
	template<class T, class Container = vector<T>,class Compare = less<T>>
	class priority_queue
	{
	public:

		//���ϵ�����С������
		void AdjustUp(size_t child)
		{
			Compare com;

			size_t parent = (child - 1) / 2;
			while (child > 0)
			{
				//if (_con[child] < _con[parent])
				if (com(_con[child], _con[parent]))
				{
					std::swap(_con[child], _con[parent]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;
				}
			}
		}
		//���µ��������������
		void AdjustDwon(size_t parent)
		{
			Compare com;

			size_t child = parent * 2 + 1;
			while (child < _con.size())
			{
				//if (child + 1 < _con.size() && _con[child + 1] < _con[child])
				if (child + 1 < _con.size() && com(_con[child + 1], _con[child]))

				{
					++child;
				}
				//if (_con[child] < _con[parent])
				if (com(_con[child], _con[parent]))
				{
					std::swap(_con[child],_con[parent] );
					parent = child;
					child = parent * 2 + 1;
				}
				else
				{
					break;
				}
			}
		}
		//�Բ����ÿ�����ݽ������ϵ���
		void push(const T& x)
		{
			_con.push_back(x);

			AdjustUp(_con.size() - 1);
		}
		//ͷɾ����Ҫ��ͷ���Ų�����һ������ɾ�����������µ���
		//Ų�����һ����ԭ���ǣ�Ч�ʻ��ֱ��ɾ���ߣ�ֱ��ɾ����Ҫn-1������
		void pop()
		{
			std::swap(_con[0], _con[size() - 1]);
			_con.pop_back();
			AdjustDwon(0);
		}
		//��ȡ��һ��Ԫ��
		T top()
		{
			return _con[0];
		}
		//��ȡ���ȶ��д�С
		size_t size()
		{
			return _con.size();
		}
		//�п�
		bool empty()
		{
			return _con.empty();
		}
	private:
		Container _con;
	};

}