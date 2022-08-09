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
	                      //引用  指针
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
		//右树不等于空，下一个访问的就是右树中，中序的第一个节点（右子树的最左节点）
		if (_node->_right)
		{
			Node* left = _node->_right;
			while (left->_left)
			{
				left = left->_left;
			}
			_node = left;
		}
		//左子树等于空，沿着三叉链往上走，找（孩子不是父亲左）的那个祖先
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
		//左子树不等于空，下一个访问的就是左子树中，中序的第一个节点（右子树的最左节点）
		if (_node->_left)
		{
			Node* right = _node->_left;
			while (right->_right)
			{
				right = right->_right;
			}
			_node = right;
		}
		//右子树等于空，沿着三叉链往上走，找（孩子不是父亲右）的那个祖先
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


//了解
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


	//拷贝构造和operator=
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

		//如果父亲存在，且父亲的颜色为红色就需要处理
		while (parent && parent->_col == RED)
		{
			Node* grandfather = parent->_parent;
			//关键是看叔叔
			if (parent == grandfather->_left)
			{
				Node* uncle = grandfather->_right;
				//情况1:nucle存在且为红
				if (uncle && uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					//继续往上处理
					cur = grandfather;
					parent = cur->_parent;
				}
				else //情况2/3，uncle不存在,uncle存在且为黑
				{
					//情况2：单旋
					if (cur == parent->_left)
					{
						RotateR(grandfather);
						grandfather->_col = RED;
						parent->_col = BLACK;
					}
					else //情况3：双旋
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
				cout << "黑色节点的数量不相等" << endl;
				return false;
			}
			return true;
		}
		if (root->_col == RED && root->_parent->_col == RED)
		{
			cout << "存在连续的红节点" << endl;
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
			cout << "根节点是红色" << endl;
			return false;
		}
		//找最左路经做黑色节点数量参考值
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