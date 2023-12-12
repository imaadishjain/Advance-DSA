#include<bits/stdc++.h>
using namespace std;


bool check(int arr[], int n, int mid, int m)
{
    int req=1;
    int sum=0;

    for(int i=0;i<n;i++)
    {
        sum+=arr[i];

        if(sum>mid)
        {
            sum=arr[i];
            req++;
        }
    }

    return req<=m;
}

int minpages(int arr[], int n, int m)
{
     int low=arr[0];
     int high=0;
    
    for(int i=0;i<n;i++)
    {
       high+=arr[i];
       low=max(low,arr[i]);
    }

    int res;
    while(low<=high)
    {
        int mid=low+(high-low)/2;

        if(check(arr,n,mid,m))
        {
            res=mid;
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }

    return res;
}

int main()
{
    int n;
    cout<<"Enter the size of array=";
    cin>>n;
    int *arr=new int[n];
    cout<<"Enter the pages of books\n";

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int x;
    cout<<"Enter the number of students=";
    cin>>x;

    cout<<"Minimum page allocated to student="<<minpages(arr,n,x)<<endl;

    return 0;

}