#include<bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    Node * left;
    Node * right;

    Node(int x)
    {
        data=x;
        left=NULL;
        right=NULL;
    }
};

int maxlevel=0;
void lefty(Node * root,int level)
{
    if(root==NULL)
    {
        return;
    }
    if(maxlevel<level)
    {
     cout<<root->data<<" ";
    maxlevel=level;
    }
    
    lefty(root->left,level+1);
    lefty(root->right,level+1);
}

int main()
{
    Node *temp=new Node(30);
    temp->right=new Node(50);
    temp->right->left=new Node(60);

    temp->right->left->right=new Node(10);

    cout<<"Left View of tree\n";

  lefty(temp,1);
  return 0;
  
}