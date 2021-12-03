#include<iostream>

typedef int TNDataType;
typedef struct TreeNode
{
    TNDataType val;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

TreeNode* CreateTreeNode(TNDataType x)
{
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = x;
    node->left = NULL;
    node->right = NULL;
    return node;
}
bool isUnivalTree(TreeNode* root) {
    if (root == NULL)
    {
        return true;
    }
    if (root->left && root->val != root->left->val)
    {
        return false;
    }
    if (root->right && root->val != root->right->val)
    {
        return false;
    }
    return isUnivalTree(root->left) && isUnivalTree(root->right);
}
void BinaryTreeDestroy(TreeNode* root)
{
    if (root == NULL)
    {
        return;
    }
    BinaryTreeDestroy(root->left);
    BinaryTreeDestroy(root->right);
    free(root);
    root = NULL;
}
int main()
{
    //TreeNode* A = CreateTreeNode(1);
    //TreeNode* B = CreateTreeNode(1);
    //TreeNode* C = CreateTreeNode(1);
    //TreeNode* D = CreateTreeNode(1);
    //TreeNode* E = CreateTreeNode(1);
    //TreeNode* F = CreateTreeNode(1);

    //A->left = B;
    //A->right = C;
    //B->left = D;
    //B->right = E;
    //C->right = F;

    //printf("isUnivalTree:%d ",isUnivalTree(A));
    //BinaryTreeDestroy(A);

    TreeNode* A = CreateTreeNode(2);
    TreeNode* B = CreateTreeNode(2);
    TreeNode* C = CreateTreeNode(2);
    TreeNode* D = CreateTreeNode(5);
    TreeNode* E = CreateTreeNode(2);

    A->left = B;
    A->right = C;
    B->left = D;
    B->right = E;
    printf("isUnivalTree:%d ", isUnivalTree(A));
    BinaryTreeDestroy(A);

	return 0;
}