#include<bits/stdc++.h>
using namespace std;

void update(int i, int n,int diff,int tree[])
{
    i=i+1;
    while(i<=n)
    {
        tree[i]+=diff;
        i=i+(i&(-i));
    }
}

int main()
{
    int arr[]={10,20,30,40,50,60,70,80,90,100,110};
    int n=11;
    int tree[12]={0};
    
    for(int i=0;i<n;i++)
    {
        update(i,n,arr[i],tree);
    }

    for(auto it: tree)
    {
        cout<<it<<" ";
    }
   
   return 0;
}