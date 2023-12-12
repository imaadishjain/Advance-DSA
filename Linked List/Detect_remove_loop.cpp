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
void printlist(Node *head)
{
    Node *curr=head;

    while(curr!=NULL)
    {
        cout<<curr->data<<"->";
        curr=curr->next;
    }

    cout<<"NULL"<<endl;
}



void removeLoop(Node* head)
    {
       Node *slow=head;
       Node *fast=head;
       Node *prev=NULL;
       while(slow!=NULL && fast->next!=NULL && fast->next->next!=NULL)
       {
           slow=slow->next;
           if(fast->next->next==slow)
           {
               prev=fast->next;
           }
           fast=fast->next->next;
           
           if(slow==fast)
           {
               break;
           }
       }
       
       if(slow!=fast)
       {
           return ;
       }
       if(slow==head)
       {
           prev->next=NULL;
           return ;
       }
       slow=head;
       
       while(slow->next!=fast->next)
       {
           slow=slow->next;
           fast=fast->next;
       }
       
       fast->next=NULL;
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
    
    removeLoop(head);
    cout<<"New Linkedlist with remove loop\n";
    printlist(head);

    return 0;
 
    
}