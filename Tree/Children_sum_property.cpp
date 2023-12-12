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

 bool check(Node *root)
    {
        if(root==NULL)
        {
            return true;
        }
        if(root->left==NULL && root->right==NULL)
        {
         return true;
        }
        int sum=0;
        if(root->left!=NULL)
        {
            sum+=root->left->data;
        }
        if(root->right!=NULL)
        {
            sum+=root->right->data;
        }
        
        return sum==root->data && check(root->left) && check(root->right);
    }

int main()
{
    Node *temp=new Node(20);
    temp->left=new Node(8);
    temp->left->left=new Node(3);
    temp->left->right=new Node(5);
    temp->right=new Node(12);

    cout<<std::boolalpha;
    
     cout<<"Does tree follow child sum property="<<check(temp);

     return 0;
}