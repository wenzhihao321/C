#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode
{
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
}TNode;
TNode* CreateTreeNode(char* str, int* i)
{
    //��#�����ؿ�
    if (str[*i] == '#')
    {
        ++(*i);
        return NULL;
    }
    //����#��������
    TNode* root = (TNode*)malloc(sizeof(TNode));
    root->data = str[*i];
    ++(*i);
    //�ݹ鹹��������
    root->left = CreateTreeNode(str, i);
    //�ݹ鹹��������
    root->right = CreateTreeNode(str, i);
    return root;
}
void InOrder(TNode* root)
{
    if (root == NULL)
    {
        return;
    }
    InOrder(root->left);
    printf("%c ", root->data);
    InOrder(root->right);
}
int main()
{
    char str[100];
    printf("�����룺");
    scanf("%s", str);
    int i = 0;
    TNode* root = CreateTreeNode(str, &i);
    InOrder(root);
    printf("\n");
    return 0;
}