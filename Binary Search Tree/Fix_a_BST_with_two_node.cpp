#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

   Node(int x)
   {
    data=x;
    left=NULL;
    right=NULL;
   }
};

Node *first=NULL;
Node *second=NULL;
Node *prevv=NULL;

void inorder(Node *root)
    {
        if(root==NULL)
        {
            return ;
        }
        inorder(root->left);
        if(prevv!=NULL && prevv->data>root->data)
        {
            if(first==NULL)
            {
                first=prevv;
            }
            second=root;
        }
        prevv=root;
    
        inorder(root->right);  
 }
  void print(Node *root)
  {
    if(root==NULL)
    {
       return ;
    }

    print(root->left);
    cout<<root->data<<" ";
    print(root->right);
  }
 int main()
 {
    Node* root=new Node(20);
    root->left=new Node(60);
    root->left->left=new Node(4);
    root->left->right=new Node(10);

    root->right=new Node(80);
    root->right->left-new Node(8);
    root->right->right=new Node(100);

    cout<<"Current Bst\n";
    print(root);


   inorder(root);
   
   swap(first->data,second->data);
   cout<<"\n";
   cout<<"New BST\n";
   print(root);
   return 0;
 }
