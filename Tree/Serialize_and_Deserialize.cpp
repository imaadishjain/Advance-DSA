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

void Serialize(Node * root,vector<int>&ans)
{
    if(root==NULL)
    {
        ans.push_back(-1);
        return ;
    }
    ans.push_back(root->data);
    Serialize(root->left,ans);
    Serialize(root->right,ans);

}
int index=0;
Node * Deserialsize(vector<int>&ans)
{
    if(index==ans.size() || ans[index]==-1)
    {
        index++;
        
        return NULL;
    }
    Node* root=new Node(ans[index]);
    index++;
    root->left=Deserialsize(ans);
    root->right=Deserialsize(ans);

    return root;
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
    Node *temp=new Node(10);
    temp->left=new Node(20);
    temp->right=new Node(30);
      temp->left->left=new Node(40);
    temp->left->right=new Node(50);
    temp->right->right=new Node(60);

    vector<int>ans;

    cout<<"Serialising\n";
    Serialize(temp,ans);

    for(auto it: ans)
    {
        cout<<it<<" ";
    }
  cout<<"\n";
    cout<<"Deserialising\n";
    Node *root= Deserialsize(ans);

    print(root);

    return 0;
}
