#include<iostream>
using namespace std;
#define N 6
struct BTreeNode
{
	int data;
	BTreeNode* lchild;
	BTreeNode* rchild;
};

class BTree
{
public:
	void setRoot(BTreeNode* r)     //���ø�
	{
		this->root = r;
	}
	BTreeNode* getRoot()           //�Ҹ�
	{
		return root;
	}
	BTreeNode* createBTree();      //�������Ĵ���
	BTreeNode* buildtree(int a[], int b[], int i, int j, int s, int t);
	void preOrder();               //ǰ��������ݹ飩
	void inOrder();                //����������ݹ飩
	void postOrder();              //����������ݹ飩
	int BTreeSize();               //����ĸ���
	int BTreeLeaves();             //��Ҷ�ӽ�����
	int BTreeHeight();             //�����ĸ�
protected:
	void preOrder(BTreeNode* r);               //ǰ��������ݹ飩
	void inOrder(BTreeNode* r);                //����������ݹ飩
	void postOrder(BTreeNode* r);              //����������ݹ飩
	int BTreeSize(BTreeNode* r);               //����ĸ���
	int BTreeLeaves(BTreeNode* r);             //��Ҷ�ӽ�����
	int BTreeHeight(BTreeNode* r);             //�����ĸ�
private:
	BTreeNode* root;
};

BTreeNode* BTree::createBTree()
{
	BTreeNode* p;
	int x;
	cin >> x;
	if (x == 0)
	{
		return NULL;
	}
	p = new BTreeNode;
	p->data = x;
	p->lchild = createBTree();
	p->rchild = createBTree();
	return p;
}


//������ʽ
void BTree::preOrder()
{
	preOrder(root);
	cout << endl;
}

//ǰ��ݹ���ʶ��������ݹ飩
void BTree::preOrder(BTreeNode* r)
{
	if (r != 0)
	{
		cout << r->data << "  ";
		preOrder(r->lchild);   //�ݹ���ʽ
		preOrder(r->rchild);   //�ݹ���ʽ
	}
}

//������ʽ
void BTree::inOrder()
{
	inOrder(root);
	cout << endl;
}

//����ݹ���ʶ��������ݹ飩
void BTree::inOrder(BTreeNode* r)
{
	if (r != 0)
	{
		inOrder(r->lchild);   //�ݹ���ʽ
		cout << r->data << "  ";
		inOrder(r->rchild);   //�ݹ���ʽ
	}
}

//������ʽ
void BTree::postOrder()
{
	postOrder(root);
	cout << endl;
}

//����ݹ���ʶ��������ݹ飩
void BTree::postOrder(BTreeNode* r)
{
	if (r != 0)
	{
		postOrder(r->lchild);   //�ݹ���ʽ
		postOrder(r->rchild);   //�ݹ���ʽ
		cout << r->data << "  ";
	}
}

//������ʽ
int BTree::BTreeSize()
{
	return BTreeSize(root);
}

//����������ĸ����ĺ���

int BTree::BTreeSize(BTreeNode* r)
{
	//�������Ľ�����Ϊ���������ĸ߶�֮����+1
	if (r == 0)
	{
		return 0;
	}
	else
	{
		return 1 + BTreeSize(r->lchild) + BTreeSize(r->rchild);
	}
}
//������ʽ
int BTree::BTreeLeaves()
{
	return BTreeLeaves(root);
}

//��Ҷ�ӽ������ĺ���
int BTree::BTreeLeaves(BTreeNode* r)
{
	if (r == 0)
	{
		return 0;
	}
	else if (r->lchild == 0 && r->rchild == 0)
	{
		return 1;
	}
	else
	{
		return BTreeLeaves(r->lchild) + BTreeLeaves(r->rchild);
	}
}

//������ʽ
int BTree::BTreeHeight()
{
	return BTreeHeight(root);
}

int BTree::BTreeHeight(BTreeNode* r)
{
	if (r == 0)
	{
		return 0;
	}
	else
	{
		//���������ĸ߶�
		int lHeight = BTreeHeight(r->lchild);
		//���������ĸ߶�
		int rHeight = BTreeHeight(r->rchild);

		//ȡ������ �� �������������+1	
		int maxHeight = lHeight > rHeight ? lHeight + 1 : rHeight + 1;

		return maxHeight;
	}
}

BTreeNode* BTree::buildtree(int a[], int b[], int i, int j, int s, int t)
{
	int k;
	BTreeNode* p;
	if (i > j)return NULL;
	p = new BTreeNode;           //������
	p->data = a[i];              //������
	k = s;
	while ((k <= t) && (b[k] != a[i]))
	{
		k++;   //�Ҹ�
	}
	if (b[k] != a[i])
	{
		cout << " Error " << endl;
		return NULL;   //û�ҵ�������
	}

	p->lchild = buildtree(a, b, i + 1, i + k - s, s, k - 1);
	p->rchild = buildtree(a, b, i + k - s + 1, j, k + 1, t);
	return p;              //���ظ����ָ��

}

void main()
{
	BTree bt;
	int i, j;
	int c = 1;
	int a[N];
	int b[N];
	while (c)
	{
		cout << "===========����������===========" << endl;
		cout << "1.���������к��������й��������" << endl;
		cout << "2.�������������еĹ��������    " << endl;
		cout << "�������˳�                      " << endl;
		cout << "================================" << endl;
		cout << "�������ܽ�   �༶��19�ƿ�6��29��" << endl;
		cout << "�����빹�췽ʽ:";
		cin >> i;
		switch (i)
		{
		case 1:
			cout << "�������������У�" << endl;
			for (j = 0; j < N; j++)
			{
				cin >> a[j];
			}
			cout << "�������������У�" << endl;
			for (j = 0; j < N; j++)
			{
				cin >> b[j];
			}
			bt.setRoot(bt.buildtree(a, b, 0, N - 1, 0, N - 1));
			break;
		case 2:
			cout << "������������������У�" << endl;
			bt.setRoot(bt.createBTree());
			break;
		default:
			cout << "�����ѽ�������л����ʹ��!" << endl;
			return;
		}
		cout << "�������������" << endl;
		cout << "���������";
		bt.preOrder();
		cout << "���������";
		bt.inOrder();
		cout << "���������";
		bt.postOrder();
		cout << "�������ĸ߶�Ϊ: " << bt.BTreeHeight() << endl;
		cout << "��������Ҷ�ӽ����Ϊ: " << bt.BTreeLeaves() << endl;
		cout << "�������Ľ����Ϊ�� " << bt.BTreeSize() << endl;
		system("pause");
		system("cls");
	}
}
