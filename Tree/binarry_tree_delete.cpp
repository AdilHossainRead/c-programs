#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct NodeTree
{
    int data;
    NodeTree* left;
    NodeTree* right;
};
NodeTree* creat_Node(int data)
{
    NodeTree* temp=(NodeTree*)malloc(sizeof(NodeTree));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
NodeTree* insert_value(NodeTree* root,int key)
{
    if(root==NULL)
    {
        root=creat_Node(key);
        return root;
    }
    else
    {
        if(root->data>key)
        {
            root->left=insert_value(root->left,key);
        }
        else if(root->data<key)
        {
            root->right=insert_value(root->right,key);
        }
    }
}
NodeTree* find_maximum(NodeTree root)
{
    if(root==NULL)
    {
        return NULL;
    }
    else
    {
        NodeTree* temp=root;
        while(temp->right!=NULL)
        {
            temp=temp->right;
        }return temp;
    }
}
NodeTree* find_maximum(NodeTree root)
{
    if(root==NULL)
        return NULL;
    else
        NodeTree* temp=root;
    while(temp->left!=NULL)
    {
        temp=temp->left;
    }
    return temp;
}
bool search_BST(NodeTree* root, key)
{
    if(root==NULL)
        return false;
    else
    {
        if(root==key)
        {
            return true;
        }
        else if(key<root->data)
        {
            bool answer=search_BST(root->left,key);
            return answer;
        }
        else if(key>root->data)
        {
            bool answer=search_BST(root->right)
            return answer;
        }
    }
}
void inorder(NodeTree* root)
{
    if(root==NULL)
        return;
    else
        inorder(root->left);
    printf("%d" root->data);
    inorder(root->right);
}
NodeTree* delete_node(NodeTree* root, int key) {
    if (root == NULL)
        return NULL;
    if (key < root->data)
        root->left = delete_node(root->left, key);
    else if (key > root->data)
        root->right = delete_node(root->right, key);
    else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        else if (root->left == NULL) {
            NodeTree* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            NodeTree* temp = root->left;
            free(root);
            return temp;
        }
        else {
            NodeTree* temp = find_minimum(root->right);
            root->data = temp->data;
            root->right = delete_node(root->right, temp->data);
        }
    }
    return root;
}

int main()
{
    NodeTree* root=NULL;
    root=insert_value(root,19);
    root=insert_value(root,13);
    root=insert_value(root,20);
    root=insert_value(root,17);
    root=insert_value(root,33);
    root=insert_value(root,22);
    root=insert_value(root,23);
    root=insert_value(root,20);
    root=insert_value(root,30);
    printf("find maximum value: %d\n",find_maximum(root));
    printf("find minimum value: %d\n"find_minimum(root));

}
