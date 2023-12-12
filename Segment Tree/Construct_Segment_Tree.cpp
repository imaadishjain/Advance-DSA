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

int main()
{
    int arr[6]={10,20,30,40,50,60};
    int n=6;
    
    int tree[4*n];

    segment(0,n-1,0,arr,tree);

    for(auto it: tree)
    {
        cout<<it<<" ";
    }

    return 0;

}
