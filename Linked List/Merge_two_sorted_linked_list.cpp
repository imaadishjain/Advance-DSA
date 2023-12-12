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


Node* sortedMerge(Node* head1, Node* head2)  
{  
     if(head1==NULL) return head2;  
     
     if(head2==NULL) return head1;
     
     
     Node *a=NULL,*b=NULL,*tail=NULL;
     
      a=head1->data<=head2->data?head1:head2;
     
      b=head1->data>=head2->data?head1:head2;
     
     tail=a;
     Node *ans=a;
     a=a->next;
     while(a!=NULL && b!=NULL)
     {
         if(a->data<=b->data)
         {
             tail->next=a;
             tail=a;
             a=a->next;
         }
         else
         {
             tail->next=b;
             tail=b;
             b=b->next;
         }
     }
     
     if(a!=NULL)
     {
         tail->next=a;
     }
     else
     {
         tail->next=b;
     }
      return ans;
}  

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
    return head;
}


int main()
{
    Node *head1=createE();
    Node *head2=createE();

    Node *ans=sortedMerge(head1,head2);

    printlist(ans);
    return 0;


}