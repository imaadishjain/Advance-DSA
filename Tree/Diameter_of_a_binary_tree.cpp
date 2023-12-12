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

int diameter(Node * root,int &res)
{
    if(root==NULL)
    {
        return 0;
    }

    int lt=diameter(root->left,res);
    int rt=diameter(root->right,res);
    res=max(res,lt+rt+1);
    return max(lt,rt)+1;
}

int main()
{
     Node *temp=new Node(10);
    temp->left=new Node(20);
    temp->right=new Node(30);
      temp->left->left=new Node(50);
    temp->left->right=new Node(40);
    temp->left->right->right=new Node(60);
     int res=0;

     diameter(temp,res);
    cout<<"Diameter of a tree is="<<res;
    return 0;
}