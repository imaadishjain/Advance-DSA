#include<bits/stdc++.h>
using namespace std;

struct Node
{
    char data;
    Node *next;

    Node(int x)
    {
        data=x;
        next=NULL;
    }
};
Node *createE()
{
    int n;
    cout<<"Enter the size of Linked List=";
    cin>>n;

    Node *head=NULL;
    Node *tail=NULL;
    cout<<"Enter the linkedlist\n";

    for(int i=1;i<=n;i++)
    {
        char x;
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
    return head;
}
Node *reverse(Node *head)
    {
        Node *curr=head;
        Node *prev=NULL;
        while(curr!=NULL)
        {
           Node *next=curr->next;
           curr->next=prev;
           prev=curr;
           curr=next;
        }
        return prev;
    }
    bool isPalindrome(Node *head)
    {
        if(head==NULL || head->next==NULL)
        {
            return 1;
        }
        
        Node *slow=head;
        Node *fast=head;
        
        
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        
        Node *head2=reverse(slow->next);
        slow=head;
        while(head2!=NULL)
        {
            if(slow->data!=head2->data)
            {
                return 0;
            }
            slow=slow->next;
            head2=head2->next;
        }
        
        return 1;
    }

int main()
{
    Node *head=createE();
    cout<<std::boolalpha;
    cout<<"Linked List is pallindrome="<<isPalindrome(head);
}