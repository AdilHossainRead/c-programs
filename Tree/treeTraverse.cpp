#include<stdio.h>
#include<stdlib.h>
struct TreeNode
{
    int data;
    TreeNode* right;
    TreeNode* left;
};
TreeNode* creatNode(int data)
{
    TreeNode* temp=(TreeNode*)malloc(sizeof(TreeNode));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
void preorder(TreeNode* root)
{
    if(root==NULL)
        return;
    printf("%d",root->data);
    preorder(root->left);
    preorder(root->right);
}
void inorder(TreeNode* root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    printf("%d",root->data);
    inorder(root->right);

}
void postorder(TreeNode* root)
{
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d",root->data);
}
int height(TreeNode*root)
{
    if(root==NULL)
    {
        return 0;
    }
    else if(root->left==NULL && root->right==NULL)
    {
        return 0;
    }
    else
    {
       if(root->left!=NULL && root->right!=NULL)
       {
           int left_site_height=height(left_site_height);
           int left_side_height = height(root->left);

           int right_site_height=height(right_site_height);
           if(left_site_height>right_site_height)
           {
               return left_site_height+1;
           }
           else
           {
               return right_site_height+1;
           }
       }
       else if(root->left!=NULL)
       {
           int left_site_height=height(left_site_height);
           return left_site_height=1;
       }
       else
       {
           int right_site_height=height(right_site_height);
           return right_site_height+1;
       }
    }
}
int find_value(TreeNode* root,int value)
{
    if(root==NULL)
        return 0;
    else if(root->data==value)
        return 1;
    else
    {
        int left_answer=find_value(root->left);
        int right_answer=find_value(root->right);
        return left_answer || right_answer;
    }
}
int count_node(TreeNode* root)
{
    if(root==NULL)
        return 0;
    else
    {
        int left_answer=count_node(root->left);
        int right_answer=count_node(root->right);
        return left_answer+right_answer+1;
    }
}
int count_lavel(TreeNode* root)
{
    if(root==NULL)
        return 0;
    else if(root->left==NULL && root->right==NULL)
        return 1;
    else
    {
         int left_answer=count_node(root->left);
        int right_answer=count_node(root->right);
        return left_answer+right_answer;
    }
    }
}
int main()
{
    TreeNode* root=creatNode(44);
    root->left=creatNode(55);
    root->right=creatNode(33);

    root->left->left=creatNode(23);
    root->left->right=creatNode(23);

    root->right->left=creatNode(13);
    root->right->right=creatNode(43);

}
