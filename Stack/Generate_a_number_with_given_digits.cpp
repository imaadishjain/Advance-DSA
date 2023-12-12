#include<bits/stdc++.h>
using namespace std;


void printfirst(string a, string b,int n)
{
    queue<string>q;
    
    q.push(a);
    q.push(b);
    
    for(int i=1;i<=n;i++)
    {
        string str=q.front();
        
        q.pop();
        cout<<str<<" ";
        
        q.push(str+a);
        q.push(str+b);
    }
}

int main()
{
    string a,b;
    int n;
    cout<<"Enter the two number\n";
    cin>>a;
    cin>>b;

    cout<<"Enter the number\n";
    cin>>n;

    printfirst(a,b,n);

    return 0;
    
}