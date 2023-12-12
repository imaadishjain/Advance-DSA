#include<bits/stdc++.h>
using namespace std;


int  maximumdifference(int arr[], int n)
{
    int minn=arr[0];
    int ans=INT_MIN;
    for(int i=1;i<n;i++)
    {
      ans=max(ans,arr[i]-minn);
      minn=min(minn,arr[i]);
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
    
    cout<<"Maximum Difference between the element such that j>i="<<maximumdifference(arr,n);
    return 0;
}