#pragma once
#include"RBTree.h"

namespace wzh
{
	template<class K,class V>
	class set
	{
		struct SetKeyOfT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};
	public:
		//typename ���߱��������Ǹ����ͣ��Ӻ�ʵ��������ȥ��
		typedef typename RBTree<K,K,SetKeyOfT>::iterator iterator;
		typedef typename RBTree<K, K, SetKeyOfT>::reverse_iterator reverse_iterator;
		reverse_iterator begin()
		{
			return _t.rbegin();
		}
		reverse_iterator end()
		{
			return _t.rend();
		}


		iterator begin()
		{
			return _t.begin();
		}

		iterator end()
		{
			return _t.end();
		}
		pair<iterator,bool> insert(const K& k)
		{			
			return _t.Insert(k);
		}
	private:
		RBTree<K, K, SetKeyOfT> _t;
	};
}