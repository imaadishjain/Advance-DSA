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
vector<vector<int>> levelorderline(Node * head)
{
    vector<vector<int>>ans;
   vector<int>vec;
   queue<Node*>q;
   q.push(head);
   q.push(NULL);
   Node *curr=head;
   while(q.size()>1)
   {
       Node *temp=q.front();
       q.pop();
       if(temp==NULL)
       {
           ans.push_back(vec);
           vec.clear();
           q.push(NULL);
       }
       else
       {
           vec.push_back(temp->data);
           if(temp->left!=NULL)
           {
               q.push(temp->left);
           }
           if(temp->right!=NULL)
           {
               q.push(temp->right);
           }
       }
   }
   ans.push_back(vec);
   return ans;
}
int main()
{
    Node *temp=new Node(10);
    temp->left=new Node(20);
    temp->left->left=new Node(40);
    temp->left->right=new Node(50);
      
      temp->right=new Node(30);
      temp->right->right=new Node(60);
      temp->right->right->left=new Node(70);
      temp->right->right->right=new Node(80);
 
   vector<vector<int>>ans=levelorderline(temp);

   for(int i=0;i<ans.size();i++)
   
   {
    for(int j=0;j<ans[i].size();j++)
    {
        cout<<ans[i][j]<<" ";
    }
    cout<<endl;
 
   }

   return 0;
}