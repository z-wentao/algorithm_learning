#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXNODE 100
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};
struct TreeNode *createTreeNode(int val)
{
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (node != NULL)
    {
        node->val = val;
        node->left = NULL;
        node->right = NULL;
        return node;
    }
    return NULL;
}
struct TreeNode * createBiTree(int *BiNum, int size)
{
    struct TreeNode * Queue[MAXNODE] = {0};
    int front = -1;
    int rear = 0;
    struct TreeNode *node;
    struct TreeNode *leftNode;
    struct TreeNode *rightNode;
    int i = 0;

    if (BiNum != NULL)
        node = createTreeNode(BiNum[i]);

    if (node)
        Queue[rear] = node;

    i++;
    while(i < size && rear != front)
    {
        leftNode = createTreeNode(BiNum[i]);
        front++;
        Queue[front]->left = leftNode;
        if (leftNode)
        {
            rear++;
            Queue[rear] = leftNode;
        }

        i++;
        if (i < size)
        {
            rightNode = createTreeNode(BiNum[i]);
            Queue[front]->right = rightNode;
            if (rightNode)
            {
                rear++;
                Queue[rear] = rightNode;
            }
            i++;
         }
    }
    return node;
}
bool isValidBST(struct TreeNode* root){
    struct TreeNode* leftnode;
    struct TreeNode* rightnode;

    if (root == NULL)
        return true;

    leftnode = root->left;
    while(leftnode)
    {
        if (root->val <= leftnode->val)
            return false;

        leftnode = leftnode->right;
    }

    rightnode = root->right;
    while(rightnode)
    {
        if (root->val >= rightnode->val)
            return false;

        rightnode = rightnode->left;
    }

    if (isValidBST(root->left) && isValidBST(root->right))
        return true;

    return false;
}
int main()
{
	//层次顺序遍历二叉树 
    int num1[8] = {5,3,7,2,4,6,8,1};
    struct TreeNode *node1 = createBiTree(num1, 8);
    for (int i = 0; i < 8; i++) printf("%d,", num1[i]);
    if (isValidBST(node1)) printf("是合法的二叉查找树！\n");
    else printf("不是合法的二叉查找树！\n");
    int num2[8] = {5,6,7,2,4,6,8,1};
    struct TreeNode *node2 = createBiTree(num2, 8);
    for (int i = 0; i < 8; i++) printf("%d,", num2[i]);
    if (isValidBST(node2)) printf("是合法的二叉查找树！");
    else printf("不是合法的二叉查找树！");
}
