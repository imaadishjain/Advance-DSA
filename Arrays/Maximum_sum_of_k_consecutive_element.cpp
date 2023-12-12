#include<bits/stdc++.h>
using namespace std;


int maxconse(int arr[], int n, int k)
{
    int res=0;
    for(int i=0;i<k;i++)
    {
        res+=arr[i];
    }
    int ans=res;
    for(int i=k;i<n;i++)
    {
      res=res+arr[i]-arr[i-k];
      ans=max(res,ans);
    }

    return ans;
}


int main()
{
    int n;
    cout<<"Enter the size of array=";
    cin>>n;

    int *arr=new int[n];
    cout<<"Enter the elements\n";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int k;
    cout<<"Enter the value of k=";
    cin>>k;

    cout<<"Maximum consecutive array of size k with max sum="<<maxconse(arr,n,k);

    return 0;
}