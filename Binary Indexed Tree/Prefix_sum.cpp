#include<bits/stdc++.h>
using namespace std;

int getsum(int i,int tree[])
{
    int sum=0;
    i=i+1;
    
    while(i>0)
    {
        sum+=tree[i];
        i=i-(i&(-i));
    }

    return sum;
}



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

   cout<<getsum(4,tree)<<endl; 
   
   // Sum from 2-5
   cout<<getsum(5,tree)-getsum(1,tree);
   return 0;
}