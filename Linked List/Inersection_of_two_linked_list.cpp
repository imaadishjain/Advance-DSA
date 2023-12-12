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

int intersectPoint(Node* head1, Node* head2)
{
    int l1=0;
    int l2=0;
    
    for(Node *curr=head1;curr!=NULL;curr=curr->next)
    {
        l1++;
    }
    for(Node *curr=head2;curr!=NULL;curr=curr->next)
    {
        l2++;
    }
    
    int c=abs(l1-l2);
    
    Node *curr=l1>=l2?head1:head2;
    Node *temp=l1<=l2?head1:head2;
    
    for(int i=1;i<=c;i++)
    {
        curr=curr->next;
    }

    
    while(curr!=NULL && temp!=NULL)
    {
        curr=curr->next;
        temp=temp->next;
        
        if(curr==temp)
        {
            return curr->data;
        }
    }
    
    return -1;
}


int main(){

    int n;
    cout<<"Enter the size of Linked List=";
    cin>>n;

    Node *head1=NULL;
    Node *tail=NULL;
    cout<<"Enter the linkedlist\n";

    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        Node *temp=new Node(x);
        if(tail==NULL)
        {
            head1=temp;
            tail=head1;
        }
        else
        {
           tail->next=temp;
           tail=temp;
        }
    }

    Node *head2=new Node(9);

    head2->next=head1->next->next->next;


    cout<<"Intersection node data="<<intersectPoint(head1,head2);


    return 0;
 
}