#pragma once
#include<cassert>
namespace milu
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;  

		vector()
		: _start(nullptr)
		, _finish(nullptr)
		,_endofstorage(nullptr)
		{}

		~vector()
		{
			
			delete[] _start;
			_start = _finish = _endofstorage = nullptr;
		}

		vector(const vector<T>& v)
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			_start = new T[v.capacity()];
			//memcpy(_start, v._start, sizeof(T) * v.size());
			for (size_t i = 0; i < v.size(); ++i)
			{
				_start[i] = v._start[i];
			}
			_finish = _start + v.size();
			_endofstorage = _start + v.capacity();

			/*reserve(v.capacity());
			for (auto e : v)
			{
				push_back(e);
			}*/
		}

		//v3 = v1
		vector<T>& operator=(const vector<T>& v)
		{
			//传统写法
			/*if (this != &v)
			{
				delete[] _start;
				_start = new T[v.capacity()];
				memcpy(_start, v._start, sizeof(T) * v.size());
				_finish = _start + v.size();
				_endofstorage = _start + v.capacity();
			}*/			
			swap(v);
			return *this;
		}

		void swap(vector<T>& v)
		{
			::swap(_start, v._start);
			::swap(_finish, v._finish);
			::swap(_endofstorage, v._endofstorage);
		}

		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		const_iterator begin() const
		{
			return _start;
		}

		const_iterator end() const
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

		bool empty() const
		{
			return _start == _finish;
		}

		T& operator[](size_t i)
		{
			assert(i < size());
			return _start[i];
		}

		void resize(size_t n, T val = T())   
		{
			/*if (n < size())
			{
				_finish = _start + n;
				return;
			}
			if (n > capacity())
			{
				reserve(n);
			}
			int ssize = n - size();
			while (ssize--)
			{
				*_finish = val;
				_finish++;
			}*/

			if (n < size())
			{
				_finish = _start + n;
			}
			else
			{
				if (n > capacity())
				{
					reserve(n);
				}
				while (_finish < _start + n)
				{
					*_finish = val;
					_finish++;
				}
				
			}
		}

		void reserve(size_t n)
		{
			if (n > capacity())
			{
				T* tmp = new T[n];
				size_t sz = size();
				if (_start)
				{
					//自定义类型会出现浅拷贝，会对同一片空间重复析构
					//memcpy(tmp, _start, sz*sizeof(T));    
					for (size_t i = 0; i < sz; ++i)
					{
						tmp[i] = _start[i];
					}
					delete[] _start;
				}
				_start = tmp;
				_finish = _start + sz;
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

		void pop_back(const T& x)
		{
			assert(!empty());
			--_finish;
		}

		void insert(iterator pos,const T& x)
		{
			assert(pos <= _finish);
			if (_finish == _endofstorage)
			{
				size_t len = pos - _start;
				size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newcapacity);

				//更新pos，解决增容后pos失效的问题
				pos = _start + len;
			}
			iterator it = _finish;
			while (it != pos)
			{
				*it = *(it - 1);
				--it;
			}
			*pos = x;
			++_finish;
		}

		iterator erase(iterator pos)
		{
			assert(pos <= _finish);
			iterator it = pos + 1;
			while (it != _finish)
			{
				*(it - 1) = *it;
				++it;
			}
			_finish = _finish - 1;
			return pos;
		}

	private:
		iterator _start;
		iterator _finish;
		iterator _endofstorage;

	};

	template<class T> 
	void PrintVector(const vector<T>& c)
	{
		vector<int> ::const_iterator it = c.begin();
		while (it != c.end())
		{
			//*it += 1；    只能读，不能写
			cout << *it << " ";
			it++;
		}
		cout << endl;
	}

	void test_vector1()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		cout << endl;
		PrintVector(v);
		v.push_back(5);
		PrintVector(v);
	}
	void test_vector2()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		
		vector<int>::iterator pos = find(v.begin(), v.end(), 3);
		//在pos -- 3之前插入
		v.insert(pos, 30);
		PrintVector(v);
	}

	void test_vector3()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		v.push_back(6);
		v.push_back(7);
		v.push_back(6);

		vector<int>::iterator it = v.begin();
		while (it != v.end())
		{
			if (*it % 2 == 0)
			{
				it = v.erase(it);
			}
			else
			{
				++it;
			}			
		}
		PrintVector(v);

	}
}