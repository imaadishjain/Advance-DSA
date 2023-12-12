#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data=x;
        next=NULL;
    }
};

bool detectLoop(Node* head)
    {
         Node *slow=head;
         Node *fast=head;
         
         while(slow!=NULL && fast->next!=NULL && fast->next->next!=NULL)
         {
             slow=slow->next;
             fast=(fast->next)->next;
             if(slow==fast)
             {
                 return 1;
             }
         }
         
         return  0;
    }

int main()
{
    int n;
    cout<<"Enter the size of Linked List=";
    cin>>n;

    Node *head=NULL;
    Node *tail=NULL;
    cout<<"Enter the linkedlist\n";

    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        Node *temp=new Node(x);
        if(tail==NULL)
        {
            head=temp;
            tail=head;
        }
        else
        {
           tail->next=temp;
           tail=temp;
        }
    }
    int l;
    cout<<"Do you want loop=";
    cin>>l;
    if(l)
    tail->next=head->next->next;
    
    cout<<std::boolalpha;
    cout<<"Loop is Present="<<detectLoop(head)<<endl;

    return 0;
 
    
}