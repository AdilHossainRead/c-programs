#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct TreeNode
{
    int data;
    TreeNode* left;
    TreeNode* right;
};
TreeNode* creatNode(int data)
{
    TreeNode* temp=(TreeNode*)malloc(sizeof(TreeNode));
    temp->data=data;
    temp->right=NULL;
    temp->left=NULL;
    return temp;
}
TreeNode* insertion(TreeNode* root,key)
{
    if(root==NULL)
    {
        root=creatNode(key);
        return root;
    }
    else
    {
        if(key>root->data)
        {
            root->right=insertion(root->right,key);
        }
        else if(key<root->data)
        {
            root->left=insertion(root->left,key);
        }
        return root;
    }
}

void pre_order(TreeNode* root)
{

}
int main()
{
    TreeNode* root=NULL;
    root=insertion(root,15);
    root=insertion(root,25);
    root=insertion(root,10);
    root=insertion(root,18);
    root=insertion(root,11);
    root=insertion(root,33);
    root=insertion(root,43);
    root=insertion(root,19);
    root=insertion(root,5);
}
