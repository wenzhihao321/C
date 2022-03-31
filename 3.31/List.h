#pragma once

namespace milu
{
	//封装双向带头链表的结点
	template<class T>
	struct _list_node
	{
		T _val;
		_list_node<T>* _next;
		_list_node<T>* _prev;
		_list_node(const T& val = T())
			:_val(val)
			, _next(nullptr)
			, _prev(nullptr)
		{}
	};

	//封装迭代器
	//                      T&          T*
	template<class T, class Ref, class Ptr>
	struct _list_iterator
	{
		typedef _list_node<T> node;
		typedef _list_iterator<T,Ref,Ptr> self;
		node* _pnode;
		_list_iterator(node* pnode)
			:_pnode(pnode)
		{}
		
		//拷贝构造、operator=、析构我们不写，编译器默认生成就可以用
		
		//T& operator*()    iterator 可读可写
		//const T& operator*()    const_iterator 只写
		Ref operator*()
		{
			return _pnode->_val;
		}
		Ptr operator->()
		{
			return &_pnode->_val;
		}
		bool operator!= (const self& s)
		{
			return _pnode != s._pnode;
		}
		bool operator== (const self& s)
		{
			return _pnode == s._pnode;
		}
		self& operator++() 
		{
			_pnode = _pnode->_next;
			return *this;
		}
		self& operator--()
		{
			_pnode = _pnode->_prev;
			return *this;
		}
		self operator++(int)
		{
			self tmp(*this);
			_pnode = _pnode->_next;
			return tmp;
		}
		self operator--(int)
		{
			self tmp(*this);
			_pnode = _pnode->_prev;
			return tmp;
		}
	};

	template<class T>
	class List
	{
	public:
		typedef _list_node<T> node;
		typedef _list_iterator<T, T&, T*> iterator;
		typedef _list_iterator<T, const T&, const T*> const_iterator;

		iterator begin()
		{
			return iterator(_head->_next);
		}
		iterator end()
		{
			return iterator(_head);
		}
		const_iterator begin() const
		{
			return const_iterator(_head->_next);
		}
		const_iterator end() const
		{
			return const_iterator(_head);
		}
		List()
		{
			_head = new node;
			_head->_next = _head;
			_head->_prev = _head;
		}

		List(const List<T>& lt)
		{
			_head = new node;
			_head->_next = _head;
			_head->_prev = _head;
			for (const auto& e : lt)
			{
				push_back(e);
			}
		}
		//传统写法
		/*List<T>& operator=(const List<T>& lt)
		{
			if (this != lt)
			{
				clear();
				for (const auto& e : lt)
				{
					push_back(e);
				}
			}
			return *this;
		}*/

		//现代写法
		List<T>& operator=(List<T> lt)
		{
			swap(_head, lt._head);
			return *this;
		}


		~List()
		{
			clear();
			delete _head;
			_head = nullptr;
		}

		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				it = erase(it);
			}
		}

		void push_back(const T& x)
		{
			/*node*newnode = new node(x);
			node* tail = _head->_prev;
			tail->_next = newnode;
			newnode->_prev = tail;
			newnode->_next = _head;
			_head->_prev = newnode;*/

			insert(end(), x);
 		}
		void push_front(const T& x)
		{
			insert(begin(), x);
		}

		void pop_back()
		{
			erase(--end());
		}

		void pop_front()
		{
			erase(begin());
		}

		void insert(iterator pos,const T& x)
		{
			assert(pos._pnode);
			node* cur = pos._pnode;
			node* prev = cur->_prev;
			node* newnode = new node(x);
			
			//prev newnode  cur
			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;
		}
		iterator erase(iterator pos)
		{
			assert(pos != end());
			assert(pos._pnode);

			//prev pos next
			node* prev = pos._pnode->_prev;
			node* next = pos._pnode->_next;
			delete pos._pnode;
			prev->_next = next;
			next->_prev = prev;
			
			//返回next是为了防止迭代器失效
			return iterator(next);
		}

		bool empty()
		{
			return end() == begin();
		}

		size_t size()
		{
			size_t i = 0;
			iterator it = begin();
			while (it != end())
			{
				i++;
				it++;
			}
			return i;
		}
	private:
		node* _head;
	};

	void PrintList(const List<int>& lt)
	{
		List<int>::const_iterator it = lt.begin();
		while (it != lt.end())
		{
			//*it += 1;
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}
	void list_test1()
	{
		List<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		List<int>::iterator it = lt.begin();
		while (it != lt.end())
		{
			*it += 1;
			cout << *it << " ";
			++it;
		}

		cout << endl;
		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;
	}
	void list_test2()
	{
		List<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		PrintList(lt);
		lt.clear();
		PrintList(lt);
		lt.push_back(4);
		PrintList(lt);

	}
}