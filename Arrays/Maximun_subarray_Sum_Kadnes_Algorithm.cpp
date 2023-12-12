#include<bits/stdc++.h>
using namespace std;

int maximum_subarray(int arr[], int n)
{
    int res=arr[0];
    int maxxending=arr[0];
    for(int i=1;i<n;i++)
    {
        maxxending=max(arr[i],maxxending+arr[i]);
        res=max(res,maxxending);
    } 

    return res;
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

   cout<<"Maximum Subarray sum is="<<maximum_subarray(arr,n);

    return 0;
}