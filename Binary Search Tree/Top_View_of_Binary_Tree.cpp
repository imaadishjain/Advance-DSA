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

vector<int> topView(Node *root)
    {
        map<int,int>mpp;
        queue<pair<int,Node*>>q;
        
        q.push({0,root});
        while(!q.empty())
        {
            auto p=q.front();
            q.pop();
            Node *temp=p.second;
            int hd=p.first;
            if(mpp.find(hd)==mpp.end())
            {
            mpp[hd]=temp->data;
            }
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
            ans.push_back(it.second);
        }
        return ans;
    }

int main()
{
    Node *root=new Node(10);
    root->left=new Node(20);
    root->left->left=new Node(30);
    root->left->right=new Node(40);

    root->right=new Node(50);
    root->right->left=new Node(60);
    root->right->right=new Node(70);

    vector<int>ans;

    cout<<"Top view of tree\n";
    ans=topView(root);

    for(auto x: ans)
    {
        cout<<x<<"  ";
    }

    return 0;
}