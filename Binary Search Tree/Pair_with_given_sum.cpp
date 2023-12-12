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


bool pair_sum(Node *root, int x, unordered_set<int>&st)
{
    if(root==NULL)
    {
        return false;
    }
    if(st.find(x-root->data)!=st.end())
    {
        return true;
    }
    st.insert(root->data);
    
    return pair_sum(root->left,x,st) || pair_sum(root->right,x,st);
}

int main()
{
    Node *root=new Node(10);
    root->left=new Node(8);
    root->left->left=new Node(4);

    root->left->right=new Node(9);
    root->right=new Node(20);
    root->right->left=new Node(11);
    root->right->right=new Node(30);
    root->right->right->left=new Node(25);

    int sum=33;
    unordered_set<int>st;
    cout<<std::boolalpha;

    cout<<"Sum is present="<<pair_sum(root,sum,st);
    return 0;
}