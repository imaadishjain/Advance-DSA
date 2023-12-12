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

void verticalOrder(Node *root)
    {
        map<int,vector<int>>mpp;
        queue<pair<int,Node*>>q;
        
        q.push({0,root});
        while(!q.empty())
        {
            auto p=q.front();
            q.pop();
            Node *temp=p.second;
            int hd=p.first;
            
            mpp[hd].push_back(temp->data);
            
            if(temp->left!=NULL)
            {
                q.push({hd-1,temp->left});
            }
            if(temp->right!=NULL)
            {
                q.push({hd+1,temp->right});
            }
        }
        
        vector<int>ans;
        
        for(auto it:mpp)
        {
            for(auto x:it.second)
            {
                cout<<x<<" ";
            }
            cout<<endl;
        }
    }

int main()
{
    Node *root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->right->left=new Node(40);
    root->right->right=new Node(50);
    
    cout<<"Vertical Traversal\n";
    

     verticalOrder(root);

    return 0;

}