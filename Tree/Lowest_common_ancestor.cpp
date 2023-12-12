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

 bool path(Node* root,int n,vector<Node*>&ans)
    {
        if(root==NULL)
        {
            return false;
        }
        ans.push_back(root);
        if(root->data==n)
        {
            return true;
        }
        
        if(path(root->left,n, ans) || path(root->right,n,ans))
        {
            return true;
        }
        ans.pop_back();
        return false;
    }
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       vector<Node*>p1;
       vector<Node*>p2;
       if(path(root,n1,p1)==false || path(root,n2,p2)==false)
       {
           return NULL;
       }
       unordered_set<Node*>st(p2.begin(),p2.end());
       Node *ans=NULL;
       for(int i=0;i<p1.size();i++)
       {
           if(st.find(p1[i])!=st.end())
           {
               ans=p1[i];
           }
       }
       
       return  ans;
    }

int main()
{
    Node *temp=new Node(10);
    temp->left=new Node(20);
    temp->right=new Node(30);
    
      temp->right->right=new Node(50);
      temp->right->right->left=new Node(70);
      temp->right->right->right=new Node(80);
      temp->right->left=new Node(40);
      temp->right->left->left=new Node(60);
      

      int n1,n2;

      cout<<"Enter the value of two nodes=";
      cin>>n1;
      cin>>n2;

      Node *ans=lca(temp,n1,n2);
      cout<<"Lowest Common node is=";
        if(ans!=NULL)
        {
        cout<<ans->data;
        }
        else
        
        {
            cout<<ans;
        }

      return 0;
}