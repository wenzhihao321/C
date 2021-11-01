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
	void setRoot(BTreeNode* r)     //设置根
	{
		this->root = r;
	}
	BTreeNode* getRoot()           //找根
	{
		return root;
	}
	BTreeNode* createBTree();      //二叉树的创建
	BTreeNode* buildtree(int a[], int b[], int i, int j, int s, int t);
	void preOrder();               //前序遍历（递归）
	void inOrder();                //中序遍历（递归）
	void postOrder();              //后序遍历（递归）
	int BTreeSize();               //求结点的个数
	int BTreeLeaves();             //求叶子结点个数
	int BTreeHeight();             //求树的高
protected:
	void preOrder(BTreeNode* r);               //前序遍历（递归）
	void inOrder(BTreeNode* r);                //中序遍历（递归）
	void postOrder(BTreeNode* r);              //后序遍历（递归）
	int BTreeSize(BTreeNode* r);               //求结点的个数
	int BTreeLeaves(BTreeNode* r);             //求叶子结点个数
	int BTreeHeight(BTreeNode* r);             //求树的高
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


//重载形式
void BTree::preOrder()
{
	preOrder(root);
	cout << endl;
}

//前序递归访问二叉树（递归）
void BTree::preOrder(BTreeNode* r)
{
	if (r != 0)
	{
		cout << r->data << "  ";
		preOrder(r->lchild);   //递归形式
		preOrder(r->rchild);   //递归形式
	}
}

//重载形式
void BTree::inOrder()
{
	inOrder(root);
	cout << endl;
}

//中序递归访问二叉树（递归）
void BTree::inOrder(BTreeNode* r)
{
	if (r != 0)
	{
		inOrder(r->lchild);   //递归形式
		cout << r->data << "  ";
		inOrder(r->rchild);   //递归形式
	}
}

//重载形式
void BTree::postOrder()
{
	postOrder(root);
	cout << endl;
}

//后序递归访问二叉树（递归）
void BTree::postOrder(BTreeNode* r)
{
	if (r != 0)
	{
		postOrder(r->lchild);   //递归形式
		postOrder(r->rchild);   //递归形式
		cout << r->data << "  ";
	}
}

//重载形式
int BTree::BTreeSize()
{
	return BTreeSize(root);
}

//求二叉树结点的个数的函数

int BTree::BTreeSize(BTreeNode* r)
{
	//二叉树的结点个数为左右子树的高度之和再+1
	if (r == 0)
	{
		return 0;
	}
	else
	{
		return 1 + BTreeSize(r->lchild) + BTreeSize(r->rchild);
	}
}
//重载形式
int BTree::BTreeLeaves()
{
	return BTreeLeaves(root);
}

//求叶子结点个数的函数
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

//重载形式
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
		//求左子树的高度
		int lHeight = BTreeHeight(r->lchild);
		//求右子树的高度
		int rHeight = BTreeHeight(r->rchild);

		//取左子树 和 右子树中最大数+1	
		int maxHeight = lHeight > rHeight ? lHeight + 1 : rHeight + 1;

		return maxHeight;
	}
}

BTreeNode* BTree::buildtree(int a[], int b[], int i, int j, int s, int t)
{
	int k;
	BTreeNode* p;
	if (i > j)return NULL;
	p = new BTreeNode;           //申请结点
	p->data = a[i];              //造根结点
	k = s;
	while ((k <= t) && (b[k] != a[i]))
	{
		k++;   //找根
	}
	if (b[k] != a[i])
	{
		cout << " Error " << endl;
		return NULL;   //没找到，出错
	}

	p->lchild = buildtree(a, b, i + 1, i + k - s, s, k - 1);
	p->rchild = buildtree(a, b, i + k - s + 1, j, k + 1, t);
	return p;              //返回根结点指针

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
		cout << "===========二叉树构造===========" << endl;
		cout << "1.用先序序列和中序序列构造二叉树" << endl;
		cout << "2.用扩充先序序列的构造二叉树    " << endl;
		cout << "其他：退出                      " << endl;
		cout << "================================" << endl;
		cout << "姓名：周杰   班级：19计科6班29号" << endl;
		cout << "请输入构造方式:";
		cin >> i;
		switch (i)
		{
		case 1:
			cout << "请输入先序序列：" << endl;
			for (j = 0; j < N; j++)
			{
				cin >> a[j];
			}
			cout << "请输入中序序列：" << endl;
			for (j = 0; j < N; j++)
			{
				cin >> b[j];
			}
			bt.setRoot(bt.buildtree(a, b, 0, N - 1, 0, N - 1));
			break;
		case 2:
			cout << "请输入扩充的先序序列：" << endl;
			bt.setRoot(bt.createBTree());
			break;
		default:
			cout << "程序已结束，感谢您的使用!" << endl;
			return;
		}
		cout << "二叉树构造完成" << endl;
		cout << "先序遍历：";
		bt.preOrder();
		cout << "中序遍历：";
		bt.inOrder();
		cout << "后序遍历：";
		bt.postOrder();
		cout << "二叉树的高度为: " << bt.BTreeHeight() << endl;
		cout << "二叉树的叶子结点数为: " << bt.BTreeLeaves() << endl;
		cout << "二叉树的结点数为： " << bt.BTreeSize() << endl;
		system("pause");
		system("cls");
	}
}
