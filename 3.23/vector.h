#pragma once
#include<cassert>
namespace milu
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		vector()
		: _start(nullptr)
		, _finish(nullptr)
		,_endofstorage(nullptr)
		{}

		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		size_t  capacity() const
		{
			return _endofstorage - _start;
		}

		size_t size() const
		{
			return _finish - _start;
		}

		T& operator[](size_t i)
		{
			assert(i < size());
			return _start[i];
		}

		void reserve(size_t n)
		{
			if (n > capacity())
			{
				T* tmp = new T[n];
				if (_start)
				{
					memcpy(tmp, _start, size());
					delete[] _start;
				}
				size_t _size = size();
				_start = tmp;
				_finish = _start + _size;
				_endofstorage = _start + n;
			}
		}

		void push_back(const T& x)
		{
			if (_finish == _endofstorage)
			{
				size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newcapacity);
			}
			*_finish = x;
			_finish++;
		}



	private:
		iterator _start;
		iterator _finish;
		iterator _endofstorage;

	};

	void test_vector1()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		vector<int> ::iterator it = v.begin();
		while (it != v.end())
		{
			cout << *it << " ";
			it++;
		}
		cout << endl;
	}
}