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


bool check(Node *root,int min,int max)
 {
         if(root==NULL)
          {
            return true;
           }
    
        if(root->data<=min || root->data>=max)
        {
            return false;
        }
        return check(root->left,min,root->data) && check(root->right,root->data,max);
    }

int main()
{
   Node *root=new Node(10);
    root->left=new Node(8);
    root->right=new Node(20);
    root->right->left=new Node(13);
    root->right->right=new Node(24);
    

    cout<<std::boolalpha;
    cout<<"Check for BST="<<check(root,INT_MIN,INT_MAX);

    return 0;
    
}