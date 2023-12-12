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

int countnode(Node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    Node * curr=root;
    int lt=0;
    int rt=0;
    while(curr!=NULL)
    {
          lt++;
       curr=curr->left;
    }
    curr=root;
    while(curr!=NULL)
    {
        rt++;
        curr=curr->right;
    }
    if(lt==rt)
    {
        int count=pow(2,lt)-1;
        return count;
    }
    
    return 1+countnode(root->left)+countnode(root->right);
}


int main()
{
    Node *temp=new Node(10);
    temp->left=new Node(20);
    temp->right=new Node(30);
     temp->left->left=new  Node(40);
     temp->left->right=new Node(50);
    

     countnode(temp);
    cout<<"Total number of nodes in complete Binary tree is="<<countnode(temp);

    return 0;
}