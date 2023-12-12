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
    
    Node *eo=NULL;
    Node *ee=NULL;
    Node *po=NULL;
    Node *pe=NULL;

   for(Node *curr=head; curr!=NULL ;curr=curr->next)
   {
    int d=curr->data;
    if(d%2==0)
    {
        if(pe==NULL)
        {
            ee=curr;
            pe=ee;
        }
        else
        {
            pe->next=curr;
            pe=curr;
        }
    }
    else
    {
        if(po==NULL)
        {
            eo=curr;
            po=eo;
        }
        else
        {
            po->next=curr;
            po=curr;
        }
    }
   }
   if(po==NULL || pe==NULL)
   {
    printlist(head);
    return 0;
   }
   pe->next=eo;
   po->next=NULL; 

   printlist(ee);
   printlist(eo);

   return 0;
}