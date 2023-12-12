#include<bits/stdc++.h>
using namespace std;


struct Node
{
    int freq;
    char data;
    Node *left;
    Node *right;

    Node(int f,char ch,Node *l=NULL,Node *r=NULL)
    {
        freq=f;
        data=ch;
        left=l;
        right=r;
    }
};

struct myCmp
{
    bool operator()(Node *p1,Node *p2)
    {
        return p1->freq>p2->freq;
    }
};

void printtree(Node *root, string str)
{
     if(root->data!='$')
     {
        cout<<root->data<<" "<<str<<endl;
        return;
     }
     
     printtree(root->left,str+'0');
     printtree(root->right,str+'1');
}

void Hauffmantree(char arr[], int freq[],int n)
{
    priority_queue<Node*,vector<Node*>,myCmp>pq;
    
    for(int i=0;i<n;i++)
    {
        Node *temp=new Node({freq[i],arr[i]});
        pq.push(temp);
    }

    while(pq.size()>1)
    {
        Node *h1=pq.top();pq.pop();
        Node *h2=pq.top();pq.pop();

        Node *n=new Node((h1->freq+h2->freq),'$',h1,h2);

        pq.push(n);
    }

    Node *root=pq.top();
    string str;
    printtree(root,str);
}


int main()
{
    int n;
    cout<<"Enter the size of array\n";
    cin>>n;

    int *freq=new int[n];
    char *arr=new char[n];

    cout<<"Enter the charactere and their Frequencies\n";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        cin>>freq[i];
    }

    Hauffmantree(arr, freq, n);

    return 0;
}


