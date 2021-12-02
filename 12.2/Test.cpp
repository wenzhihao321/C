#include<iostream>
#include"Queue.h"
typedef char BTDataType;
typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
	BTDataType data;
}BTNode;

BTNode* CreateTreeNode(BTDataType x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	node->data = x;
	node->left = NULL;
	node->right = NULL;
	return node;
}
//前序遍历
void PrevOrder(BTNode*root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%c ", root->data);
	PrevOrder(root->left);
	PrevOrder(root->right);
}
//中序遍历
void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	InOrder(root->left);
	printf("%c ", root->data);
	InOrder(root->right);
}
//后序遍历
void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%c ", root->data);

}
//层序遍历
void TreeLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
	{
		QueuePush(&q, root);
	}
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		printf("%c ", front->data);
		if (front->left)
		{
			QueuePush(&q, front->left);
		}
		if (front->right)
		{
			QueuePush(&q, front->right);
		}
	}
}
//计算树的结点
int TreeSize(BTNode* root)
{
	return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right)+1;
}
//找叶子结点
int TreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->left == NULL && root->right == NULL)
	{
		return 	1;
	}
	return TreeLeafSize(root->left)+TreeLeafSize(root->right);
}
//k>0
int TreeKLeveSize(BTNode* root, int k)
{
	if (root == nullptr)
	{
		return 0;
	}

	if (k == 1)
	{
		return 1;
	}
	int leftSize = TreeKLeveSize(root->left, k - 1);
	int rightSize = TreeKLeveSize(root->right, k - 1);
	return leftSize + rightSize;
}
//查找树里面值为x的那个结点
BTNode* TreeFind(BTNode* root, BTDataType x)
{
	if (root == nullptr)
	{
		return nullptr;
	}
	if (root->data == x)
	{
		return root;
	}
	BTNode *left = TreeFind(root->left,x);
	if (left)
	{
		return left;
	}
	BTNode *right = TreeFind(root->right,x);
	if (right)
	{
		return right;
	}
	return nullptr;
	//return left == nullptr ? right : left;
}
//二叉树销毁
//一般，如果选择一级指针，存在野指针问题，调用BinaryTreeDestroy的人，把指针置空
//这样可以保持接口一致性
void BinaryTreeDestroy(BTNode*root)
{
	if (root == NULL)
	{
		return;
	}
	BinaryTreeDestroy(root->left);
	BinaryTreeDestroy(root->right);
	free(root);
	root = nullptr;
}
//判断二叉树是否为完全二叉树
int BinaryTreeComplete(BTNode* root)
{

}
int main()
{
	BTNode* A = CreateTreeNode('A');
	BTNode* B = CreateTreeNode('B');
	BTNode* C = CreateTreeNode('C');
	BTNode* D = CreateTreeNode('D');
	BTNode* E = CreateTreeNode('E');
	BTNode* F = CreateTreeNode('F');

	A->left = B;
	A->right = C;
	B->left = D;
	C->left = E;
	C->right = F;
	PrevOrder(A);
	printf("\n");
	InOrder(A);
	printf("\n");
	PostOrder(A);
	printf("\n");
	printf("树有%d个结点\n", TreeSize(A));
	printf("树有%d个叶子结点\n", TreeLeafSize(A));
	printf("%d\n", TreeKLeveSize(A, 4));
	printf("%c\n",TreeFind(A, 'F')->data);

	TreeLevelOrder(A);
	BinaryTreeDestroy(A);
	A==nullptr;
	return 0;
}