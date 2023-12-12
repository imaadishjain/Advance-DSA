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
int index=0;
Node * construct(vector<int>in,vector<int>pre,int is, int ie)
{
  if(is>ie)
  {
    return NULL;
  }
  int p=pre[index];
  Node *temp=new Node(p);
  index++;
  int f;
  for(int i=is;i<=ie;i++)
  {
    if(in[i]==p)
    {
       f=i;
       break;
    }
  }

  temp->left=construct(in,pre,is,f-1);
  temp->right=construct(in,pre,f+1,ie);

  return temp;
}
void print(Node *root)
{
    if(root==NULL)
    {
        return ;
    }
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}
int main()
{
   vector<int>in{20,10,40,30,50};
   vector<int>pre{10,20,30,40,50};

   Node *root=construct(in,pre,0,4);

 print(root);

 return 0;
}