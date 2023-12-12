#include<bits/stdc++.h>
using namespace std;


void reverse(queue<int>&q)
{
    if(q.empty()==true)
    {
        return;
    }
    int x=q.front();
    q.pop();
    reverse(q);
    q.push(x);
}

void print(queue<int>q)
{
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
}

int main()
{
    queue<int>q;
    int n;
    cout<<"Enter the total number of element=";
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        q.push(x);
    }

    cout<<"Queue\n";
    print(q);

    cout<<"Reversing the queue\n";
    reverse(q);

    print(q);
    

    return 0;
}