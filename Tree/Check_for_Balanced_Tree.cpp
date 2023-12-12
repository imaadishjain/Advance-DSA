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

bool isBalanced(Node * root)
{
    if(root==NULL)
    {
        return 0;
    }

    int lt=isBalanced(root->left);
    if(lt==-1)
    {
        return -1;
    }
    int rt=isBalanced(root->right);
    if(rt==-1)
    {
        return -1;
    }

    if(abs(lt-rt)>1)
    {
        return -1;
    }

    return max(lt,rt)+1;
}

int main()
{
    Node *temp=new Node(18);
    temp->left=new Node(4);

      
      temp->right=new Node(20);
      temp->right->right=new Node(70);
      temp->right->left=new Node(13);
     
     cout<<std::boolalpha;
      cout<<"Is tree is Balanced="<<isBalanced(temp);
      return 0;
}