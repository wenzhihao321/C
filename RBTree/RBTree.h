#pragma once
#include<iostream>
using namespace std;

enum Colour
{
	RED,
	BLACK,
};

template<class T>
struct RBTreeNode
{
	RBTreeNode<T>* _left;
	RBTreeNode<T>* _right;
	RBTreeNode<T>* _parent;
	T _date;
	Colour _col;
	RBTreeNode(const T& x)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _date(x)
		, _col(RED)
	{}
};


template<class T, class Ref, class Ptr>
struct _TreeIterator
{
	typedef Ref reference;
	typedef Ptr pointer;

	typedef RBTreeNode<T> Node;
	                      //����  ָ��
	typedef _TreeIterator<T, Ref, Ptr> Self;
	Node* _node;
	_TreeIterator(Node* node)
		:_node(node)
	{}
	Ref operator*()
	{
		return _node->_date;
	 }

	Ptr operator->()
	{
		return &_node->_date;
	}

	bool operator !=(const Self& s) const
	{
		return _node != s._node;
	}
	bool operator ==(const Self& s) const
	{
		return _node == s._node;
	}
	Self& operator++()
	{
		//���������ڿգ���һ�����ʵľ��������У�����ĵ�һ���ڵ㣨������������ڵ㣩
		if (_node->_right)
		{
			Node* left = _node->_right;
			while (left->_left)
			{
				left = left->_left;
			}
			_node = left;
		}
		//���������ڿգ����������������ߣ��ң����Ӳ��Ǹ����󣩵��Ǹ�����
		else
		{
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent && cur == parent->_right)
			{
				cur = cur->_parent;
				parent = parent->_parent;
			}
			_node = parent;
		}
		return *this;
	}
	Self& operator--()
	{
		//�����������ڿգ���һ�����ʵľ����������У�����ĵ�һ���ڵ㣨������������ڵ㣩
		if (_node->_left)
		{
			Node* right = _node->_left;
			while (right->_right)
			{
				right = right->_right;
			}
			_node = right;
		}
		//���������ڿգ����������������ߣ��ң����Ӳ��Ǹ����ң����Ǹ�����
		else
		{
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent && cur == parent->_left)
			{
				cur = cur->_parent;
				parent = parent->_parent;
			}
			_node = parent;
		}
		return *this;
	}

};


//�˽�
template<class Iterator>
struct ReverseIterator
{
	typedef typename Iterator::reference Ref;
	typedef typename Iterator::pointer Ptr;
	typedef ReverseIterator<Iterator> Self;

	ReverseIterator(Iterator it)
		:_it(it)
	{}
	Ref operator*()
	{
		return *_it;
	}
	Ptr operator->()
	{
		return _it.operator->();
	}
	Self& operator++()
	{
		--_it;
		return *this;
	}
	Self& operator--()
	{
		++_it;
		return *this;
	}
	bool operator !=(const Self& s) const
	{
		return _it != s._it;
	}
	bool operator ==(const Self& s) const
	{
		return _it == s._it;
	}
	Iterator _it;
};

template<class K, class T,class KeyOfT>
class RBTree
{
	typedef RBTreeNode<T> Node;
public:
	typedef _TreeIterator<T, T&, T*> iterator;
	typedef _TreeIterator<T, const T&,const  T*> const_iterator;
	typedef ReverseIterator<iterator> reverse_iterator;

	reverse_iterator rbegin()
	{
		Node* right = _root;
		while (right && right->_right)
		{
			right = right->_right;
		}
		return reverse_iterator(iterator(right));
	}
	reverse_iterator rend()
	{
		return reverse_iterator(iterator(nullptr));
	}

	iterator begin()
	{
		Node* left = _root;
		while (left && left->_left)
		{
			left = left->_left;
		}
		return iterator(left);
	}

	iterator end()
	{
		return iterator(nullptr);
	}
	
	RBTree()
		:_root(nullptr)
	{}


	//���������operator=
	void Destory(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}
		Destory(root->_left);
		Destory(root->_right);
		delete root;
	}
	~RBTree()
	{
		Destory(_root);
		_root = nullptr;
	}

	Node* Find(const K& key)
	{
		KeyOfT kot;
		Node* cur = _root;
		while (cur)
		{
			if (kot(cur->_date) < key)
			{
				cur = cur->_right;
			}
			else if (kot(cur->_date) > key)
			{
				cur = cur->_left;
			}
			else
			{
				return cur;
			}
		}
		return nullptr;
	}

	pair<iterator, bool> Insert(const T& date)
	{
		if (_root == nullptr)
		{
			_root = new Node(date);
			_root->_col = BLACK;
			return make_pair(iterator(_root), true);
		}

		KeyOfT kot;
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (kot(cur->_date) < kot(date))
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (kot(cur->_date) > kot(date))
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return make_pair(iterator(cur), false);
			}
		}
		Node* newnode = new Node(date);
		newnode->_col = RED;
		if (kot(parent->_date) < kot(date))
		{

			parent->_right = newnode;
			newnode->_parent = parent;
		}
		else //parent->_kv.first > kv.first
		{

			parent->_left = newnode;
			newnode->_parent = parent;
		}

		cur = newnode;

		//������״��ڣ��Ҹ��׵���ɫΪ��ɫ����Ҫ����
		while (parent && parent->_col == RED)
		{
			Node* grandfather = parent->_parent;
			//�ؼ��ǿ�����
			if (parent == grandfather->_left)
			{
				Node* uncle = grandfather->_right;
				//���1:nucle������Ϊ��
				if (uncle && uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					//�������ϴ���
					cur = grandfather;
					parent = cur->_parent;
				}
				else //���2/3��uncle������,uncle������Ϊ��
				{
					//���2������
					if (cur == parent->_left)
					{
						RotateR(grandfather);
						grandfather->_col = RED;
						parent->_col = BLACK;
					}
					else //���3��˫��
					{
						RotateL(parent);
						RotateR(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;
					}
					break;
				}
			}
			else //parent == grandfather->_right
			{
				Node* uncle = grandfather->_left;
				if (uncle&& uncle->_col == RED)
				{
					uncle->_col = parent->_col = BLACK;
					grandfather->_col = RED;

					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					if (cur == parent->_right)
					{
						RotateL(grandfather);
						grandfather->_col = RED;
						parent->_col = BLACK;
					}
					else
					{
						RotateR(parent);
						RotateL(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;
					}
					break;
				}
			}
		}
		_root->_col = BLACK;
		return make_pair(iterator(newnode), true);
	}
	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
		{
			subLR->_parent = parent;
		}
		subL->_right = parent;
		Node* parentParent = parent->_parent;
		parent->_parent = subL;
		if (_root == parent)
		{
			_root = subL;
			_root->_parent = nullptr;
		}
		else
		{
			if (parentParent->_left == parent)
			{
				parentParent->_left = subL;
			}
			else
			{
				parentParent->_right = subL;
			}
			subL->_parent = parentParent;
		}
	}
	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL)
		{
			subRL->_parent = parent;
		}

		subR->_left = parent;
		Node* parentParent = parent->_parent;
		parent->_parent = subR;

		if (parent == _root)
		{
			_root = subR;
			_root->_parent = nullptr;
		}
		else
		{
			if (parentParent->_left == parent)
			{
				parentParent->_left = subR;
			}
			else
			{
				parentParent->_right = subR;
			}
			subR->_parent = parentParent;
		}
	}
	bool _CheckBlance(Node* root, int blackNum, int count)
	{
		if (root == nullptr)
		{
			if (count != blackNum)
			{
				cout << "��ɫ�ڵ�����������" << endl;
				return false;
			}
			return true;
		}
		if (root->_col == RED && root->_parent->_col == RED)
		{
			cout << "���������ĺ�ڵ�" << endl;
			return false;
		}
		if (root->_col == BLACK)
		{
			count++;
		}
		return _CheckBlance(root->_left, blackNum, count)
			&& _CheckBlance(root->_right, blackNum, count);
	}

	bool CheckBlance()
	{
		if (_root == nullptr)
		{
			return true;
		}
		if (_root->_col == RED)
		{
			cout << "���ڵ��Ǻ�ɫ" << endl;
			return false;
		}
		//������·������ɫ�ڵ������ο�ֵ
		Node* left = _root;
		int blackNum = 0;
		while (left)
		{
			if (left->_col == BLACK)
			{
				blackNum++;
			}
			left = left->_left;
		}
		int count = 0;
		return _CheckBlance(_root, blackNum, count);
	}
	void _InOrder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}

		_InOrder(root->_left);
		cout << root->_kv.first << ":" << root->_kv.second << endl;
		_InOrder(root->_right);
	}
	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}
private:
	Node* _root;
};