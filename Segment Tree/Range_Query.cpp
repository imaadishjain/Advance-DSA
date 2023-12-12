#include<bits/stdc++.h>
using namespace std;

int segment(int ss,int se,int si,int arr[],int tree[])
{
    if(ss==se)
    {
        tree[si]=arr[ss];
        return tree[si];
    }
    int mid=(ss+se)/2;
    return tree[si]=segment(ss,mid,2*si+1,arr,tree)+segment(mid+1,se,2*si+2,arr,tree);
}

int getsum(int qs,int qe,int ss,int se,int si,int tree[])
{
    if(qs>se || ss>qe)
    {
       return 0;
    }
    if(qs<=ss && qe>=se)
    {
        return tree[si];
    }
    int mid=(ss+se)/2;
    return getsum(qs,qe,ss,mid,2*si+1,tree)+getsum(qs,qe,mid+1,se,2*si+2,tree);
}




int main()
{
    int arr[6]={10,20,30,40,50,60};
    int n=6;
    
    int tree[4*n];

    segment(0,n-1,0,arr,tree);
    
    cout<<getsum(0,2,0,n-1,0,tree)<<endl;
    cout<<getsum(1,3,0,n-1,0,tree)<<endl;
    cout<<getsum(0,3,0,n-1,0,tree)<<endl;
    return 0;

}
