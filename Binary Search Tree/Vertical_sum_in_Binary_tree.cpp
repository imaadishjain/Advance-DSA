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


void vertical_sum(Node *root,int hd,map<int,int>&mpp)
{
    if(root==NULL)
    {
        return ;
    }
    vertical_sum(root->left,hd-1,mpp);
    mpp[hd]+=root->data;
    vertical_sum(root->right,hd+1,mpp);
}


int main()
{
  Node *root=new Node(10);
  root->left=new Node(20);
  root->left->left=new Node(5);
  root->left->right=new Node(15);
  root->right=new Node(30);

  
  map<int,int>mpp;

  vertical_sum(root,0,mpp);

  for(auto it:mpp)
  {
    cout<<it.second<<" ";
  }
  return 0;
}
