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

		//向上调整，小到上面
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
		//向下调整，大的往下走
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
		//对插入的每个数据进行向上调整
		void push(const T& x)
		{
			_con.push_back(x);

			AdjustUp(_con.size() - 1);
		}
		//头删，需要把头结点挪到最后一个，再删除，进行向下调整
		//挪到最后一个的原因是：效率会比直接删除高，直接删除需要n-1个数据
		void pop()
		{
			std::swap(_con[0], _con[size() - 1]);
			_con.pop_back();
			AdjustDwon(0);
		}
		//获取第一个元素
		T top()
		{
			return _con[0];
		}
		//获取优先队列大小
		size_t size()
		{
			return _con.size();
		}
		//判空
		bool empty()
		{
			return _con.empty();
		}
	private:
		Container _con;
	};

}