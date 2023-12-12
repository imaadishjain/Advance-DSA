#include<bits/stdc++.h>
using namespace std;


void leader(int arr[], int n)
{
    int res=arr[n-1];
    
    cout<<res<<" ";
    for(int i=n-2;i>=0;i--)
    {
       if(arr[i]>res)
       {
        cout<<arr[i]<<" ";
        res=arr[i];
       }
    }
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

    cout<<"Leaders are\n";

    leader(arr,n);

    return 0;
}